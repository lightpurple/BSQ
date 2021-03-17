/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euhong <euhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 20:43:39 by euhong            #+#    #+#             */
/*   Updated: 2021/03/17 21:25:50 by euhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

extern t_info	g_info;

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
	int i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i])
		i++;
	return (i);
}

void			ft_strcpy(char **copy, char *line, int idx)
{
	int			i;
	int			j;
	int			tmp;
	int			cnt;

	i = 0;
	cnt = -1;
	j = -1;
	if (i == 0)
		while (line[i] != '\n')
			i++;
	while (1)
	{
		tmp = i + 1;
		while (line[++i] != '\n')
			;
		cnt++;
		if (cnt == idx)
			break;
	}
	while (++j < i - tmp)
	{
		(*copy)[j] = line[tmp + j];
	}
	(*copy)[j] = '\0';
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
