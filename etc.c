/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   etc.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euhong <euhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 20:40:13 by euhong            #+#    #+#             */
/*   Updated: 2021/03/15 20:48:59 by euhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

extern t_info	g_info;

void			map_cpy(t_map *map)
{
	int	idx;

	idx = -1;
	while (map[++idx].line != NULL)
		map[idx].cp_line = ft_strdup_to_int(map[idx].line);
}

int				ft_atoi(void)
{
	int	res;
	int	idx;

	idx = 0;
	while (g_info.rows[idx] >= '0' && g_info.rows[idx] <= '9')
		idx++;
	if (idx != ft_strlen(g_info.rows))
		return (FAIL);
	res = 0;
	while (*g_info.rows >= '0' && *g_info.rows <= '9')
		res = 10 * res + *g_info.rows++ - '0';
	g_info.row_len = res;
	return (SUCCESS);
}
