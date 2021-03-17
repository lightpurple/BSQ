/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extend_split.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euhong <euhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 21:06:58 by euhong            #+#    #+#             */
/*   Updated: 2021/03/17 21:43:42 by euhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

extern t_info	g_info;

char			*ft_extend(char *line, int line_len, char *buf, int b_size)
{
	char	*new_line;

	if (!(new_line = (char *)malloc(line_len + b_size + 1)))
		return (NULL);
	*new_line = '\0';
	if (line != NULL)
		ft_strncat(&new_line, line, line_len);
	ft_strncat(&new_line, buf, b_size);
	if (line != NULL)
		free(line);
	return (new_line);
}

int				ft_split_size(char *line, int idx)
{
	int	i;
	int	tmp;
	int	cnt;

	i = 0;
	cnt = -1;
	if (i == 0)
		while (line[i] != '\n')
			i++;
	while (1)
	{
		tmp = i;
		while (line[++i] != '\n')
			;
		cnt++;
		if (cnt == idx)
			break ;
	}
	return (i - tmp);
}

t_map			*ft_split(char *line)
{
	int		i;
	t_map	*map;

	i = -1;
	if (!(map = (t_map *)malloc(sizeof(t_map) * (g_info.row_len + 1))))
	{
		free(line);
		return (NULL);
	}
	while (++i < g_info.row_len)
		if (!(map[i].line = (char *)malloc(ft_split_size(line, i))))
		{
			free_line(map, i);
			return (NULL);
		}
	map[g_info.row_len].line = NULL;
	i = 0;
	while (i < g_info.row_len)
	{
		ft_strcpy(&map[i].line, line, i);
		i++;
	}
	free(line);
	return (map);
}
