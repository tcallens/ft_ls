/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcallens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 02:15:58 by tcallens          #+#    #+#             */
/*   Updated: 2018/09/30 04:39:00 by tcallens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		ft_ls_dir(char *name, t_args *args, int ind)
{
	t_file			**tabdir;
	int				a;
	t_info			info;
	t_pad			*pad;

	a = 0;
	info.size = ft_dirlen(name);
	info.type = 0;
	tabdir = bef_fill_dir(name, info);
	pad = ft_fill_pad(ft_init_pad(), info.size, tabdir, args);
	not_permitted(tabdir, info);
	ft_print_dir_l(tabdir, ind++, name, info.size, args, pad, info);
	//free_dir(tabdir, info.size);
	free(pad);
	info.ind = ind;
	if (args->R == 1)
		ft_rec(name, args, info, tabdir);
	free(name);
}

void		ft_rec(char *name, t_args *args, t_info info, t_file **tabdir)
{
	char			*path;
	//DIR				*dir;
	//struct dirent	*dp;
	char			**tab;
	int				a;
	int				b;

	a = 0;
	b = 0;
	path = ft_strjoin(name, "/");
	//dir = opendir(name);
	tab = (char **)malloc(sizeof(char *) * info.size);
/*while ((dp = readdir(dir)) != NULL && args->R == 1)
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
	}*/
	while (a < info.size)
	{
		if ((tabdir[a]->perms[0] == 'd' && tabdir[a]->name[0] != '.') ||
				(tabdir[a]->name[0] == '.' &&
					args->a == 1 && tabdir[a]->perms[0] == 'd'))
			tab[b++] = ft_strjoin(tabdir[a]->name, "");
		a++;
	}
	free_dir(tabdir, info.size);
	ft_help_rec(b, args, tab, info);
	free(path);
	//(void)closedir(dir);
}

void		ft_help_rec(int a, t_args *args, char **tab, t_info info)
{
	int ret;

	tab = ft_range_t(tab, a, args);
	tab = ft_range_r(tab, --a, args);
	ret = a;
	a = 0;
	while (a <= ret)
	{
		ft_putendl("");
		if (find_error(ft_strjoin(tab[a]) != EACCES)
			ft_ls_dir(tab[a++], args, info.ind);
		else
			perm_denied(tab[a++], info);
	}
	free(tab);
}
