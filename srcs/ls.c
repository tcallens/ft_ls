/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcallens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 02:15:58 by tcallens          #+#    #+#             */
/*   Updated: 2018/09/27 04:43:34 by tcallens         ###   ########.fr       */
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
	if (args->R == 1)
		ft_rec(name, args, ind);
	free(name);
}

void		ft_rec(char *name, t_args *args, int ind)
{
	char			*path;
	DIR				*dir;
	struct dirent	*dp;
	char			**tab;
	int				a;

	a = 0;
	path = ft_strjoin(name, "/");
	dir = opendir(name);
	tab = (char **)malloc(sizeof(char *) * ft_dirlen(name) + 1);
	while ((dp = readdir(dir)) != NULL && args->R == 1)
	{
		if (dp->d_name[0] == '.' && dp->d_name[1] && dp->d_name[1] != '.'
				&& args->a == 1
				&& (correct_args_free(ft_strjoin(path, dp->d_name)) == 2)
				&& (ft_file_link(ft_strjoin(path, dp->d_name)) == 0))
			tab[a++] = ft_strjoin(path, dp->d_name);
		else if (dp->d_name[0] != '.'
				&& correct_args_free(ft_strjoin(path, dp->d_name)) == 2 &&
				ft_file_link(ft_strjoin(path, dp->d_name)) == 0)
			tab[a++] = ft_strjoin(path, dp->d_name);
	}
	ft_help_rec(a, args, tab, ind);
	free(path);
	(void)closedir(dir);
}

void		ft_help_rec(int a, t_args *args, char **tab, int ind)
{
	int ret;

	tab = ft_range_t(tab, a, args);
	tab = ft_range_r(tab, --a, args);
	ret = a;
	a = 0;
	while (a <= ret)
	{
		ft_putendl("");
		ft_ls_dir(tab[a++], args, ind);
	}
	free(tab);
}
