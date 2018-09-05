/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcallens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 16:36:42 by tcallens          #+#    #+#             */
/*   Updated: 2018/09/05 22:18:22 by tcallens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <unistd.h>
# include <sys/stat.h>
# include <stdio.h>
# include <time.h>
# include <errno.h>
# include <string.h>
# include <sys/types.h>
# include <pwd.h>
# include <uuid/uuid.h>
# include <grp.h>
# include <dirent.h>
# include "../libft/libft.h"

typedef struct stat		t_stats;

typedef struct			s_args
{
	int		l;
	int		R;
	int		a;
	int		r;
	int		t;
}						t_args;

/*
** fonctions
*/

t_args					*ft_init_args(char **av);
int						ft_options(char *str, t_args *args);
int						correct_args(char *str);
void					ft_error_options(void);
void					ft_not_file(char *str);



#endif
