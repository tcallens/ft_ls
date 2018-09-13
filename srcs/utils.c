/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcallens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/09 01:59:44 by tcallens          #+#    #+#             */
/*   Updated: 2018/09/11 03:40:58 by tcallens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		ft_nbr_files(char **av, int ac)
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

void	find_dir(char **av, t_args *args)
{
	int a;

	a = 0;
	while (av[a])
	{
		if (correct_args(av[a]) == 2)
			ft_ls_dir(av[a], args);
		a++;
	}
}
