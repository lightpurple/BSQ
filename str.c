/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euhong <euhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 20:43:39 by euhong            #+#    #+#             */
/*   Updated: 2021/03/18 00:16:03 by euhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

extern t_info	g_info;
extern int		g_flag;

int				ft_nl_len(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i] != '\n')
		i++;
	return (i);
}

int				ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i])
		i++;
	return (i);
}

int				ft_strcpy(char **copy, char *line)
{
	int			i;
	static int	cur = 0;

	if (g_flag == 2)
	{
		cur = 0;
		g_flag = 0;
	}
	i = -1;
	if (cur == 0)
		while (line[cur] != '\n')
			cur++;
	while (line[++cur] != '\n')
		(*copy)[++i] = line[cur];
	if (i != -1)
		(*copy)[++i] = '\0';
	return (i);
}

void			ft_strncat(char **dest, char *src, int n)
{
	int	i;
	int	j;

	i = ft_strlen(*dest);
	j = 0;
	while (j < n && src[j])
		(*dest)[i++] = src[j++];
	(*dest)[i] = '\0';
}

int				*ft_strdup_to_int(char *src)
{
	int	index;
	int	*dest;

	index = -1;
	if ((dest = (int *)malloc(sizeof(int) * (g_info.col_len + 1))) == NULL)
		return (NULL);
	while (src[++index])
		dest[index] = src[index];
	dest[index] = LINE_END;
	return (dest);
}
