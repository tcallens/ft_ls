/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcallens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 02:00:32 by tcallens          #+#    #+#             */
/*   Updated: 2018/09/25 04:39:10 by tcallens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int			ft_dirlen(char *name)
{
	int				ret;
	DIR				*dir;
	struct dirent	*file;

	ret = 0;
	if ((dir = opendir(name)) == NULL)
		ret = 1;
	else
		while ((file = readdir(dir)) != NULL)
			ret++;
	(void)closedir(dir);
	return (ret);

}

t_file		**ft_init_dir(int nbr, t_file **dir)
{
	int		a;

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

t_file	*fill_stats(t_file *dir, char *name, char *path, t_stats *stats)
{
	dir->name = ft_strdup(name);
	dir->path = ft_strjoin(path, name);
	dir->perms = find_modes(stats);
	dir->links = stats->st_nlink;
	dir->linkpath = find_link(path, dir->name);
	dir->user = find_user(stats);
	dir->group = find_group(stats);
	dir->size = find_majmin(stats);
	dir->timestamp = stats->st_mtime;
	dir->ntimestamp = stats->st_mtimespec.tv_nsec;
	dir->blocks = stats->st_blocks;
	dir->error = find_error(name);
	free(stats);
	return (dir);
}

void	fill_dir(char *name, t_args *args, int ind)
{
	DIR				*dir;
	struct dirent	*dp;
	t_file			**file;
	struct stat		*stats;
	int				a;
	char			*tmp;
	t_info			info;

	if (args->l)
		info.type = 0;
	file = NULL;
	info.size = ft_dirlen(name);
	info.type = 0;
	a = 0;
	tmp = ft_strjoin(name, "/");
	file = ft_init_dir(info.size, file);
	if ((dir = opendir(name)) == NULL)
		return ;
	while (a < info.size && (dp = readdir(dir)) != NULL)
	{
		if ((stats = (struct stat *)malloc(sizeof(struct stat))) != NULL)
		{
			lstat(ft_strjoin(tmp,dp->d_name), stats);
			file[a] = fill_stats(file[a], dp->d_name, tmp, stats);
		}
		a++;
	}
	ft_print_dir_l(file, ind, name);
	(void)closedir(dir);
}

