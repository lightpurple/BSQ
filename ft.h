/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euhong <euhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 17:06:06 by euhong            #+#    #+#             */
/*   Updated: 2021/03/17 17:48:15 by euhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <stdio.h>//얘 지우기
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include "struct.h"
# define BUF_SIZE 300000
# define SUCCESS 0
# define FAIL 1
# define LINE_END -1
# define ERR_MSG "map error\n"

void			bsq(t_map *map);
t_map			*read_map(int fd);
t_map			*ft_split(char *line);
int				init_rows(char *line);
char			*ft_extend(char *line, int line_len, char *buf);
void			dobby_is_free(t_map *map);
void			free_line(t_map *map, int idx);
void			free_cp_line(t_map *map, int idx);
void			only_ac(void);
void			many_ac(int ac, char **av);
int				ft_strlen(char *str);
void			ft_strcat(char **dest, char *src);
void			fill_map(t_map *map, t_xy *loc);
void			finish_map(t_map *map, t_xy loc);
void			print_err(char *str);
void			print_map(t_map *map);


int				ft_atoi(void);
int				check_deserve(char c);
int				fill_info(char *line);
void			change_map(t_map *map);
void			map_cpy(t_map *map);
t_xy			init_loc(t_map *map);
int				*ft_strdup_to_int(char *src);
void			init_malloc(char **map, int rows, int cols);
void			ft_fail_malloc(char **map);
int				ft_is_c_in_str(char c, char *str);

#endif
