/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcallens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/09 02:52:03 by tcallens          #+#    #+#             */
/*   Updated: 2018/09/28 04:04:09 by tcallens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void				ft_print_fichier(char *name)
{
	ft_putstr(name);
}

void				ft_print_name(char *str)
{
	ft_putstr(str);
	ft_putstr(" ");
}

void				ft_print_dossier(char *name, t_args *args, int ind, t_info info)
{
	DIR				*dir;
	struct dirent	*dp;

	dir = opendir(name);
	if (ind > 1 || args->nbrfiles > 0)
	{
		ft_putstr(name);
		ft_putendl(":");
	}
	while ((dp = readdir(dir)) != NULL)
	{
		if (find_error(dp->d_name) == EACCES && info.type == 1)
			perm_denied(dp->d_name, info);
		else if (find_error(dp->d_name) != EPERM)
		{
			if (dp->d_name[0] != '.')
				ft_print_name(dp->d_name);
			else if (args->a == 1)
				ft_print_name(dp->d_name);
		}
	}
	(void)closedir(dir);
	if (ft_dirlen(name) > 2)
		ft_putendl("");
}

void				ft_print_time(long a)
{
	char *ret;

	if ((ret = ctime(&a)) == NULL)
		return ;
	ret[16] = '\0';
	ft_putstr(ret + 4);
}

void				ft_print_link(char *str)
{
	ft_putstr(" -> ");
	ft_putstr(str);
}

void				ft_print_dir_l(t_file **file, int ind, char *name, int nbr, t_args *args, t_pad *pad, t_info info)
{
	int a;

	a = 0;
	if (ind > 1 || args->nbrfiles > 0)
	{
		ft_putstr(name);
		ft_putendl(":");
	}
	//ft_intendl((int)file[3]->blocks);
	file = ft_range_t_dir(file, nbr, args);
	file = ft_range_r_dir(file, nbr, args);
	while (a < nbr)
	{
		if (file[a]->name[0] != '.')
		{
			if (args->l == 0)
				ft_print_name(file[a]->name);
			else
				ft_print_file_l(file[a], pad, info);
		}
		else if (args->a == 1)
		{
			if (args->l == 0)
				ft_print_name(file[a]->name);
			else
				ft_print_file_l(file[a], pad, info);
		}
		a++;
	}
}

void		ft_print_b(int nbr)
{
	int a;

	a = -1;
	while (++a < nbr)
		ft_putstr(" ");
}

void			ft_print_file_l(t_file *file, t_pad *pad, t_info info)
{
	if (file->error == EACCES && info.type == 1)
		perm_denied(file->name, info);
	else if (file->error == EPERM)
		return ;
	ft_putstr(file->perms);
	ft_print_b(pad->links - ft_nbrlen(file->links) + 2);
	ft_putnbr(file->links);
	ft_print_b(pad->user - ft_strlen(file->user) + 1);
	ft_putstr(file->user);
	ft_print_b(pad->group - ft_strlen(file->group) + 2);
	ft_putstr(file->group);
	ft_print_b(pad->size - ft_strlen(file->size) + 2);
	ft_putstr(file->size);
	ft_putstr(" ");
	ft_print_time(file->timestamp);
	ft_putstr(" ");
	ft_putstr(file->name);
	if (file->linkpath != NULL)
		ft_print_link(file->linkpath);
	ft_putchar('\n');

}
