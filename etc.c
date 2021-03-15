/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   etc.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euhong <euhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 20:40:13 by euhong            #+#    #+#             */
/*   Updated: 2021/03/15 20:21:26 by dookim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

extern t_info info;

void	finish_map(t_map *map, t_xy loc)
{
	int row;
	int col;
	int y_init;

	row = loc.x - loc.max + 1;
	col = loc.y - loc.max + 1;
	y_init = col;
	while (row <= loc.x)
	{
		col = y_init;
		while (col <= loc.y)
			map[row].line[col++] = info.fill;
		row++;
	}
}

int	ft_strlen(char *str)
{
	char *str_st;

	str_st = str;
	while (*str_st)
		str_st++;
	return (str_st - str);
}

int	*ft_strdup_to_int(char *src)
{
	int		index;
	int	*dest;

	index = 0;
	if ((dest = (int *)malloc(sizeof(int) * (info.col_len + 1))) == NULL)
		return (0);
	while (src[index])
		dest[index] = (int)(src[index++]);
	dest[index] = LINE_END;
	return (dest);
}

void	map_cpy(t_map *map)
{
	int idx;

	idx = 0;
	while (map[idx].line != NULL)
		map[idx].cp_line = ft_strdup_to_int(map[idx++].line);
}

int		ft_atoi(void)
{
	int res;
	int idx;

	idx = 0;
	while (info.rows[idx] >= '0' && info.rows[idx] <= '9')
		idx++;
	if (idx != ft_strlen(info.rows))
		return (FAIL);
	res = 0;
	while (*info.rows >= '0' && *info.rows <= '9')
		res = 10 * res + *info.rows++ - '0';
	info.row_len = res;
	return (SUCESS);
}
