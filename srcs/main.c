/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcallens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 19:02:36 by tcallens          #+#    #+#             */
/*   Updated: 2018/10/01 10:22:48 by tcallens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		main(int ac, char **av)
{
	t_args	*args;
	int		plus;
	int		ret;

	plus = 0;
	if ((args = ft_init_args(av)) == NULL)
		return (0);
	if (ft_first_files(av, ac) == 0)
		ft_ls_dir(ft_strjoin(".", ""), args, 1);
	else
	{
		ret = find_files(&av[ft_first_files(av, ac)], args);
	//	if (args->notfile == 1)
	//		plus = 1;
		find_dir(&av[ft_first_files(av, ac)], args, ft_nbr_files(av) + plus, ret);
	}
	free(args);
	while (1);
	return (1);
}
