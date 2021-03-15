/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euhong <euhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 19:32:18 by euhong            #+#    #+#             */
/*   Updated: 2021/03/15 20:08:12 by euhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

extern t_info info; // malloc하기

//유효하지 않은 지도이면 1을 리턴 아닐경우 0리턴
//

int	check_deserve(char c)
{
	if (c != info.emt || c != info.block || c != info.fill)
		return (FAIL);
	return (SUCCESS);
}

int	cnt_col(int cnt_fd)
{
	int		cnt;
	char	c;

	cnt = 0;
	while (read(cnt_fd, &c, 1))
	{
		if (c == '\n' || c == '\0')
			break ;
		cnt++;
	}
	if (cnt < 1 || c != '\n' || c != '\0')
		return (FAIL);
	info.col_len = cnt;
	return (SUCCESS);
}

int	fill_info(char *buf, int len)
{
	int	i;

	i = -1;
	info.emt = buf[len - 3];
	info.block = buf[len - 2];
	info.fill = buf[len - 1];
	if (info.emt == info.fill || info.emt == info.block ||
			info.block == info.fill)
		return (FAIL);
	while (++i < len - 3)
		info.rows[i] = buf[i];
	info.rows[i] = '\0';
	if (ft_atoi())
		return (FAIL);
	return (SUCCESS);
}

int	dup_line(int rd_fd, char *line)
{
	int	i;

	i = -1;
	line = (char *)malloc(sizeof(char) * (info.col_len + 1));
	while (read(rd_fd, &line[++i], 1))
	{
		if (check_deserve(line[i]))
			return (FAIL);
		if (i == info.col_len)
		{
			if (line[i] == '\n' || line[i] == '\0')
				break ;
			return (FAIL);
		}
	}
	line[i] = '\0';
	return (SUCCESS);
}

int	init_map(t_map *map, int rd_fd)
{
	int		i;
	char	tmp;

	i = -1;
	map = (t_map *)malloc(sizeof(t_map) * (info.row_len + 1));
	map[info.row_len].line = NULL;
	while (read(rd_fd, &tmp, 1))
		if (tmp == '\n')
			break ;
	while (++i < info.row_len)
		if (dup_line(rd_fd, map[i].line))
		{
			dobby_is_free(map);
			return (FAIL);
		}
	return (SUCCESS);
}

int	check_err(int cnt_fd, int rd_fd, t_map *map)
{
	int		i;
	char	buf[BUF_SIZE];

	i = -1;
	while (read(cnt_fd, &buf[++i], 1))
	{
		if (buf[i] == '\n')
			break ;
		if (buf[i] <= 31 || buf[i] == 127)
			return (FAIL);
	}
	if (i < 4 || cnt_col(cnt_fd) || fill_info(buf, i) || init_map(map, rd_fd))
		return (FAIL);
	return (SUCCESS);
}
