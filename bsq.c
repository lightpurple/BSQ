/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euhong <euhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 19:18:46 by euhong            #+#    #+#             */
/*   Updated: 2021/03/10 20:20:39 by euhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	bsq(int fd)
{
	char	**map;
	int		**copy_map;
	t_xy	loc;
	t_info	info;

	if (check_err(fd, map))
	{
		// print_err();
	}
	map_cpy(copy_map, map);
	init_map(copy_map, &info);
	fill_map(copy_map, &loc);
	finish_map(map, info, loc);
	print_map(map);
}
