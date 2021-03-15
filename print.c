/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euhong <euhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 20:47:53 by euhong            #+#    #+#             */
/*   Updated: 2021/03/15 19:52:35 by euhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
	write(1, "\n", 1);
}

void	print_map(t_map *map)
{
	int i;

	i = -1;
	while (map[++i].line)
		putstr(map[i].line);
}

void	print_err(char *str)
{
	while (*str)
		write(2, str++, 1);
}
