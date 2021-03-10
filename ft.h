/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euhong <euhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 17:06:06 by euhong            #+#    #+#             */
/*   Updated: 2021/03/10 20:22:20 by euhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

void			bsq(int fd);
int				check_err(int fd, char **map);
void			init_map(int **copy_map, t_info *info);
void			fill_map(int **copy_map, t_xy *loc);
void			map_cpy(int **map_cpy, char **map);
void			finish_map(char **map, t_info info, t_xy loc);
void			print_map(char **map);

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
