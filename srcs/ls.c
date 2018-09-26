/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcallens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 02:15:58 by tcallens          #+#    #+#             */
/*   Updated: 2018/09/26 04:50:33 by tcallens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

/*void		ft_ls_dir(char *name, t_args *args, int ind)
{
	char			*path;
	DIR				*dir;
	struct dirent	*dp;

	path = ft_strjoin(name, "/");
	if (args->l == 0)
		ft_print_dossier(name, args, ind++);
	else
		fill_dir(name, args, ind++);
	dir = opendir(name);
	while ((dp = readdir(dir)) != NULL && args->R == 1)
	{
		if (dp->d_name[0] != '.' &&
				correct_args_free(ft_strjoin(path, dp->d_name)) == 2 &&
				ft_file_link(ft_strjoin(path,dp->d_name)) == 0)
		{
			ft_putendl("");
			ft_ls_dir(ft_strjoin(path, dp->d_name), args, ind);
		}
	}
	free(name);
	free(path);
	(void)closedir(dir);
}*/

void		ft_ls_dir(char *name, t_args *args, int ind)
{
	t_file			**tabdir;
	int				a;
	t_info			info;

	a = 0;
	info.size = ft_dirlen(name);
	info.type = 0;
	tabdir = bef_fill_dir(name, info);
	if (args->l == 0)
		ft_print_dossier(name, args, ind++);
	else
		ft_print_dir_l(tabdir, ind++, name, info.size, args);
	free_dir(tabdir, info.size);
	ft_rec(name, args, ind);
	free(name);
}

void		ft_rec(char *name, t_args *args, int ind)
{
	char			*path;
	DIR				*dir;
	struct dirent	*dp;

	path = ft_strjoin(name, "/");
	dir = opendir(name);
	while ((dp = readdir(dir)) != NULL && args->R == 1)
	{
		if (dp->d_name[0] != '.' &&
				correct_args_free(ft_strjoin(path, dp->d_name)) == 2 &&
				ft_file_link(ft_strjoin(path,dp->d_name)) == 0)
		{
			ft_putendl("");
			ft_ls_dir(ft_strjoin(path, dp->d_name), args, ind);
		}
	}
	free(path);
	(void)closedir(dir);

}
