/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euhong <euhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 16:43:15 by euhong            #+#    #+#             */
/*   Updated: 2021/03/17 17:08:00 by euhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

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
	// line마지막 \0인지 확인, 중간에 빈 행있는지
	if (init_rows(line) || !(map = ft_split(line)))
		return (NULL);
	return (map);
}
