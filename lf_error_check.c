/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lf_error_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dookim <dookim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 16:36:39 by dookim            #+#    #+#             */
/*   Updated: 2021/03/17 17:11:36 by dookim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include "struct.h"

extern t_info	g_info; 

int	linefeed_error_check(char *line)
{
	int idx;
	int count;

	count = 0;
	idx = -1;
	while (line[++idx])
		if (line[idx] == '\n')
			count++;
	if (g_info.row_len != count - 1)
	{
		free(g_info.rows);
		return (FAIL);
	}
	idx = -1;
	while (line[++idx])
	{
		if ((idx != ft_strlen(line)) &&
			(line[idx] == '\n' && line[idx + 1] == '\n'))
		{
			free(g_info.rows);
			return (FAIL);
		}
	}
	return (SUCCESS);
}
