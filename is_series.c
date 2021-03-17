/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_series.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dookim <dookim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 10:56:06 by dookim            #+#    #+#             */
/*   Updated: 2021/03/17 18:32:54 by euhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include "string.h"

extern t_info	g_info;

int				is_non_printable(char c)
{
	if (!(c >= 32 && c <= 126))
		return (1);
	else
		return (0);
}

int				ft_str_is_printable(char *str)
{
	int	index;

	index = 0;
	while (str[index] != '\0')
	{
		if (is_non_printable(str[index]))
			return (0);
		index++;
	}
	return (1);
}

int				is_in_info(char *line)
{
	int	idx;

	idx = -1;
	while (line[++idx])
		if (line[idx] != g_info.fill && line[idx] != g_info.block &&
			line[idx] != g_info.emt)
			return (FAIL);
	return (SUCCESS);
}

int				is_c_in_str(char c, char *str)
{
	while (*str)
	{
		if (c == *str)
			return (1);
		str++;
	}
	return (0);
}
