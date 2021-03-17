/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euhong <euhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 21:06:58 by euhong            #+#    #+#             */
/*   Updated: 2021/03/17 18:23:17 by euhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

extern t_info	g_info;

char			*ft_extend(char *line, int line_len, char *buf)
{
	char	*new_line;

	if (!(new_line = (char *)malloc(line_len + ft_strlen(buf) + 1)))
		return (NULL);
	*new_line = '\0';
	if (line != NULL)
		ft_strcat(&new_line, line);
	ft_strcat(&new_line, buf);
	if (line != NULL)
		free(line);
	return (new_line);
}

int				ft_split_size(char *line)
{
	static int	cur;
	int			cmp;

	cur = 0;
	if (cur == 0)
		while (line[cur] != '\n')
			cur++;
	cmp = cur;
	while (line[++cur] != '\n')
		;
	if (cmp != cur)
		return (cur - cmp);
	return (0);
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
		if (!(map[i].line = (char *)malloc(ft_split_size(line))))
		{
			free_line(map, i);
			return (NULL);
		}
	map[g_info.row_len].line = NULL;
	i = 0;
	while (i < g_info.row_len)
	{
		if (ft_strcpy(&map[i].line, line) == -1)
			continue ;
		i++;
	}
	free(line);
	return (map);
}
