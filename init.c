/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euhong <euhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 19:56:52 by euhong            #+#    #+#             */
/*   Updated: 2021/03/18 02:10:25 by dookim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

extern t_info	g_info;

int				map_cpy(t_map *map)
{
	int	idx;

	idx = 0;
	while (map->line[idx])
		idx++;
	g_info.col_len = idx;
	idx = -1;
	while (map[++idx].line != NULL)
		if (!(map[idx].cp_line = ft_strdup_to_int(map[idx].line)))
		{
			free_cp_line(map, idx);
			return (FAIL);
		}
	return (SUCCESS);
}

int				init_rows(char *line, int total)
{
	int	i;

	i = -1;
	if (line == NULL)
		return (FAIL);
	if (!(g_info.rows = (char *)malloc(ft_nl_len(line) + 1)))
	{
		free(line);
		return (FAIL);
	}
	while (line[++i] != '\n')
		g_info.rows[i] = line[i];
	g_info.rows[i] = '\0';
	if (fill_info(line, total))
	{
		free(line);
		return (FAIL);
	}
	return (SUCCESS);
}

t_xy			init_loc_search_x0(t_map *map)
{
	t_xy	loc;
	int		col;

	loc.max = 0;
	loc.x = g_info.col_len;
	loc.y = g_info.row_len;
	col = 0;
	while (map->cp_line[col] != LINE_END)
	{
		if (map->cp_line[col] == 1)
		{
			loc.max = 1;
			loc.y = 0;
			loc.x = col;
			break ;
		}
		col++;
	}
	return (loc);
}

t_xy			init_loc_search_0y(t_map *map, t_xy loc)
{
	int	row;

	row = 0;
	while (map[row].line != NULL)
	{
		if (*map[row].cp_line == 1 && row < loc.y)
		{
			loc.max = 1;
			loc.y = row;
			loc.x = 0;
			break ;
		}
		row++;
	}
	return (loc);
}

t_xy			init_loc(t_map *map)
{
	t_xy	loc;

	loc = init_loc_search_x0(map);
	loc = init_loc_search_0y(map, loc);
	return (loc);
}
