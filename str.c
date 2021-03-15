/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euhong <euhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 20:43:39 by euhong            #+#    #+#             */
/*   Updated: 2021/03/15 20:49:10 by euhong           ###   ########.fr       */
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

int				*ft_strdup_to_int(char *src)
{
	int	index;
	int	*dest;

	index = -1;
	if ((dest = (int *)malloc(sizeof(int) * (g_info.col_len + 1))) == NULL)
		return (0);
	while (src[++index])
		dest[index] = (int)(src[index]);
	dest[index] = LINE_END;
	return (dest);
}
