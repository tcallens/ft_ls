/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcallens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/09 02:52:03 by tcallens          #+#    #+#             */
/*   Updated: 2018/09/13 04:33:17 by tcallens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void				ft_print_fichier(char *name)
{
	ft_putendl(name);
	ft_putendl("");
}

void				ft_print_dossier(char *name, t_args *args, int ind)
{
	DIR				*dir;
	struct dirent	*dp;

	dir = opendir(name);
	if (ind > 2)
	{
	ft_putstr(name);
	ft_putendl(":");
	}
	while ((dp = readdir(dir)) != NULL)
	{
		if (dp->d_name[0] != '.')
		{
			ft_putstr(dp->d_name);
			ft_putstr(" ");
		}
		else if (args->a == 1)
		{
		ft_putstr(dp->d_name);
		ft_putstr(" ");
		}
	}
	(void)closedir(dir);
	ft_putendl("");
	ft_putendl("");
}
