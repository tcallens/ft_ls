/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcallens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/09 01:59:44 by tcallens          #+#    #+#             */
/*   Updated: 2018/09/25 04:09:43 by tcallens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		ft_nbr_files(char **av)
{
	int a;
	int ind;

	a = 1;
	ind = 0;
	while (av[a] && av[a][0] == '-')
		a++;
	while (av[a] && av[a][0] != '-' && (correct_args(av[a]) > 0))
	{
		a++;
		ind++;
	}
	if (ind > 1)
		ind++;
	return (ind);
}

int		ft_first_files(char **av, int ac)
{
	int a;

	a = 1;
	while (av[a] && av[a][0] == '-')
		a++;
	if (a == ac)
		return (0);
	return (a);
}

void	find_files(char **av)
{
	int a;

	a = 0;
	while (av[a])
	{
		if (correct_args(av[a]) == 1)
			ft_print_fichier(av[a]);
		a++;
	}
}

void	find_dir(char **av, t_args *args, int ind)
{
	int		a;
	char	*name;

	a = 0;
	name = NULL;
	while (av[a])
	{
		if (correct_args(av[a]) == 2)
		{
			name = ft_strjoin(av[a], "");
			ft_ls_dir(name, args, ind--);
			if (ind > 1)
				ft_putendl("");
		}
		a++;;
	}
}
