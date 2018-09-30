/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcallens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/09 02:52:03 by tcallens          #+#    #+#             */
/*   Updated: 2018/09/30 02:18:53 by tcallens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void				ft_print_name(char *str)
{
	ft_putstr(str);
	ft_putstr(" ");
}

void				ft_print_time(long a)
{
	char *ret;

	if ((ret = ctime(&a)) == NULL)
		return ;
	ret[16] = '\0';
	ft_putstr(ret + 4);
}
