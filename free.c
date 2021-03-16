/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euhong <euhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 15:57:51 by euhong            #+#    #+#             */
/*   Updated: 2021/03/16 17:40:08 by euhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

extern t_info g_info;

void	dobby_is_free(t_map *map)
{
	int i;

	i = -1;
	while (++i <= g_info.row_len)
	{
		free(map[i].line);
		free(map[i].cp_line);
	}
	free(map);
	free(g_info.rows);
}

void	free_line(t_map *map, int idx)
{
	int i;

	i = -1;
	while (++i < idx)
		free(map[i].line);
	free(map);
	free(g_info.rows);
}
