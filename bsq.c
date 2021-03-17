/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euhong <euhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 19:18:46 by euhong            #+#    #+#             */
/*   Updated: 2021/03/17 19:37:18 by euhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

t_info	g_info;

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

t_map	*read_map(int fd)
{
	t_map	*map;
	char	buf[BUF_SIZE];
	char	*line;
	int		size;
	int		total;

	line = NULL;
	total = 0;
	while ((size = read(fd, buf, BUF_SIZE - 1)) > 0)
	{
		buf[BUF_SIZE - 1] = '\0';
		if (!(line = ft_extend(line, total, buf)))
			return (NULL);
		total += size;
	}
	if (total != 0 && line[total - 1] != '\n')
	{
		free(line);
		return (NULL);
	}
	if (init_rows(line) || !(map = ft_split(line)))
		return (NULL);
	return (map);
}

void	bsq(t_map *map)
{
	t_xy	loc;

	loc.max = 0;
	loc.x = 0;
	loc.y = 0;
	// map을 copy_map에 malloc하면서 cpy까지
	if (map_cpy(map))
		return ;
	change_map(map); //행,열 1번째를 1로 채우고 벽을 0을로 바꾸는거 까지
	loc = init_loc(map);
	fill_map(map, &loc);  // 알고리즘거쳐서 x,y값, max값 구하기
	finish_map(map, loc); // 원본 맵에 fill 채우기
	print_map(map);
	dobby_is_free(map); // copy_map, map free시키기
}
