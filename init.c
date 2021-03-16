/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euhong <euhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 19:56:52 by euhong            #+#    #+#             */
/*   Updated: 2021/03/16 15:16:14 by euhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

extern t_info	g_info;

int	dup_line(int rd_fd, char *line)
{
	int	i;

	i = -1;
	line = (char *)malloc(sizeof(char) * (g_info.col_len + 1));
	while (read(rd_fd, &line[++i], 1))
	{
		if (check_deserve(line[i]))
			return (FAIL);
		if (i == g_info.col_len)
		{
			if (line[i] == '\n' || line[i] == '\0')
				break ;
			return (FAIL);
		}
	}
	line[i] = '\0';
	return (SUCCESS);
}

int				init_map(t_map **map, int rd_fd)
{
	int		i;
	char	tmp;

	i = -1;
	*map = (t_map *)malloc(sizeof(t_map) * (g_info.row_len + 1));
	map[g_info.row_len]->line = NULL;
	while (read(rd_fd, &tmp, 1))
		if (tmp == '\n')
			break ;
	while (++i < g_info.row_len)
		if (dup_line(rd_fd, map[i]->line))
		{
			dobby_is_free(*map);
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
		if (*map[row].cp_line == 1 && row < loc.x)
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
