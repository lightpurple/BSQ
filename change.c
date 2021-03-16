/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euhong <euhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 20:39:00 by euhong            #+#    #+#             */
/*   Updated: 2021/03/17 01:46:38 by dookim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

extern t_info	g_info;

void			change_first_row_col(t_map *map)
{
	int idx;

	idx = 0;
	while (map->line[idx] != '\0')
	{
		if (map->line[idx] == g_info.emt)
			map->cp_line[idx] = 1;
		if (map->line[idx] == g_info.block)
			map->cp_line[idx] = 0;
		idx++;;
	}
	idx = 0;
	while (map[idx].line != NULL)
	{
		if (*map[idx].line == g_info.emt)
			*map[idx].cp_line = 1;
		if (*map[idx].line == g_info.block)
			*map[idx].cp_line = 0;
		idx++;
	}
}

void			change_rest(t_map *map)
{
	int	row;
	int	col;

	row = 1;
	while (map[row].line != NULL)
	{
		col = 1;
		while (map[row].cp_line[col] != LINE_END)
		{
			if (map[row].line[col] == g_info.block)
				map[row].cp_line[col] = 0;
			col++;
		}
		row++;
	}
}

void			change_map(t_map *map)
{
	change_first_row_col(map);
	change_rest(map);
}
