/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_plus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcallens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/29 01:47:02 by tcallens          #+#    #+#             */
/*   Updated: 2018/10/02 05:24:09 by tcallens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		ft_print_link(char *str)
{
	ft_putstr(" -> ");
	ft_putstr(str);
}

t_file		**ft_p_dir_l(t_file **f, char *n, t_args *ar, t_pad p)
{
	int		a;

	a = -1;
	if ((p.ind > 1 || ar->nbrfiles > 0) || ar->notfile == 1)
		ft_double_point(n);
	if (ar->l == 1)
		print_blocks(f, p.nbr, ar);
	f = ft_sort_as(f, p.nbr);
	f = ft_range_t_dir(f, p.nbr, ar);
	f = ft_range_r_dir(f, p.nbr, ar);
	while (++a < p.nbr)
	{
		if ((ar->a == 1 && f[a]->name[0] == '.')
				|| f[a]->name[0] != '.')
		{
			if (ar->l == 0)
				ft_print_name(f[a]->name);
			else
				ft_print_file_l(f[a], p);
		}
	}
	if (ft_dirlen(n) > 2 && ar->l == 0)
		ft_putendl("");
	return (f);
}

void		ft_print_b(int nbr)
{
	int		a;

	a = -1;
	while (++a < nbr)
		ft_putstr(" ");
}

void		ft_print_file_l(t_file *file, t_pad pad)
{
	if (file->error == EPERM)
		return ;
	else
	{
		ft_putstr(file->perms);
		ft_print_b(pad.links - ft_nbrlen(file->links) + 2);
		ft_putnbr(file->links);
		ft_print_b(pad.user - ft_strlen(file->user) + 1);
		ft_putstr(file->user);
		ft_print_b(pad.group - ft_strlen(file->group) + 2);
		ft_putstr(file->group);
		ft_print_b(pad.size - ft_strlen(file->size) + 2);
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
