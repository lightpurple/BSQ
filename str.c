/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euhong <euhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 20:43:39 by euhong            #+#    #+#             */
/*   Updated: 2021/03/16 18:10:18 by euhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

extern t_info g_info;

int				ft_strlen(char *str)
{
	char	*str_st;

	str_st = str;
	while (*str_st)
		str_st++;
	return (str_st - str);
}

void			ft_strcat(char **dest, char *src)
{
	int i;
	int j;

	i = ft_strlen(*dest);
	j = 0;
	while (src[j])
		(*dest)[i++] = src[j++];
	(*dest)[i] = '\0';
}

int				*ft_strdup_to_int(char *src)
{
	int	index;
	int	*dest;

	index = -1;
	if ((dest = (int *)malloc(sizeof(int) * (g_info.col_len + 1))) == NULL)
		return (0);
	while (src[++index])
		dest[index] = src[index];
	dest[index] = LINE_END;
	return (dest);
}
