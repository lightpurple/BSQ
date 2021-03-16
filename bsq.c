/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euhong <euhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 19:18:46 by euhong            #+#    #+#             */
/*   Updated: 2021/03/15 23:49:16 by euhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

t_info	g_info;

void	bsq(int cnt_fd, int rd_fd)
{
	int		err;
	t_map	*map;
	t_xy	loc;

	// 인자로 주어진 파일을 읽으면서 error체크와 동시에 map에 저장
	map = check_err(cnt_fd, rd_fd, &err);
	if (err)
	{
		print_err(ERR_MSG);
		return ;
	}
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
	int		cnt_fd;
	int		rd_fd;
	char	*f_name;

	f_name = read_stdin();
	cnt_fd = open(f_name, O_RDONLY);
	rd_fd = open(f_name, O_RDONLY);
	bsq(cnt_fd, rd_fd);
	free(f_name);
	close(cnt_fd);
	close(rd_fd);
}

void	many_ac(int ac, char **av)
{
	int	i;
	int	cnt_fd;
	int	rd_fd;

	i = 0;
	while (++i < ac)
	{
		cnt_fd = open(av[i], O_RDONLY);
		rd_fd = open(av[i], O_RDONLY);
		bsq(cnt_fd, rd_fd);
		close(cnt_fd);
		close(rd_fd);
	}
}
