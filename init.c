/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euhong <euhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 19:56:52 by euhong            #+#    #+#             */
/*   Updated: 2021/03/15 18:03:49 by dookim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	change_first_row_col(t_map *map)
{
	while (*map.line != '\0')
	{
		if (*map.line == info.emt)
			*map.cp_line = 1;
		if (*map.line == info.block)
			*map.cp_line = 0;
		map.line++;
		map.cp_line++;
	}	
	while (map.line != NULL)
	{
		if (*map.line == info.emt)
			*map.cp_line = 1;
		if (*map.line == info.block)
			*map.cp_line = 0;
		map++;
	}
}

void	change_rest(t_map *map)
{
	int idx;

	while (*map.line  != NULL)
	{
		idx = 1;
		while (map.cp_line[idx] != LINE_END)
		{
			if (*map.line == info.block)
				*map.cp_line = 0;
			idx++;
		}
		map++;
	}
}

void	change_map(t_map *map)
{
	change_first_row_col(map);
	change_rest(map);
}
