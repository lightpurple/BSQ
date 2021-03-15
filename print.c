/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euhong <euhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 20:47:53 by euhong            #+#    #+#             */
/*   Updated: 2021/03/15 16:26:43 by dookim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_putstr(char *str)
{
	write(2, str, ft_strlen(str));
	write(2, "\n", 1);
}

void	print_map(t_map *map)
{
	
}

void	print_err(void)
{
	ft_putstr("Map Error!");
}
