/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euhong <euhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 19:18:46 by euhong            #+#    #+#             */
/*   Updated: 2021/03/17 21:43:04 by euhong           ###   ########.fr       */
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
			continue ;
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
	buf[0] = '\0';
	while ((size = read(fd, buf, BUF_SIZE - 1)) > 0)
	{
		buf[BUF_SIZE - 1] = '\0';
		if (!(line = ft_extend(line, total, buf, size)))
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
	if (map_cpy(map))
		return ;
	change_map(map);
	loc = init_loc(map);
	fill_map(map, &loc);
	finish_map(map, loc);
	print_map(map);
	dobby_is_free(map);
}
