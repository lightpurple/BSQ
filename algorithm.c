/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euhong <euhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 21:05:26 by euhong            #+#    #+#             */
/*   Updated: 2021/03/15 20:15:57 by dookim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

extern t_info	info;

t_xy	init_loc_search_x0(t_map *map)
{
	t_xy loc;
	int col;

	loc.map = 0;
	loc.x = info.col_len;
	loc.y = info.row_len;
	col = 0;
	while (map.cp_line[col] != LINE_END)
	{
		if (map.cp_line[col] == 1)
		{
			loc.map = 1;
			loc.y = 0;
			loc.x = col;
			break ;
		}
		col++;
	}
	return (loc);
}

t_xy	init_loc_search_0y(t_map *map, t_xy loc)
{
	int row;

	row = 0;
	while (*map[row].line != NULL)
	{
		if (*map[row].cp_line == 1 && row < loc.x)
		{
			loc.map = 1;
			loc.y = row;
			loc.x = 0;
			break ;
		}
		row++;
	}
	return (loc);
}

t_xy	init_loc(t_map *map)
{
	t_xy loc;
	int row;

	loc = init_loc_search_x0(map);
	loc = init_loc_search_0y(map, loc);
	return (loc);
}

t_xy	*compare_xy(int curr, int row, int col, t_xy *loc)
{
	if (curr > loc.max)
	{
		loc.max = curr;
		loc.x = col;
		loc.y = row;
	}
	if (curr == loc.max && ((col * col + row * row) < (loc.x * loc.x + loc.y * loc.y)))
	{
		loc.x = col;
		loc.y = row;
	}
	return (loc);
}

void	fill_curr_xy(t_map *map, int row, int col, t_xy *loc)
{
	int mini;
	int leftup;
	int up;
	int left;
	int curr;

	leftup = map[row - 1].cp_line[col - 1];
	up = map[row - 1].cp_line[col];
	left = map[row].cp_line[col - 1];
	curr = map[row].cp_line[col];
	mini = leftup;
	if (mini > up)
		mini = up;
	if (mini > left)
		mini = left;
	curr = mini + 1;
	loc = compare_xy(curr, row, col, loc)
}




void	fill_map(t_map *map, t_xy *loc)
{
	int row;
	int col;
	
	if (info.row_len == 1 || info.col_len == 1)
		return ;
	row = 1;
	while (map[row].line  != NULL)
	{
		col = 1;
		while (map[row].cp_line[col] != LINE_END)
		{
			if (map[row].cp_line[col] == 0)
				continue;
			fill_curr_xy(map, row, col, loc);
			col++;
		}
		row++;
	}

}
