/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_plus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcallens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/29 01:47:02 by tcallens          #+#    #+#             */
/*   Updated: 2018/10/01 08:57:38 by tcallens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		ft_print_link(char *str)
{
	ft_putstr(" -> ");
	ft_putstr(str);
}

t_file		**ft_print_dir_l(t_file **file, int ind, char *name, int nbr, t_args *args, t_pad *pad)
{
	int		a;

	a = 0;
	if ((ind > 1 || args->nbrfiles > 0) || args->notfile == 1)
	{
		ft_putstr(name);
		ft_putendl(":");
	}
	if (args->l == 1)
		print_blocks(file, nbr, args);
	file = ft_sort_as(file, nbr);
	file = ft_range_t_dir(file, nbr, args);
	file = ft_range_r_dir(file, nbr, args);
	while (a < nbr)
	{
		if ((args->a == 1 && file[a]->name[0] == '.')
				|| file[a]->name[0] != '.')
		{
			if (args->l == 0)
				ft_print_name(file[a]->name);
			else
				ft_print_file_l(file[a], pad);
		}
		a++;
	}
	if (ft_dirlen(name) > 2 && args->l == 0)
		ft_putendl("");
	return (file);
}

void		ft_print_b(int nbr)
{
	int		a;

	a = -1;
	while (++a < nbr)
		ft_putstr(" ");
}

void		ft_print_file_l(t_file *file, t_pad *pad)
{
	if (file->error == EPERM)
		return;
	else
	{
		ft_putstr(file->perms);
		ft_print_b(pad->links - ft_nbrlen(file->links) + 2);
		ft_putnbr(file->links);
		ft_print_b(pad->user - ft_strlen(file->user) + 1);
		ft_putstr(file->user);
		ft_print_b(pad->group - ft_strlen(file->group) + 2);
		ft_putstr(file->group);
		ft_print_b(pad->size - ft_strlen(file->size) + 2);
		ft_putstr(file->size);
		ft_putstr(" ");
		ft_print_time(file->timestamp);
		ft_putstr(" ");
		ft_putstr(file->name);
		if (file->linkpath != NULL)		
			ft_print_link(file->linkpath);
		ft_putchar('\n');
	}
}
