/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euhong <euhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 19:18:46 by euhong            #+#    #+#             */
/*   Updated: 2021/03/17 17:12:27 by euhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

t_info	g_info;

void	bsq(t_map *map)
{
	t_xy	loc;

	loc.max = 0;
	loc.x = 0;
	loc.y = 0;
	//bsq들어가서 errmsg를 출력해야하는 케이스가 있나??
	map_cpy(map); // map을 copy_map에 malloc하면서 cpy까지
	change_map(map); //행,열 1번째를 1로 채우고 벽을 0을로 바꾸는거 까지
	loc = init_loc(map);
	fill_map(map, &loc);  // 알고리즘거쳐서 x,y값, max값 구하기
	finish_map(map, loc); // 원본 맵에 fill 채우기
	print_map(map);
	dobby_is_free(map); // copy_map, map free시키기
}

void	only_ac(void)
{
	t_map	*map;

	if (!(map = read_map(0)))
	{
		print_err(ERR_MSG);
		return ;
	}
	bsq(map);
}

void	many_ac(int ac, char **av)
{
	int		i;
	int		fd;
	t_map	*map;

	i = 0;
	while (++i < ac)
	{
		fd = open(av[i], O_RDONLY);
		if (!(map = read_map(fd)))
		{
			print_err(ERR_MSG);
			close(fd);
			return ;
		}
		bsq(map);
		close(fd);
	}
}
