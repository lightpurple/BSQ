/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euhong <euhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 21:06:58 by euhong            #+#    #+#             */
/*   Updated: 2021/03/10 21:07:47 by euhong           ###   ########.fr       */
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

char	*read_stdin(void)
{
	int		i;
	char	*buf;

	i = 0;
	buf = (char *)malloc(sizeof(char) * BUF_SIZE);
	while (read(0, &buf[i], 1))
		i++;
	return (buf);
}
