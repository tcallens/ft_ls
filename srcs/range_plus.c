/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   range_plus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcallens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 06:30:46 by tcallens          #+#    #+#             */
/*   Updated: 2018/10/01 06:38:48 by tcallens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_file		**ft_sort_as(t_file **tab, int nbr)
{
	int		a;
	t_file	*tmp;

	a = 0;
	while (a < nbr - 1)
	{
		if (ft_strcmp(tab[a]->name, tab[a + 1]->name) > 0)
		{
			tmp = tab[a];
			tab[a] = tab[a + 1];
			tab[a + 1] = tmp;
			if (a > 0)
				a -= 1;
		}
		else
			a++;
	}
	return (tab);
}

char		**ft_sort_tab(char **tab, int nbr)
{
	int		a;
	char	*tmp;

	a = 0;
	while (a < nbr - 1)
	{
		if (ft_strcmp(tab[a], tab[a + 1]) > 0)
		{
			tmp = tab[a];
			tab[a] = tab[a + 1];
			tab[a + 1] = tmp;
			if (a > 0)
				a -= 1;
		}
		else
			a++;
	}
	return (tab);
}
