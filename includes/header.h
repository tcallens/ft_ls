/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcallens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 16:36:42 by tcallens          #+#    #+#             */
/*   Updated: 2018/10/02 06:33:50 by tcallens         ###   ########.fr       */
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

typedef struct stat	t_stats;

typedef struct		s_pad
{
	int				directory_number;
	int				perms;
	int				links;
	int				user;
	int				group;
	int				size;
	int				timestamp;
	int				name;
	int				ind;
	int				nbr;
}					t_pad;

typedef struct		s_info
{
	int				size;
	int				type;
	int				ind;
	int				afhr;
}					t_info;

typedef struct		s_args
{
	int				l;
	int				rec;
	int				a;
	int				r;
	int				t;
	int				nbrfiles;
	int				notfile;
}					t_args;

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

t_args				*ft_i_a_help(char **av);
int					find_files_help(int b, t_args *ar, char **av, t_pad p);
void				ft_perm_denied(int nbr, char *name);
void				ft_free_help(char *name, int *tab);
int					*ft_fill_int(int nbr);
char				**ft_sort_tab(char **tab, int nbr);
t_file				**ft_sort_as(t_file **tab, int nbr);
t_file				**fill_files(int nbr, char **av);
int					ft_print_files(t_file **f, int nbr, t_args *ar, t_pad pad);
void				ft_print_name(char *str);
void				perm_denied(char *file, int size);
void				not_permitted(t_file **file, t_info info);
void				ft_print_file_l(t_file *file, t_pad pad);
int					ft_nbrlen(int a);
int					ft_if(int v1, int v2);
t_pad				ft_init_pad(void);
t_pad				ft_fill_pad(t_pad pad, int n, t_file **file, t_args *args);
void				ft_print_b(int nbr);
void				ft_print_link(char *str);
void				ft_print_time(long a);
void				ft_help_rec(t_args *ar, char **tab, t_info i, int *intt);
int					ft_cmp_time(char *s1, char *s2, long c, long d);
t_file				**ft_range_t_dir(t_file **tab, int nbr, t_args *args);
char				**ft_range_t(char **tab, int nbr, t_args *args);
int					ft_files(char **av);
void				ft_print_double(char **str);
void				ft_rec(char *n, t_args *args, t_info inf, t_file **tabdir);
t_file				**ft_range_r_dir(t_file **tab, int nbr, t_args *args);
char				**ft_range_r(char **tab, int nbr, t_args *args);
int					ft_file_link(char *name);
void				free_file(t_file *dir);
void				free_dir(t_file **dir, int size);
t_args				*ft_init_args(char **av);
int					ft_options(char *str, t_args *args);
int					correct_args(char *str);
void				ft_error_options(char option);
t_args				*ft_not_file(char *str, t_args *args);
int					ls(char *name, t_args *args, int fichier);
int					ft_first_files(char **av, int ac);
int					find_files(char **av, t_args *args);
void				find_dir(char **av, t_args *args, int dir, int ret);
int					correct_args_free(char *str);
t_file				**ft_init_dir(int nbr, t_file **dir);
void				ft_ls_dir(char *name, t_args *args, int dir);
int					ft_nbr_files(char **av);
t_file				**ft_p_dir_l(t_file **f, char *n, t_args *ar, t_pad p);
t_file				*fill_stats(t_file *d, char *n, char *pat, t_stats *stats);
t_file				**bef_fill_dir(char *name, t_info info);
t_file				**fill_dir(char *n, char *pat, t_info info, t_file **file);
int					ft_dirlen(char *name);
char				*find_link(char *path);
char				*find_group(struct stat *stats);
char				*find_user(struct stat *stats);
int					find_error(char *file);
char				*find_modes(struct stat *file, char *ret);
void				print_blocks(t_file **dir, int size, t_args *options);
long				get_timestamp(char *dir);
int					next_dir_offset(char **av);
char				*find_majmin(struct stat *stats);
char				**ft_find_tab(int ind, char **av, t_args *args);
void				ft_double_point(char *str);

#endif
