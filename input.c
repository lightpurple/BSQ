/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euhong <euhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 21:06:58 by euhong            #+#    #+#             */
/*   Updated: 2021/03/16 18:22:15 by euhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int		ft_file_size(int fd)
{
	int		cnt;
	char	tmp;

	cnt = 0;
	while (read(fd, &tmp, 1))
		cnt++;
	return (cnt);
}

char	*add_buf(char *file, char *buf)
{
	char	*res;

	if (file == NULL)
	{
		res = (char *)malloc(ft_strlen(buf) + 1);
		*res = '\0';
		ft_strcat(&res, buf);
	}
	else
	{
		res = (char *)malloc(ft_strlen(file) + ft_strlen(buf) + 1);
		*res = '\0';
		ft_strcat(&res, file);
		ft_strcat(&res, buf);
	}
	free(file);
	return (res);
}

char	*read_stdin(void)
{
	char	buf[BUF_SIZE];
	char	*file;
	int		end;

	file = NULL;
	end = read(0, buf, BUF_SIZE - 1);
	while (end == BUF_SIZE - 1)
	{
		buf[end] = '\0';
		file = add_buf(file, buf);
		end = read(0, buf, BUF_SIZE - 1);
	}
	buf[end] = '\0';
	file = add_buf(file, buf);
	return (file);
}
