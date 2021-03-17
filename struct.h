/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euhong <euhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 16:53:11 by euhong            #+#    #+#             */
/*   Updated: 2021/03/17 10:49:08 by dookim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct	s_info
{
	char		*rows
	int			row_len;
	int			col_len;
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

typedef struct	s_map
{
	char		*line;
	int			*cp_line;
}				t_map;

#endif
