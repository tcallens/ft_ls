/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcallens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 19:04:43 by tcallens          #+#    #+#             */
/*   Updated: 2018/09/09 04:21:43 by tcallens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int				ft_options(char *str, t_args *args)
{
	int a;

	a = 1;
	while (str[a])
	{
		if (str[a] != 'l' && str[a] != 'R' && str[a] != 'a' && str[a] != 'r'
				&& str[a] != 't')
			ft_error_options();
		if (str[a] == 'l')
			args->l = 1;
		if (str[a] == 'R')
			args->R = 1;
		if (str[a] == 'a')
			args->a = 1;
		if (str[a] == 'r')
			args->r = 1;
		if (str[a] == 't')
			args->t = 1;
		a++;
	}
	return (a);
}

t_args			*ft_init_args(char **av)
{
	t_args		*args;
	int 		a;
	int 		b;

	a = 1;
	if ((args = (t_args *)malloc(sizeof(t_args))) == NULL)
		return (NULL);
	args->l = 0;
	args->R = 0;
	args->a = 0;
	args->r = 0;
	args->t = 0;
	while (av[a] && av[a][0] == '-')
	{
		b = ft_options(av[a++], args);
	}
	while (av[a])
	{
		if (correct_args(av[a]) == 0)
			ft_not_file(av[a]);
		a++;
	}
	return (args);
}
