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

static void     heat_this(t_map *map, int x, int y)
{
    if ((map->map[y][x - 1] == '.' || map->map[y][x - 1] == map->me || map->map[y][x - 1] == ft_tolower(map->me))
    && !map->heat[y][x - 1])
        map->heat[y][x - 1] = map->value + 1;
    if ((map->map[y][x + 1] == '.' || map->map[y][x + 1] == map->me || map->map[y][x + 1] == ft_tolower(map->me))
    && !map->heat[y][x + 1])
        map->heat[y][x + 1] = map->value + 1;
    if (y > 0)
    {
        if ((map->map[y - 1][x] == '.' || map->map[y - 1][x] == map->me || map->map[y - 1][x] == ft_tolower(map->me))
        && !map->heat[y - 1][x])
            map->heat[y - 1][x] = map->value + 1;
        if ((map->map[y - 1][x + 1] == '.' || map->map[y - 1][x + 1] == map->me || map->map[y - 1][x + 1] == ft_tolower(map->me))
        && !map->heat[y - 1][x + 1])
            map->heat[y - 1][x + 1] = map->value + 1;
        if ((map->map[y - 1][x - 1] == '.' || map->map[y - 1][x - 1] == map->me || map->map[y - 1][x - 1] == ft_tolower(map->me))
        && !map->heat[y - 1][x - 1])
            map->heat[y - 1][x - 1] = map->value + 1;
    }
    if (y < map->rows - 1)
    {
        if ((map->map[y + 1][x] == '.' || map->map[y + 1][x] == map->me || map->map[y + 1][x] == ft_tolower(map->me))
        && !map->heat[y + 1][x])
            map->heat[y + 1][x] = map->value + 1;
        if ((map->map[y + 1][x + 1] == '.' || map->map[y + 1][x + 1] == map->me|| map->map[y + 1][x + 1] == ft_tolower(map->me))
        && !map->heat[y + 1][x + 1])
            map->heat[y + 1][x + 1] = map->value + 1;
        if ((map->map[y + 1][x - 1] == '.' || map->map[y + 1][x - 1] == map->me || map->map[y + 1][x - 1] == ft_tolower(map->me))
        && !map->heat[y + 1][x - 1])
            map->heat[y + 1][x - 1] = map->value + 1;
    }
}

static void     start_heat(t_map *map)
{
    int     x;
    int     y;
    int     i;

    i = -1;
    while (++i < map->cols)
    {
        map->value = i;
        y = 0;
        while (y < map->rows)
        {
            x = 0;
            while (x < map->cols)
            {
                if (map->map[y][x] == map->enemy || map->map[y][x] == ft_tolower(map->enemy))
                {
                    map->heat[y][x] = -1;
                    heat_this(map, x, y);
                }
                else if (map->heat[y][x] == map->value && map->value)
                    heat_this(map, x, y);
                x++;
            }
            y++;
        }
    }
}

static void	    ft_free_int_arr(t_map *map)
{
	int	x;
    int y;

	y = -1;
	while (map->heat[++y])
	{
        x = -1;
        while (map->heat[y][++x])
            map->heat[y][x] = 0;
    }
}


void            heat_map(t_map *map)
{
    int             i;

    i = -1;
    if (map->heat)
        ft_free_int_arr(map);
    else
    {
        map->heat = (int **)malloc(sizeof(int *) * map->rows + 1);
        map->heat[map->rows] = NULL;
    while (++i < map->rows)
        map->heat[i] = (int *)malloc(sizeof(int) * map->cols);
    }
    i = -1;
    start_heat(map);
    //paint_heat(map);
}