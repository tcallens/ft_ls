/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcallens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 20:51:19 by tcallens          #+#    #+#             */
/*   Updated: 2018/09/13 04:11:42 by tcallens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void				ft_error_options(void)
{
	ft_putendl("pas bon arguement bordel");
}

int					correct_args(char *str)
{
	int				ret;
	struct stat		*stats;
	DIR				*dir;

	stats = NULL;
	ret = 0;
	if ((dir = opendir(str)) != NULL)
	{
		(void)closedir(dir);
		ret = 2;
		return (ret);
	}
	if ((stats = (struct stat *)malloc(sizeof(struct stat))) == NULL)
		return (ret);
	if (lstat(str, stats) == -1)
		return (ret);
	ret = 1;
	free(stats);
	return (ret);
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
		ret = 2;
		return (ret);
	}
	if ((stats = (struct stat *)malloc(sizeof(struct stat))) == NULL)
		return (ret);
	if (lstat(str, stats) == -1)
		return (ret);
	ret = 1;
	free(stats);
	ft_memdel((void **)&str);
	return (ret);
}

void				ft_not_file(char *str)
{
	ft_putstr_fd("ls: ", STDERR_FILENO);
	ft_putstr_fd(str, STDERR_FILENO);
	ft_putstr_fd(": No such file or directory\n", STDERR_FILENO);
}
