/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcallens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 02:15:58 by tcallens          #+#    #+#             */
/*   Updated: 2018/10/02 10:37:11 by tcallens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		ft_ls_dir(char *name, t_args *args, int ind)
{
	t_file	**tabdir;
	int		a;
	t_info	info;
	t_pad	pad;

	a = 0;
	info.size = ft_dirlen(name);
	info.type = 0;
	tabdir = bef_fill_dir(name, info);
	pad = ft_fill_pad(ft_init_pad(), info.size, tabdir, args);
	pad.ind = ind;
	pad.nbr = info.size;
	not_permitted(tabdir, info);
	tabdir = ft_p_dir_l(tabdir, name, args, pad);
	info.ind = ind + 1;
	if (args->rec == 1)
		ft_rec(name, args, info, tabdir);
	free(name);
	free_dir(tabdir, info.size);
}

int			*ft_fill_int(int nbr)
{
	int		a;
	int		*tab;

	a = 0;
	tab = (int *)malloc(sizeof(int) * nbr + 1);
	while (a < nbr)
	{
		tab[a] = 0;
		a++;
	}
	return (tab);
}

void		ft_rec(char *n, t_args *args, t_info inf, t_file **tabdir)
{
	char	**tab;
	int		*intt;
	int		a;

	a = -1;
	inf.afhr = -1;
	intt = ft_fill_int(inf.size + 50);
	inf.path = ft_cmp_if(n);
	tab = (char **)malloc(sizeof(char *) * inf.size);
	while (++a < inf.size)
	{
		if ((tabdir[a]->perms[0] == 'd' && tabdir[a]->name[0] != '.')
				|| (tabdir[a]->name[0] == '.' && tabdir[a]->name[1]
					&& tabdir[a]->name[1] != '.' && args->a == 1
					&& tabdir[a]->perms[0] == 'd'))
		{
			tab[++inf.afhr] = ft_strjoin(tabdir[a]->name, "");
			if (tabdir[a]->error == EACCES && tabdir[a]->perms[0] == 'd')
				intt[inf.afhr] = 1;
		}
	}
	ft_help_rec(args, tab, inf, intt);
	free(intt);
}

char		*ft_cmp_if(char *name)
{
	if (ft_strcmp(name, "/") == 0)
		return (ft_strjoin(name, ""));
	else
		return (ft_strjoin(name, "/"));
}

void		ft_help_rec(t_args *ar, char **tab, t_info i, int *intt)
{
	int		ret;
	int		a;
	char	*tmp;

	a = i.afhr;
	ret = a;
	a = 0;
	tmp = NULL;
	while (a <= ret)
	{
		tmp = ft_strjoin(i.path, tab[a]);
		ft_putendl("");
		if (intt[a] == 0)
			ft_ls_dir(tmp, ar, i.ind);
		else
		{
			ft_double_point(tmp);
			perm_denied(tab[a], 0);
		}
		free(tab[a]);
		a++;
	}
	free(i.path);
	intt[0] = 0;
	free(tab);
}
