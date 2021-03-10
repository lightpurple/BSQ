/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euhong <euhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 20:47:53 by euhong            #+#    #+#             */
/*   Updated: 2021/03/10 20:50:12 by euhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_putstr(char *str)
{
	while (*str)
		write(2, str++, 1);
	write(2, "\n", 1);
}

void	print_map(char **map)
{

}

void	print_err(void)
{
	ft_putstr("Map Error!");
}
