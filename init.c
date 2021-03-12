/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euhong <euhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 19:56:52 by euhong            #+#    #+#             */
/*   Updated: 2021/03/12 21:26:45 by dookim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void			change_map(int **copy_map, t_info *info)
{
	
}

void	ft_fail_malloc(char **map)
{
	int idx;

	idx = -1;
	while (map[++idx] == NULL)
		free(map[idx]);
	free(map);
}

char	**init_malloc(char **map, int rows, int cols)
{
	int idx;

	if((map = (char **)malloc(sizeof(char *) * (rows + 1))) == NULL)
		return (NULL);
	map[rows] = NULL;
	idx = -1;
	while (++idx < cols)
	{
		if((map[cols] = (char *)malloc(sizeof(char) * (cols + 1))) == NULL)
		{
			ft_fail_malloc(map);
			return (NULL);
		}
	}
	return (map);
}

void			dobby_is_free(int **copy_map)
{

}
