/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   etc.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euhong <euhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 20:40:13 by euhong            #+#    #+#             */
/*   Updated: 2021/03/12 20:59:39 by dookim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

extern t_info info;

void	finish_map(char **map, t_info info, t_xy loc)
{
	int x_idx;
	int y_idx;
	int y_init;

	x_idx = loc.x - loc.max + 1;
	y_idx = loc.y - loc.max + 1;
	y_init = y_idx;
	while (x_idx <= loc.x)
	{
		y_idx = y_init;
		while (y_idx <= loc.y)
			map[x_idx][y_idx++] = info.fill;
		x_idx++;
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

char	*ft_strcpy(char *dest, char *src)
{
	int index;

	index = 0;
	while (src[index] != '\0')
	{
		dest[index] = src[index];
		index++;
	}
	dest[index] = '\0';
	return (dest);
}

void	map_cpy(int **copy_map, char **map)
{
	int rows;
	int cols;

	rows = ft_atoi(info.rows);
	cols = ft_strlen(map[0]);
	if ((copy_map = init_malloc(copy_map, rows, cols)) = NULL)
		exit(1);
	while (rows--)
		ft_strcpy(copy_map[rows], map[rows]);
}

int		ft_atoi(char *str)
{
	int res;

	res = 0;
	while (*str >= '0' && *str <= '9')
		res = 10 * res + *str - '0';
	return (res);
}
