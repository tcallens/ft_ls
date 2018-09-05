/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcallens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 19:02:36 by tcallens          #+#    #+#             */
/*   Updated: 2018/09/05 21:57:18 by tcallens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		main(int ar, char **av)
{
	t_args	*args;
	
	(void)ar;
	if (ar <= 1)
		return (0);
	if ((args = ft_init_args(av)) == NULL)
		return (0);
	ft_putendl("----------------------");
	ft_intendl(args->l);
	ft_intendl(args->R);
	ft_intendl(args->a);
	ft_intendl(args->r);
	ft_intendl(args->t);
	free(args);
	return (1);
}
