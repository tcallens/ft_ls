/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcallens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/09 02:52:03 by tcallens          #+#    #+#             */
/*   Updated: 2018/09/27 02:44:20 by tcallens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void				ft_print_fichier(char *name)
{
	ft_putstr(name);
}

void				ft_print_dossier(char *name, t_args *args, int ind)
{
	DIR				*dir;
	struct dirent	*dp;

	dir = opendir(name);
	if (ind > 1 || args->nbrfiles > 0)
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
	if (ft_dirlen(name) > 2)
		ft_putendl("");
}

void				ft_print_dir_l(t_file **file, int ind, char *name, int nbr, t_args *args)
{
	int a;

	a = 0;
	if (ind > 1 || args->nbrfiles > 0)
	{
		ft_putstr(name);
		ft_putendl(":");
	}
	while (a < nbr)
	{
		if (file[a]->name[0] != '.')
		{
			ft_putstr(file[a]->perms);
			ft_putstr(" ");
			ft_putendl(file[a]->name);
		}
		else if (args->a == 1)
		{
			ft_putstr(file[a]->perms);
			ft_putstr(" ");
			ft_putendl(file[a]->name);
		}
		a++;
	}
}
