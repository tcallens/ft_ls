/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcallens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 04:13:07 by tcallens          #+#    #+#             */
/*   Updated: 2018/09/27 02:06:57 by tcallens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*find_modes(struct stat *file, char *ret)
{
	ret = ft_strnew(10);
	ret[0] = '-';
	ret[0] = ((file->st_mode & S_IFIFO) == S_IFIFO ? 'p' : ret[0]);
	ret[0] = ((file->st_mode & S_IFCHR) == S_IFCHR ? 'c' : ret[0]);
	ret[0] = ((file->st_mode & S_IFDIR) == S_IFDIR ? 'd' : ret[0]);
	ret[0] = ((file->st_mode & S_IFBLK) == S_IFBLK ? 'b' : ret[0]);
	ret[0] = ((file->st_mode & S_IFSOCK) == S_IFSOCK ? 's' : ret[0]);
	ret[0] = ((file->st_mode & S_IFLNK) == S_IFLNK ? 'l' : ret[0]);
	ret[1] = (file->st_mode & S_IRUSR ? 'r' : '-');
	ret[2] = (file->st_mode & S_IWUSR ? 'w' : '-');
	ret[3] = (file->st_mode & S_IXUSR ? 'x' : '-');
	ret[4] = (file->st_mode & S_IRGRP ? 'r' : '-');
	ret[5] = (file->st_mode & S_IWGRP ? 'w' : '-');
	ret[6] = (file->st_mode & S_IXGRP ? 'x' : '-');
	ret[7] = (file->st_mode & S_IROTH ? 'r' : '-');
	ret[8] = (file->st_mode & S_IWOTH ? 'w' : '-');
	ret[9] = (file->st_mode & S_IXOTH ? 'x' : '-');
	if (file->st_mode & S_ISUID)
		ret[3] = ret[3] == '-' ? 'S' : 's';
	if (file->st_mode & S_ISGID)
		ret[6] = ret[6] == '-' ? 'S' : 's';
	if (file->st_mode & S_ISVTX)
		ret[9] = ret[9] == '-' ? 'T' : 't';
	return (ret);
}

int		find_error(char *file)
{
	struct stat	*stats;
	DIR			*dir;

	dir = opendir(file);
	if (errno == EACCES)
		return (errno);
	if (dir != NULL)
		(void)closedir(dir);
	if ((stats = malloc(sizeof(struct stat))) == NULL)
		return (-1);
	lstat(file, stats);
	free(stats);
	return (errno);
}

char	*find_user(struct stat *stats)
{
	struct passwd	*usr;
	char			*ret;

	ret = NULL;
	if ((usr = getpwuid(stats->st_uid)) == NULL)
		ret = ft_itoa(stats->st_uid);
	else
		ret = ft_strdup(usr->pw_name);
	return (ret);
}

char	*find_group(struct stat *stats)
{
	struct group	*grp;
	char			*ret;

	ret = NULL;
	if ((grp = getgrgid(stats->st_gid)) == NULL)
		ret = ft_itoa(stats->st_gid);
	else
		ret = ft_strdup(grp->gr_name);
	return (ret);
}

char	*find_link(char *path, char *file)
{
	char	*buf;
	char	*tmp;

	tmp = ft_strdup(path);
	path = ft_strjoin(tmp, file);
	if ((buf = ft_strnew(1024)) == NULL)
		return (NULL);
	if (readlink(path, buf, 256) == -1)
		ft_strdel(&buf);
	ft_strdel(&tmp);
	ft_strdel(&path);
	return (buf);
}
