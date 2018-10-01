/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcallens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 02:15:58 by tcallens          #+#    #+#             */
/*   Updated: 2018/10/01 10:23:03 by tcallens         ###   ########.fr       */
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
	tabdir = ft_print_dir_l(tabdir, ind++, name, info.size, args, pad);
	free(pad);
	info.ind = ind;
	if (args->R == 1)
		ft_rec(name, args, info, tabdir);
	free(name);
	free_dir(tabdir, info.size);
}

void		ft_rec(char *name, t_args *args, t_info info, t_file **tabdir)
{
	char			*path;
	char			**tab;
	int				intt[info.size + 50];
	int				a;
	int				b;

	a = 0;
	b = -1;
	while (a < info.size)
	{
		intt[b++] = 0;
		a++;
	}
	a = 0;
	b = -1;
	path = ft_strjoin(name, "/");
	tab = (char **)malloc(sizeof(char *) * info.size);
	while (a < info.size)
	{
		if ((tabdir[a]->perms[0] == 'd' && tabdir[a]->name[0] != '.') ||
				(tabdir[a]->name[0] == '.' && tabdir[a]->name[1] &&
				 tabdir[a]->name[1] != '.' && args->a == 1
				 && tabdir[a]->perms[0] == 'd'))
		{
			tab[++b] = ft_strjoin(path, tabdir[a]->name);
			if (tabdir[a]->error == EACCES && tabdir[a]->perms[0] == 'd')
				intt[b] = 1;
		}
		a++;
	}
	ft_help_rec(b + 1, args, tab, info, intt);
	free(path);
}

void		ft_help_rec(int a, t_args *args, char **tab, t_info info, int *intt)
{
	int ret;

	//tab = ft_sort_tab(tab, a);
	//tab = ft_range_t(tab, a, args);
	//tab = ft_range_r(tab, --a, args);
	a--;
	ret = a;
	a = 0;
	while (a <= ret)
	{
		ft_putendl("");
		if (intt[a] == 0)
			ft_ls_dir(tab[a++], args, info.ind);
		else
		{
			ft_putstr(tab[a]);
			ft_putendl(":");
			perm_denied(tab[a], 0);
			free(tab[a++]);
		}
	}
	intt[0] = 0;
	free(tab);
}
