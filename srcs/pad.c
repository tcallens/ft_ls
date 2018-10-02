/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pad.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcallens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 01:17:05 by tcallens          #+#    #+#             */
/*   Updated: 2018/10/02 06:06:23 by tcallens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_pad		ft_init_pad(void)
{
	t_pad	pad;

	pad.directory_number = 0;
	pad.perms = 0;
	pad.links = 0;
	pad.user = 0;
	pad.group = 0;
	pad.size = 0;
	pad.timestamp = 0;
	pad.name = 0;
	pad.ind = 0;
	pad.nbr = 0;
	return (pad);
}

t_pad		ft_fill_pad(t_pad pad, int n, t_file **file, t_args *args)
{
	int		a;
	int		links;
	int		user;
	int		group;
	int		size;

	a = -1;
	if (file == NULL)
		return (pad);
	while (++a < n)
	{
		links = ft_nbrlen(file[a]->links);
		user = ft_strlen(file[a]->user);
		group = ft_strlen(file[a]->group);
		size = ft_strlen(file[a]->size);
		if ((args->a == 1 && file[a]->name[0] == '.')
				|| file[a]->name[0] != '.')
		{
			pad.links = ft_if(links, pad.links);
			pad.user = ft_if(user, pad.user);
			pad.group = ft_if(group, pad.group);
			pad.size = ft_if(size, pad.size);
		}
	}
	return (pad);
}

int			ft_if(int v1, int v2)
{
	if (v1 > v2)
		return (v1);
	else
		return (v2);
}

int			ft_nbrlen(int a)
{
	int		b;

	b = 0;
	while ((a / 10) > 0)
	{
		a = a / 10;
		b++;
	}
	return (b);
}
