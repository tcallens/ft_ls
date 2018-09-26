/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcallens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 16:36:42 by tcallens          #+#    #+#             */
/*   Updated: 2018/09/26 04:46:28 by tcallens         ###   ########.fr       */
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

/*
** structs
*/

typedef struct stat		t_stats;

typedef struct		s_info
{
	int				size;
	int				type;
}					t_info;


typedef struct			s_args
{
	int		l;
	int		R;
	int		a;
	int		r;
	int		t;
}						t_args;

typedef struct		s_file
{
	char			*path;
	char			*name;
	char			*perms;
	int				links;
	char			*linkpath;
	char			*user;
	char			*group;
	char			*size;
	long			timestamp;
	long			ntimestamp;
	long			blocks;
	int				error;
}					t_file;

/*
 ** fonctions
 */

void					ft_rec(char *name, t_args *args, int ind);
int						ft_file_link(char *name);
void					free_file(t_file *dir);
void					free_dir(t_file **dir, int size);
t_args					*ft_init_args(char **av);
int						ft_options(char *str, t_args *args);
int						correct_args(char *str);
void					ft_error_options(void);
void					ft_not_file(char *str);
int						ls(char *name, t_args *args, int fichier);
int						ft_first_files(char **av, int ac);
void					find_files(char **av);
void					find_dir(char **av, t_args *args, int dir);
void					ft_print_fichier(char *name);
void					ft_print_dossier(char *name, t_args *args, int ind);
int						correct_args_free(char *str);
t_file					**ft_init_dir(int nbr, t_file **dir);
void					ft_ls_dir(char *name, t_args *args, int dir);
int						ft_nbr_files(char **av);
void					ft_print_dir_l(t_file **file, int ind, char *name, int nbr, t_args *args);
t_file					*fill_stats(t_file *dir, char *name, char *path, t_stats *stats);
t_file					**bef_fill_dir(char *name, t_info info);
t_file					**fill_dir(char *name, char *path, t_info info, t_file **file);
int						ft_dirlen(char *name);
char					*find_link(char *path, char *file);
char					*find_group(struct stat *stats);
char					*find_user(struct stat *stats);
int						find_error(char *file);
char					*find_modes(struct stat *file, char *ret);
void					print_blocks(t_file **dir, int size, t_args *options);
long					get_timestamp(char *dir);
int						next_dir_offset(char **av);
char					*find_majmin(struct stat *stats);





#endif
