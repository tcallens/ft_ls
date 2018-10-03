/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcallens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 02:00:32 by tcallens          #+#    #+#             */
/*   Updated: 2018/10/02 17:46:54 by tcallens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int					ft_dirlen(char *name)
{
	int				ret;
	DIR				*dir;
	struct dirent	*file;

	ret = 0;
	if ((dir = opendir(name)) == NULL)
		return (-1);
	else
		while ((file = readdir(dir)) != NULL)
			ret++;
	(void)closedir(dir);
	return (ret);
}

t_file				**ft_init_dir(int nbr, t_file **dir)
{
	int				a;

	a = 0;
	if ((dir = (t_file **)malloc(sizeof(t_file *) * nbr)) == NULL)
		return (NULL);
	while (a < nbr)
	{
		if ((dir[a] = (t_file *)malloc(sizeof(t_file))) == NULL)
			return (NULL);
		dir[a]->path = NULL;
		dir[a]->name = NULL;
		dir[a]->perms = NULL;
		dir[a]->links = 0;
		dir[a]->linkpath = NULL;
		dir[a]->user = NULL;
		dir[a]->group = NULL;
		dir[a]->size = 0;
		dir[a]->timestamp = 0;
		dir[a]->ntimestamp = 0;
		dir[a]->blocks = 0;
		a++;
	}
	return (dir);
}

t_file				*fill_stats(t_file *d, char *n, char *pat, t_stats *stats)
{
	char			*ret;

	ret = NULL;
	d->name = ft_strdup(n);
	d->path = ft_strdup(pat);
	d->perms = find_modes(stats, ret);
	d->links = stats->st_nlink;
	d->linkpath = find_link(pat);
	d->user = find_user(stats);
	d->group = find_group(stats);
	d->size = find_majmin(stats);
	d->timestamp = stats->st_mtime;
	d->ntimestamp = stats->st_mtimespec.tv_nsec;
	d->blocks = stats->st_blocks;
	d->error = find_error(n);
	return (d);
}

t_file				**bef_fill_dir(char *name, t_info info)
{
	t_file			**file;
	char			*path;

	file = NULL;
	path = ft_strjoin(name, "/");
	file = ft_init_dir(info.size, file);
	file = fill_dir(name, path, info, file);
	ft_strdel(&path);
	return (file);
}

t_file				**fill_dir(char *n, char *pat, t_info info, t_file **file)
{
	DIR				*dir;
	struct stat		*stats;
	struct dirent	*dp;
	char			*tmp;
	int				a;

	a = 0;
	if ((dir = opendir(n)) == NULL)
		return (NULL);
	while (a < info.size && (dp = readdir(dir)) != NULL)
	{
		tmp = ft_strjoin(pat, dp->d_name);
		if ((stats = (struct stat *)malloc(sizeof(struct stat))) != NULL)
		{
			lstat(tmp, stats);
			file[a] = fill_stats(file[a], dp->d_name, tmp, stats);
			free(stats);
		}
		ft_strdel(&tmp);
		a++;
	}
	(void)closedir(dir);
	return (file);
}
