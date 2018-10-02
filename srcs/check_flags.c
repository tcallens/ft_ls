/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcallens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 19:04:43 by tcallens          #+#    #+#             */
/*   Updated: 2018/10/02 06:50:20 by tcallens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int					ft_options(char *str, t_args *args)
{
	int				a;

	a = 1;
	while (str[a])
	{
		if (str[a] != 'l' && str[a] != 'R' && str[a] != 'a' && str[a] != 'r'
				&& str[a] != 't')
			ft_error_options(str[a]);
		if (str[a] == 'l')
			args->l = 1;
		if (str[a] == 'R')
			args->rec = 1;
		if (str[a] == 'a')
			args->a = 1;
		if (str[a] == 'r')
			args->r = 1;
		if (str[a] == 't')
			args->t = 1;
		a++;
	}
	return (a);
}

t_args				*ft_init_args(char **av)
{
	t_args			*args;
	int				a;
	int				b;

	a = 1;
	args = ft_i_a_help(av);
	while (av[a] && av[a][0] == '-')
	{
		if (!(av[a][1]))
			args = ft_not_file(av[a++], args);
		else
			b = ft_options(av[a++], args);
	}
	while (av[a])
	{
		if (correct_args(av[a]) == 0)
			args = ft_not_file(av[a], args);
		a++;
	}
	return (args);
}

t_args				*ft_i_a_help(char **av)
{
	t_args			*args;

	if ((args = (t_args *)malloc(sizeof(t_args))) == NULL)
		return (NULL);
	args->l = 0;
	args->rec = 0;
	args->a = 0;
	args->r = 0;
	args->t = 0;
	args->nbrfiles = ft_files(av);
	args->notfile = 0;
	return (args);
}

int					ft_files(char **av)
{
	int a;
	int ret;

	a = 1;
	ret = 0;
	while (av[a])
	{
		if (correct_args(av[a]) == 1)
			ret = 1;
		a++;
	}
	return (ret);
}

int					correct_args(char *str)
{
	int				ret;
	struct stat		*stats;
	DIR				*dir;

	stats = NULL;
	ret = 0;
	if ((dir = opendir(str)) != NULL)
	{
		(void)closedir(dir);
		ret = 2;
		return (ret);
	}
	if ((stats = (struct stat *)malloc(sizeof(struct stat))) == NULL)
		return (ret);
	if (lstat(str, stats) == -1)
	{
		free(stats);
		return (ret);
	}
	ret = 1;
	free(stats);
	return (ret);
}
