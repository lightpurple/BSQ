/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dookim <dookim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 10:43:50 by dookim            #+#    #+#             */
/*   Updated: 2021/03/17 16:40:21 by dookim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include "struct.h"

extern t_info g_info;

int	first_error_check(void)
{
	int idx;
	int count;

	if (ft_strlen(g_info.rows) < 4 || !ft_str_is_printable(g_info.rows))
	{
		free(g_info.rows);
		return (FAIL);
	}
	idx = -1;
	count = 0;
	while (g_info.rows[++idx])
		if (is_c_in_str(g_info.rows, "0123456789"))
			count++;
	if (count == 0 || (count < ft_strlen(g_info.rows) - 3))
	{
		free(g_info.rows);
		return (FAIL);
	}
	return (SUCESS);
}

int	fill_info(char *line)
{
	int idx;
	int len;

	if (first_error_check())
		return (FAIL);
	g_info.row_len = 0;
	len = ft_strlen(g_info.rows);
	idx = -1;
	while (++idx < len -3)
		g_info.row_len = 10 * g_info.row_len + g_info.rows[idx] - '0';
	if (g_info.row_len == 0)
	{
		free(g_info.rows);
		return (FAIL);
	}
	if (linefeed_error_check(line))
		return (FAIL);
	g_info.emt = g_info.rows[len - 3];
	g_info.block = g_info.rows[len - 2];
	g_info.fill = g_info.rows[len - 1];
	return (SUCCESS);
}
