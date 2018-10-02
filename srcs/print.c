/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcallens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/09 02:52:03 by tcallens          #+#    #+#             */
/*   Updated: 2018/10/02 10:47:26 by tcallens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		ft_double_point(char *str)
{
	ft_putstr(str);
	ft_putendl(":");
}

void		ft_print_name(char *str)
{
	ft_putstr(str);
	ft_putstr(" ");
}

void		ft_print_time(long a)
{
	char	*ret;
	time_t	today;

	today = time(NULL);
	if ((ret = ctime(&a)) == NULL)
		return ;
	if (today - a <= 15778800 && today - a > 0)
		ret[16] = '\0';
	else
	{
		ret[11] = ' ';
		ret[12] = ret[20];
		ret[13] = ret[21];
		ret[14] = ret[22];
		ret[15] = ret[23];
		ret[16] = '\0';
	}
	ft_putstr(ret + 4);
}
