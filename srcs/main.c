/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcallens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 19:02:36 by tcallens          #+#    #+#             */
/*   Updated: 2018/09/11 04:18:45 by tcallens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		main(int ac, char **av)
{
	t_args	*args;

	if ((args = ft_init_args(av)) == NULL)
		return (0);
	if (ft_nbr_files(av, ac) == 0)
		ft_ls_dir("./", args);
	else
	{
		find_files(&av[ft_nbr_files(av, ac)]);
		find_dir(&av[ft_nbr_files(av, ac)], args);
	}
	free(args);
	return (1);
}
