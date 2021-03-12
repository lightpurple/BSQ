/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euhong <euhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 19:18:46 by euhong            #+#    #+#             */
/*   Updated: 2021/03/12 22:27:04 by euhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
t_info	info;

void	bsq(int fd1, int fd2)
{
	char	**map;
	int		**copy_map;
	t_xy	loc;

	if (check_err(fd, map)) // 인자로 주어진 파일을 읽으면서 error체크와 동시에 map에 저장
	{
		print_err();
	}
	map_cpy(copy_map, map); // map을 copy_map에 malloc하면서 cpy까지
	change_map(copy_map, &info); //행,열 1번째를 1로 채우고 벽을 0을로 바꾸는거 까지
	fill_map(copy_map, &loc); // 알고리즘거쳐서 x,y값, max값 구하기
	finish_map(map, info, loc); // 원본 맵에 fill 채우기
	print_map(map);
	dobby_is_free(copy_map, info); // copy_map, map free시키기
}
