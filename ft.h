/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euhong <euhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 17:06:06 by euhong            #+#    #+#             */
/*   Updated: 2021/03/18 10:10:16 by euhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include "struct.h"
# define BUF_SIZE 3000000
# define SUCCESS 0
# define FAIL 1
# define LINE_END -1
# define ERR_MSG "map error\n"

void			bsq(t_map *map);
t_map			*read_map(int fd);
t_map			*ft_split(char *line);
int				init_rows(char *line, int total);
char			*ft_extend(char *line, int line_len, char *buf, int b_size);
void			dobby_is_free(t_map *map);
void			free_line(t_map *map, int idx);
void			free_cp_line(t_map *map, int idx);
void			only_ac(void);
void			many_ac(int ac, char **av);
int				ft_nl_len(char *str);
int				ft_strcpy(char **copy, char *line);
int				ft_strlen(char *str);
void			ft_strncat(char **dest, char *src, int n);
void			fill_map(t_map *map, t_xy *loc);
void			finish_map(t_map *map, t_xy loc);
void			print_err(char *str);
void			print_map(t_map *map);
int				fill_info(char *line, int total);
int				map_cpy(t_map *map);
int				*ft_strdup_to_int(char *src);
void			change_map(t_map *map);
t_xy			init_loc(t_map *map);
int				ft_str_is_printable(char *str);
int				linefeed_error_check(char *line, int total);
int				map_error_check(t_map *map);
int				is_in_info(char *line);
int				is_c_in_str(char c, char *str);

#endif
