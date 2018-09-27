/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plus.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcallens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 04:10:52 by tcallens          #+#    #+#             */
/*   Updated: 2018/09/27 03:42:39 by tcallens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_print_double(char **str)
{
	int a;
	int ret;

	ret = 0;
	a = 0;
	while (str[a])
	{
		if (correct_args(str[a]) == 1)
			ret = 1;
		a++;
	}
	if (ret == 1)
	{
		ft_putendl("");
		ft_putendl("");
	}
}

void	print_blocks(t_file **dir, int size, t_args *options)
{
	int ret;
	int i;

	i = 0;
	ret = 0;
	while (i < size)
	{
		if (!(options->a == 0 && dir[i]->name[0] == '.'))
			ret += dir[i]->blocks;
		i++;
	}
	ft_putstr("total ");
	ft_intendl(ret);
}

long	get_timestamp(char *dir)
{
	struct stat	*stats;
	int			ret;

	ret = 0;
	stats = malloc(sizeof(struct stat));
	if (lstat(dir, stats) == -1)
		ret = -1;
	else
		ret = stats->st_mtime;
	free(stats);
	return (ret);
}

int		next_dir_offset(char **av)
{
	int ret;

	ret = 1;
	while (av[ret] && correct_args(av[ret]) != 2)
		ret++;
	if (correct_args(av[ret]) == 2)
		return (ret);
	else
		return (0);
}

char	*find_majmin(struct stat *stats)
{
	char *ret;

	if (!S_ISCHR(stats->st_mode) && !S_ISBLK(stats->st_mode))
		return (ft_itoa(stats->st_size));
	else
	{
		ret = ft_strjoin(ft_itoa(major(stats->st_rdev)), ", ");
		ret = ft_strjoin(ret, ft_itoa(minor(stats->st_rdev)));
		ret = ft_strjoin (ret, "\0");
	}
	return (ret);
}
