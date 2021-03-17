/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dookim <dookim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 13:02:30 by dookim            #+#    #+#             */
/*   Updated: 2021/03/17 18:32:43 by euhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include "struct.h"

extern t_info	g_info;

int				map_col_check(t_map *map)
{
	int	idx;
	int	col_len;

	idx = -1;
	while (map[++idx].line != NULL)
	{
		col_len = ft_strlen(map[idx].line);
		if (ft_strlen(map[0].line) != col_len || is_in_info(map[idx].line))
		{
			free_line(map, g_info.row_len);
			return (FAIL);
		}
	}
	return (SUCCESS);
}

int				map_row_check(t_map *map)
{
	int	count;

	count = 0;
	while (map[count].line)
		count++;
	if (count != g_info.row_len)
	{
		free_line(map, g_info.row_len);
		return (FAIL);
	}
	return (SUCCESS);
}

int				map_error_check(t_map *map)
{
	if (map_col_check(map))
		return (FAIL);
	if (map_row_check(map))
		return (FAIL);
	return (SUCCESS);
}
