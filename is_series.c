/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_series.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dookim <dookim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 10:56:06 by dookim            #+#    #+#             */
/*   Updated: 2021/03/17 11:41:21 by dookim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include "string.h"

int		is_non_printable(char c)
{
	if (!(c >= 32 && c <= 126))
		return (1);
	else
		return (0);
}

int		ft_str_is_printable(char *str)
{
	int index;

	index = 0;
	while (str[index] != '\0')
	{
		if (is_non_printable(str[index]))
			return (0);
		index++;
	}
	return (1);
}
