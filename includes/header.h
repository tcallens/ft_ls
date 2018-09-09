/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcallens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 16:36:42 by tcallens          #+#    #+#             */
/*   Updated: 2018/09/09 04:03:53 by tcallens         ###   ########.fr       */
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
int						ls(char *name, t_args *args, int fichier);
int						ft_nbr_files(char **av, int ac);
void					find_names(char **av, t_args *args);
void					ft_print_fichier(char *name);
void					ft_print_dossier(char *path, char *name, t_args *args);


#endif
