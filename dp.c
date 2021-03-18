/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dp.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euhong <euhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 21:05:26 by euhong            #+#    #+#             */
/*   Updated: 2021/03/18 11:04:46 by euhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

extern t_info	g_info;

t_xy			*compare_xy(int curr, int row, int col, t_xy *loc)
{
	if (curr > loc->max)
	{
		loc->max = curr;
		loc->x = col;
		loc->y = row;
	}
	if (curr == loc->max &&
		(((col - curr + 1) * (col - curr + 1) +
			(row - curr + 1) * (row - curr + 1)) <
			((loc->x - curr + 1) * (loc->x - curr + 1) +
			(loc->y - curr + 1) * (loc->y - curr + 1))))
	{
		loc->x = col;
		loc->y = row;
	}
	return (loc);
}

void			fill_curr_xy(t_map *map, int row, int col, t_xy *loc)
{
	int	mini;
	int	leftup;
	int	up;
	int	left;
	int	curr;

	leftup = map[row - 1].cp_line[col - 1];
	up = map[row - 1].cp_line[col];
	left = map[row].cp_line[col - 1];
	mini = leftup;
	if (mini > up)
		mini = up;
	if (mini > left)
		mini = left;
	curr = mini + 1;
	map[row].cp_line[col] = curr;
	loc = compare_xy(curr, row, col, loc);
}

void			fill_map(t_map *map, t_xy *loc)
{
	int	row;
	int	col;

	if (g_info.row_len == 1 || g_info.col_len == 1)
		return ;
	row = 1;
	while (map[row].line != NULL)
	{
		col = 1;
		while (map[row].cp_line[col] != LINE_END)
		{
			if (map[row].cp_line[col] == 0)
			{
				col++;
				continue ;
			}
			fill_curr_xy(map, row, col, loc);
			col++;
		}
		row++;
	}
}

void			finish_map(t_map *map, t_xy loc)
{
	int	row;
	int	col;
	int	x_init;

	row = loc.y - loc.max + 1;
	col = loc.x - loc.max + 1;
	x_init = col;
	while (row <= loc.y)
	{
		col = x_init;
		while (col <= loc.x)
			map[row].line[col++] = g_info.fill;
		row++;
	}
}
