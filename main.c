/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euhong <euhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 17:07:07 by euhong            #+#    #+#             */
/*   Updated: 2021/03/12 22:27:08 by euhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	main(int argc, char *argv[])
{
	int		fd1;
	int		fd2;
	int		i;
	int		size;
	char	*f_name;

	i = 0;
	if (argc == 1)
	{
		f_name = read_stdin();
		fd1 = open(f_name, O_RDONLY);
		fd2 = open(f_name, O_RDONLY);
		bsq(fd1, fd2);
		close(fd1);
		close(fd2);
		free(f_name);
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
}
