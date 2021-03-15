/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euhong <euhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 19:32:18 by euhong            #+#    #+#             */
/*   Updated: 2021/03/15 23:32:01 by euhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

extern t_info g_info; // malloc하기

//유효하지 않은 지도이면 1을 리턴 아닐경우 0리턴
//

int	check_deserve(char c)
{
	if (c != g_info.emt && c != g_info.block && c != g_info.fill &&
			c != '\n' && c != '\0')
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
	if (cnt < 1 || (c != '\n' && c != '\0'))
		return (FAIL);
	g_info.col_len = cnt;
	return (SUCCESS);
}

int	fill_info(char *buf, int len)
{
	int	i;

	i = -1;
	g_info.emt = buf[len - 3];
	g_info.block = buf[len - 2];
	g_info.fill = buf[len - 1];
	if (g_info.emt == g_info.fill || g_info.emt == g_info.block ||
			g_info.block == g_info.fill)
		return (FAIL);
	g_info.rows = (char *)malloc(sizeof(char) * (len - 2));
	while (++i < len - 3)
		g_info.rows[i] = buf[i];
	g_info.rows[i] = '\0';
	if (ft_atoi())
		return (FAIL);
	return (SUCCESS);
}

int	dup_line(int rd_fd, char *line)
{
	int	i;

	i = -1;
	line = (char *)malloc(sizeof(char) * (g_info.col_len + 1));
	while (read(rd_fd, &line[++i], 1))
	{
		if (check_deserve(line[i]))
			return (FAIL);
		if (i == g_info.col_len)
		{
			if (line[i] == '\n' || line[i] == '\0')
				break ;
			return (FAIL);
		}
	}
	line[i] = '\0';
	return (SUCCESS);
}

t_map	*check_err(int cnt_fd, int rd_fd, int *err)
{
	int		i;
	char	buf[BUF_SIZE];
	t_map	*map;

	i = -1;
	map = NULL;
	*err = SUCCESS;
	while (read(cnt_fd, &buf[++i], 1))
	{
		if (buf[i] == '\n')
			break ;
		if (buf[i] <= 31 || buf[i] == 127)
			*err = FAIL;
	}
	if (i < 4 || cnt_col(cnt_fd) || fill_info(buf, i) || init_map(&map, rd_fd))
		*err = FAIL;
	if (*err == FAIL)
		return (NULL);
	else
		return (map);
}
