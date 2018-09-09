/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcallens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 19:02:36 by tcallens          #+#    #+#             */
/*   Updated: 2018/09/09 05:32:56 by tcallens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		ls(char *name, t_args *args, int fichier)
{
	if (fichier == 1)
	{
		ft_print_fichier(name);
	}
	else if (fichier == 0)
	{
		ft_print_dossier(ft_strjoin(name, "/"), name, args);
	}
	else
		return (0);
	(void)args;
	return (1);
}

int		main(int ac, char **av)
{
	t_args	*args;

	if ((args = ft_init_args(av)) == NULL)
		return (0);
	if (ft_nbr_files(av, ac) == 0)
		ls("./", args, 0);
	else
		find_names(&av[ft_nbr_files(av, ac)], args);
	ft_putendl("----------------------");
	ft_putstr("l : ");
	ft_intendl(args->l);
	ft_putstr("R : ");
	ft_intendl(args->R);
	ft_putstr("a : ");
	ft_intendl(args->a);
	ft_putstr("r : ");
	ft_intendl(args->r);
	ft_putstr("t : ");
	ft_intendl(args->t);
	free(args);
	return (1);
}
