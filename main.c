/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euhong <euhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 17:07:07 by euhong            #+#    #+#             */
/*   Updated: 2021/03/10 21:19:58 by euhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	main(int argc, char *argv[])
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
