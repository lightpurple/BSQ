/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euhong <euhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 17:07:07 by euhong            #+#    #+#             */
/*   Updated: 2021/03/10 20:22:04 by euhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
# define BUF_SIZE 1000

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

int		main(int argc, char *argv[])
{
	int		fd;
	int		i;
	int		size;
	char	*f_name;

	i = 0;
	if (argc == 1)
	{
		f_name = read_stdin();
		fd = open(f_name, O_RDONLY);
		bsq(fd);
		close(fd);
	}
	else
	{
		while (++i < argc)
		{
			fd = open(argv[i], O_RDONLY);
			bsq(fd);
			close(fd);
		}
	}
	free(f_name);
}
