/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_plus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcallens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/02 05:29:18 by tcallens          #+#    #+#             */
/*   Updated: 2018/10/02 18:05:26 by tcallens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void			ft_perm_denied(int nbr, char *name)
{
	if (nbr > 1)
		ft_double_point(name);
	perm_denied(name, 1);
}

int				find_files(char **av, t_args *args)
{
	int			a;
	int			b;
	t_pad		pad;

	a = 0;
	b = 0;
	pad.perms = 0;
	while (av[a])
	{
		if (correct_args(av[a]) == 1)
			b++;
		a++;
	}
	b = find_files_help(b, args, av, pad);
	return (b);
}

int				find_files_help(int b, t_args *ar, char **av, t_pad p)
{
	char		**tab;
	t_file		**file;
	int			a;

	tab = NULL;
	file = NULL;
	a = -1;
	if (b > 0)
	{
		tab = (char **)malloc(sizeof(char *) * b);
		b = 0;
		while (av[++a])
			if (correct_args(av[a]) == 1)
				tab[b++] = av[a];
		tab = ft_sort_tab(tab, b);
		tab = ft_range_t(tab, b, ar);
		tab = ft_range_r(tab, b - 1, ar);
		file = fill_files(b, tab);
		p = ft_fill_pad(ft_init_pad(), b, file, ar);
		a = ft_print_files(file, b, ar, p);
		free(tab);
		free_dir(file, b);
		b = a;
	}
	return (b);
}

t_file			**fill_files(int nbr, char **av)
{
	struct stat	*stats;
	t_file		**file;
	int			a;
	char		*path;

	a = 0;
	file = NULL;
	file = ft_init_dir(nbr, file);
	path = ft_strdup("");
	while (a < nbr)
	{
		if ((stats = (struct stat *)malloc(sizeof(struct stat))) != NULL)
		{
			lstat(av[a], stats);
			file[a] = fill_stats(file[a], av[a], path, stats);
			free(stats);
		}
		a++;
	}
	free(path);
	return (file);
}

int				ft_print_files(t_file **f, int nbr, t_args *ar, t_pad pad)
{
	int			a;
	int			ret;

	a = 0;
	ret = 0;
	while (a < nbr)
	{
		if (f[a]->error != EACCES && f[a]->perms[0] != 'd')
		{
			ret++;
			if (ar->l == 0)
				ft_print_name(f[a]->name);
			else
				ft_print_file_l(f[a], pad);
		}
		a++;
	}
	if (ar->l == 0 && ret == 1)
		ft_putendl("");
	return (ret);
}
