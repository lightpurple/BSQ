/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euhong <euhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 17:06:06 by euhong            #+#    #+#             */
/*   Updated: 2021/03/15 21:48:14 by euhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include "struct.h"
# define BUF_SIZE 30
# define SUCCESS 0
# define FAIL 1
# define LINE_END -1
# define ERR_MSG "map error\n"

void			bsq(int fd1, int fd2);
int				ft_atoi(void);
int				check_err(int fd1, int fd2, t_map **map);
void			change_map(t_map *map);
void			fill_map(t_map *map, t_xy *loc);
void			map_cpy(t_map *map);
t_xy			init_loc(t_map *map);
int				*ft_strdup_to_int(char *src);
void			finish_map(t_map *map, t_xy loc);
int				init_map(t_map *map, int rd_fd);
int				dup_line(int rd_fd, char *line);
void			print_err(char *str);
void			print_map(t_map *map);
int				ft_file_size(int fd);
char			*read_stdin(void);
void			dobby_is_free(t_map *map);
void			init_malloc(char **map, int rows, int cols);
void			ft_fail_malloc(char **map);
int				ft_strlen(char *str);
char			*ft_strcpy(char *dest, char *src);
int				ft_is_c_in_str(char c, char *str);
void			only_ac(void);
void			many_ac(int ac, char **av);

#endif
