/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heat_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdemian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 19:54:55 by pdemian           #+#    #+#             */
/*   Updated: 2019/05/01 19:54:58 by pdemian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static void				avoid_norminette(t_map *map, int y, int x, int value)
{
	if (!ft_strstr(map->en, &map->map[y - 1][x - 1]) &&
	!map->heat[y - 1][x - 1])
		map->heat[y - 1][x - 1] = value;
	if (!ft_strstr(map->en, &map->map[y - 1][x]) &&
	!map->heat[y - 1][x])
		map->heat[y - 1][x] = value;
	if (!ft_strstr(map->en, &map->map[y - 1][x + 1]) &&
	!map->heat[y - 1][x + 1])
		map->heat[y - 1][x + 1] = value;
}

static void				heat_coord(t_map *map, int y, int x, int value)
{
	if (y > 0)
	{
		avoid_norminette(map, y, x, value);
	}
	if (!ft_strstr(map->en, &map->map[y][x - 1]) &&
	!map->heat[y][x - 1])
		map->heat[y][x - 1] = value;
	if (!ft_strstr(map->en, &map->map[y][x + 1]) &&
	!map->heat[y][x + 1])
		map->heat[y][x + 1] = value;
	if (y < map->rows - 1)
	{
		if (!ft_strstr(map->en, &map->map[y + 1][x - 1]) &&
		!map->heat[y + 1][x - 1])
			map->heat[y + 1][x - 1] = value;
		if (!ft_strstr(map->en, &map->map[y + 1][x]) &&
		!map->heat[y + 1][x])
			map->heat[y + 1][x] = value;
		if (!ft_strstr(map->en, &map->map[y + 1][x + 1]) &&
		!map->heat[y + 1][x + 1])
			map->heat[y + 1][x + 1] = value;
	}
}

static void				init_heat(t_map *map)
{
	int y;
	int x;

	y = -1;
	while (++y < map->rows)
	{
		x = -1;
		while (++x < map->cols)
		{
			map->heat[y][x] = 0;
		}
	}
}

void					heat_map(t_map *map)
{
	int y;
	int x;
	int value;

	value = -1;
	init_heat(map);
	while (++value < map->cols)
	{
		y = -1;
		while (++y < map->rows)
		{
			x = -1;
			while (++x < map->cols)
			{
				if ((map->map[y][x] == map->en[0]
				|| map->map[y][x] == map->en[1]) && map->heat[y][x] != -1)
				{
					map->heat[y][x] = -1;
					heat_coord(map, y, x, value + 1);
				}
				else if (map->heat[y][x] == value && value)
					heat_coord(map, y, x, value + 1);
			}
		}
	}
}
