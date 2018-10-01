/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_dir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcallens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 01:17:30 by tcallens          #+#    #+#             */
/*   Updated: 2018/10/01 09:41:53 by tcallens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	free_file(t_file *dir)
{
	if (dir != NULL)
	{
		ft_strdel(&dir->name);
		ft_strdel(&dir->path);
		ft_strdel(&dir->perms);
		ft_strdel(&dir->user);
		ft_strdel(&dir->group);
		ft_strdel(&dir->size);
		ft_strdel(&dir->linkpath);
		free(dir);
	}
}

void	free_dir(t_file **dir, int size)
{
	int i;

	i = 0;
	if (dir != NULL)
	{
		while (i < size)
			free_file(dir[i++]);
		free(dir);
	}
}
