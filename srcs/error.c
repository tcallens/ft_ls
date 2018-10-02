/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcallens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 20:51:19 by tcallens          #+#    #+#             */
/*   Updated: 2018/10/02 09:39:12 by tcallens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void				ft_error_options(char option)
{
	ft_putstr_fd("./ft_ls: illegal option -- ", STDERR_FILENO);
	ft_putchar_fd(option, STDERR_FILENO);
	ft_putstr_fd("\nusage: ./ft_ls [-lartR] [file ...]\n", STDERR_FILENO);
	exit(1);
}

int					correct_args_free(char *str)
{
	int				ret;
	struct stat		*stats;
	DIR				*dir;

	stats = NULL;
	ret = 0;
	if ((dir = opendir(str)) != NULL)
	{
		(void)closedir(dir);
		ft_memdel((void **)&str);
		ret = 2;
		return (ret);
	}
	if ((stats = (struct stat *)malloc(sizeof(struct stat))) == NULL)
		return (ret);
	if (lstat(str, stats) == -1)
		return (ret);
	free(stats);
	ft_memdel((void **)&str);
	return (ret);
}

t_args				*ft_not_file(char *str, t_args *args)
{
	ft_putstr_fd("ls: ", STDERR_FILENO);
	ft_putstr_fd(str, STDERR_FILENO);
	ft_putstr_fd(": No such file or directory\n", STDERR_FILENO);
	args->notfile = 1;
	return (args);
}

void				perm_denied(char *file, int size)
{
	if (size > 2)
		ft_putchar('\n');
	ft_putstr_fd("./ft_ls: ", STDERR_FILENO);
	ft_putstr_fd(file, STDERR_FILENO);
	ft_putstr_fd(": Permission denied\n", STDERR_FILENO);
}

void				not_permitted(t_file **file, t_info info)
{
	int				a;

	a = -1;
	while (++a < info.size)
		if (file[a]->error == EPERM)
		{
			ft_putstr_fd("./ft_ls: ", STDERR_FILENO);
			ft_putstr_fd(file[a]->name, STDERR_FILENO);
			ft_putstr_fd(": Operation not permitted\n", STDERR_FILENO);
		}
}
