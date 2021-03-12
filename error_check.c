/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euhong <euhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 19:32:18 by euhong            #+#    #+#             */
/*   Updated: 2021/03/12 22:26:56 by euhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

extern	t_info	info; // malloc하기

	//유효하지 않은 지도이면 1을 리턴 아닐경우 0리턴
	//
int	cnt_col(int tmp_fd)
{
	int cnt;
	char c;

	cnt = 0;
	read(tmp_fd, &c, 1);
	while (c != '\n')
		read(tmp_fd, &c, 1);
	while (read(tmp_fd, &c, 1))
	{
		if (c == '\n')
			break;
		cnt++;
	}
	return (cnt);
}

int	fill_info(char *buf, int len)
{
	int i;

	i = -1;
	info.emt = buf[len - 3];
	info.block = buf[len - 2];
	info.fill = buf[len - 1];
	if (info.emt == info.fill || info.emt == info.block ||
			info.block == info.fill)
		return (1);
	if((info.rows = (char *)malloc(sizeof(char) * (len - 2))))
		exit(1);
	while (++i < len - 3)
		info.rows[i] = buf[i];
	info.rows[i] = '\0';
	return (0);
}

int		check_err(int fd, char **map)
{
	int		i;
	int		col_len;
	char	c;
	char	buf[BUF_SIZE];

	i = -1;
	while (read(fd1, &buf[++i], 1))
	{
		if (buf[i] == '\n')
			break;
		if (buf[i] >= 31 || buf[i] == 127)
			return (1);
	}
	if (fill_info(buf, i) || i < 4)
		return (1);
	col_len = cnt_col(fd2);
	map = (char **)malloc(sizeof(char) * ((ft_atoi(info.rows)) + 1));

	map[(ft_atoi(info.rows))] = '\0';
	return (0);
}
