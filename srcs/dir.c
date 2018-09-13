/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcallens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 02:00:32 by tcallens          #+#    #+#             */
/*   Updated: 2018/09/13 04:21:07 by tcallens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_file		**ft_init_dir(int nbr, t_file **dir)
{
	int		a;

	a = 0;
	if ((dir = (t_file **)malloc(sizeof(t_file *) * nbr)) == NULL)
		return (NULL);
	while (a < nbr)
	{
		if ((dir[a] = (t_file *)malloc(sizeof(t_file))) == NULL)
			return (NULL);
		dir[a]->path = NULL;
		dir[a]->name = NULL;
		dir[a]->perms = NULL;
		dir[a]->links = 0;
		dir[a]->linkpath = NULL;
		dir[a]->user = NULL;
		dir[a]->group = NULL;
		dir[a]->size = 0;
		dir[a]->timestamp = 0;
		dir[a]->ntimestamp = 0;
		dir[a]->blocks = 0;
		a++;
	}
	return (dir);
}
