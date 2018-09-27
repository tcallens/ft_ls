/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   range.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcallens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 00:49:58 by tcallens          #+#    #+#             */
/*   Updated: 2018/09/27 04:44:28 by tcallens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char		**ft_range_r(char **tab, int nbr, t_args *args)
{
	int		a;
	char	*tmp;

	a = 0;
	tmp = NULL;
	if (args->r == 1 && nbr > 0)
	{
		while (a < nbr)
		{
			tmp = tab [a];
			tab[a] = tab[nbr];
			tab[nbr] = tmp;
			tmp = NULL;
			nbr--;
			a++;
		}
	}
	return (tab);
}

char	**ft_range_t(char **tab, int nbr, t_args *args)
{
	int		a;
	char	*tmp;
	long	c;
	long	d;

	a = 0;
	c = 0;
	d = 0;
	if (args->t == 1 && nbr > 0)
	{
		while (a < nbr)
		{
			if (ft_cmp_time(tab[a], tab[a + 1], c, d) == 1)
			{
				tmp = tab[a];
				tab[a] = tab[a + 1];
				tab[a + 1] = tmp;
				a = 0;
			}
			else
				a++;
		}
	}
	return (tab);
}

int		ft_cmp_time(char *s1, char *s2, long c, long d)
{
	struct stat	*stats;
	struct stat	*stats2;
	long		a;
	long		b;

	a = 0;
	b = 0;
	if ((stats = (struct stat *)malloc(sizeof(struct stat))) == NULL)
		return (-1);
	if ((stats2 = (struct stat *)malloc(sizeof(struct stat))) == NULL)
		return (-1);
	lstat(s1, stats);
	lstat(s2, stats2);
	a = stats->st_mtime;
	b = stats2->st_mtime;
	c = stats->st_mtimespec.tv_nsec;
	d = stats2->st_mtimespec.tv_nsec;
	free(stats);
	free(stats2);
	if ((a < b) || (a == b && c < d))
		return (1);
	return (0);	
}
