/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euhong <euhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 15:57:51 by euhong            #+#    #+#             */
/*   Updated: 2021/03/17 18:27:52 by euhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

extern t_info	g_info;

void			dobby_is_free(t_map *map)
{
	int	i;

	i = -1;
	while (++i <= g_info.row_len)
	{
		free(map[i].line);
		free(map[i].cp_line);
	}
	free(map);
	free(g_info.rows);
}

void			free_line(t_map *map, int idx)
{
	int	i;

	i = -1;
	while (++i < idx)
		free(map[i].line);
	free(map);
	free(g_info.rows);
}

void			free_cp_line(t_map *map, int idx)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (++i < idx)
		free(map[i].cp_line);
	while (++j <= g_info.row_len)
		free(map[j].line);
	free(map);
	free(g_info.rows);
}
