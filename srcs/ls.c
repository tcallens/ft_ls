/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcallens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 02:15:58 by tcallens          #+#    #+#             */
/*   Updated: 2018/09/11 04:17:45 by tcallens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		ft_ls_dir(char *name, t_args *args)
{
	char			*path;
	DIR				*dir;
	struct dirent	*dp;

	path = ft_strjoin(name, "/");
	ft_print_dossier(name, args);
	dir = opendir(name);
	while ((dp = readdir(dir)) != NULL && args->R == 1)
	{
		if (dp->d_name[0] != '.' &&
				correct_args_free(ft_strjoin(path, dp->d_name)) == 2)
			ft_ls_dir(ft_strjoin(path, dp->d_name), args);
	}
	(void)closedir(dir);
}
