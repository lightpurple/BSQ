/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euhong <euhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 17:06:06 by euhong            #+#    #+#             */
/*   Updated: 2021/03/12 22:29:00 by euhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# define BUF_SIZE 30

void			bsq(int fd1, int fd2);
int				check_err(int fd, char **map);
void			change_map(int **copy_map, t_info *info);
void			fill_map(int **copy_map, t_xy *loc);
void			map_cpy(int **copy_map, char **map);
void			finish_map(char **map, t_info info, t_xy loc);
void			print_err(void);
void			print_map(char **map);
int				ft_file_size(int fd);
char			*read_stdin(void);
void			dobby_is_free(void **map, t_info info);
int				ft_atoi(char *rows);
void			init_malloc(char **map, int rows, int cols);
void			ft_fail_malloc(char **map);
int				ft_strlen(char *str);
char			*ft_strcpy(char *dest, char *src);
int				ft_is_c_in_str(char c, char *str);

typedef struct	s_info
{
	char		*rows;
	char		emt;
	char		block;
	char		fill;
}				t_info;

typedef struct	s_xy
{
	int			max;
	int			x;
	int			y;
}				t_xy;

#endif
