/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcallens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 08:14:48 by tcallens          #+#    #+#             */
/*   Updated: 2018/10/01 09:38:33 by tcallens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcallens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/09 01:59:44 by tcallens          #+#    #+#             */
/*   Updated: 2018/10/01 08:14:23 by tcallens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		ft_file_link(char *name)
{
	struct stat *stats;
	char		*str;
	char		*ret;

	str = NULL;
	ret = NULL;
	if ((stats = (struct stat *)malloc(sizeof(struct stat))) == NULL)
		return (-1);
	if (lstat(name, stats) == -1)
		return (-1);
	str = find_modes(stats, ret);
	if (str[0] == 'l')
	{
		ft_strdel(&str);
		free(name);
		free(stats);
		return (1);
	}
	free(stats);
	ft_strdel(&str);
	free(name);
	return (0);
}

int		ft_nbr_files(char **av)
{
	int a;
	int ind;

	a = 1;
	ind = 0;
	while (av[a] && av[a][0] == '-')
		a++;
	while (av[a])
	{
		if (correct_args(av[a]) == 2 ||
				(correct_args(av[a]) == 1 && find_error(av[a]) == EACCES))
			ind++;
		a++;
	}
	//if (ind > 1)
	//	ind++;
	return (ind);
}

int		ft_first_files(char **av, int ac)
{
	int a;

	a = 1;
	while (av[a] && (av[a][0] == '-' && av[a][1]))
		a++;
	if (a == ac)
		return (0);
	return (a);
}

int		find_files(char **av, t_args *args)
{
	int		a;
	int		b;
	char	**tab;
	t_pad	*pad;
	t_file	**file;

	a = 0;
	b = 0;
	tab = NULL;
	file = NULL;
	pad = NULL;
	while (av[a])
	{
		if (correct_args(av[a]) == 1)
			b++;
		a++;
	}
	if (b > 0)
	{
		tab = (char **)malloc(sizeof(char *) * b);
		a = 0;
		b = 0;
		while (av[a])
		{
			if (correct_args(av[a]) == 1)
				tab[b++] = av[a];
			a++;
		}
		tab = ft_sort_tab(tab, b);
		tab = ft_range_t(tab, b, args);
		tab = ft_range_r(tab, b - 1, args);
		file = fill_files(b, tab);
		pad = ft_fill_pad(ft_init_pad(), b, file, args);
		b = ft_print_files(file, b, args, pad);
		free(tab);
		free_dir(file, b);
		free(pad);
	}
	return (b);
}

t_file	**fill_files(int nbr, char **av)
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
	return (file);
}

int		ft_print_files(t_file **file, int nbr, t_args *args, t_pad *pad)
{
	int a;
	int ret;

	a = 0;
	ret = 0;
	file = ft_range_t_dir(file, nbr, args);
	file = ft_range_r_dir(file, nbr, args);
	while (a < nbr)
	{
		if (file[a]->error != EACCES && file[a]->perms[0] != 'd')
		{
			ret++;
			if (args->l == 0)
				ft_print_name(file[a]->name);
			else
				ft_print_file_l(file[a], pad);
		}
		a++;
	}
	if (args->l == 0 && ret == 1)
		ft_putendl("");
	return (ret);
}

void	find_dir(char **av, t_args *args, int ind, int ret)
{
	int		a;
	char	*name;
	int		nbr;

	a = 0;
	name = NULL;
	nbr = ind;
	while (av[a])
	{
		if (ind == nbr && ret > 0 && ind > 0)
			ft_putendl("");
		if (correct_args(av[a]) == 2)
		{
			name = ft_strjoin(av[a], "");
			ft_ls_dir(name, args, nbr);
			if (ind > 1)
				ft_putendl("");
		}
		if (find_error(av[a]) == EACCES && correct_args(av[a]) != 2)
		{
			if (nbr > 1)
			{
				ft_putstr(av[a]);
				ft_putendl(":");
			}
			perm_denied(av[a], 1);
			if (ind > 1)
				ft_putendl("");
		}
		ind--;
		a++;
	}
}
