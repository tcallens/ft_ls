/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcallens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 08:14:48 by tcallens          #+#    #+#             */
/*   Updated: 2018/10/02 07:24:31 by tcallens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int				ft_file_link(char *name)
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

int				ft_nbr_files(char **av)
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
	return (ind);
}

int				ft_first_files(char **av, int ac)
{
	int			a;

	a = 1;
	while (av[a] && (av[a][0] == '-' && av[a][1]))
		a++;
	if (a == ac)
		return (0);
	return (a);
}

void			find_dir(char **av, t_args *args, int ind, int ret)
{
	int			a;
	int			nbr;
	char		**tab;

	a = -1;
	nbr = ind;
	tab = ft_find_tab(ind, av, args);
	while (++a < nbr && tab[a])
	{
		if (ind == nbr && ret > 0 && ind > 0)
			ft_putendl("");
		if (correct_args(tab[a]) == 2)
		{
			ft_ls_dir(tab[a], args, nbr);
			if (ind-- > 1)
				ft_putendl("");
		}
		if (find_error(tab[a]) == EACCES && correct_args(tab[a]) != 2)
		{
			ft_perm_denied(nbr, tab[a]);
			if (ind-- > 1)
				ft_putendl("");
		}
	}
	free(tab);
}

char			**ft_find_tab(int ind, char **av, t_args *args)
{
	char		**tab;
	char		*name;
	int			a;
	int			b;

	a = 0;
	b = 0;
	name = NULL;
	tab = (char **)malloc(sizeof(char *) * ind);
	while (av[a])
	{
		if (correct_args(av[a]) == 2)
		{
			name = ft_strjoin(av[a], "");
			tab[b++] = name;
		}
		if (find_error(av[a]) == EACCES && correct_args(av[a]) != 2)
			tab[b++] = av[a];
		a++;
	}
	tab = ft_sort_tab(tab, b);
	tab = ft_range_t(tab, b, args);
	tab = ft_range_r(tab, b - 1, args);
	return (tab);
}
