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
    if (map->map[y][x - 1] == '.' && !map->heat[y][x])
        map->heat[y][x - 1] = map->value + 1;
    if (map->map[y][x + 1] == '.' && !map->heat[y][x])
        map->heat[y][x + 1] = map->value + 1;
    if (map->map[y - 1][x] == '.' && !map->heat[y][x])
        map->heat[y - 1][x] = map->value + 1;
    if (map->map[y - 1][x + 1] == '.' && !map->heat[y][x])
        map->heat[y - 1][x + 1] = map->value + 1;
    if (map->map[y - 1][x - 1] == '.' && !map->heat[y][x])
        map->heat[y - 1][x - 1] = map->value + 1;
    if (map->map[y + 1][x] == '.' && !map->heat[y][x])
        map->heat[y + 1][x] = map->value + 1;
    if (map->map[y + 1][x + 1] == '.' && !map->heat[y][x])
        map->heat[y + 1][x + 1] = map->value + 1;
    if (map->map[y + 1][x - 1] == '.' && !map->heat[y][x])
        map->heat[y + 1][x - 1] = map->value + 1;
    paint_map(map);
    printf("============================================\n");
}

static void     start_heat(t_map *map)
{
    int     x;
    int     y;

    y = 0;
    while (y < map->rows)
    {
        x = 0;
        while (x < map->cols)
        {
            if (map->map[y][x] == 'X' || ft_atoi(map->map[y][x]) == map->value)
                heat_this(map, x, y);
            // printf("++++++++++%d++++++++++++++%d+++++++++\n", y, x);    
            
            x++;
        }
        y++;
    }
}

void            heat_map(t_map *map)
{
    int     i = -1;

    map->heat = (int **)malloc(sizeof(int *) * map->rows + 1);
    map->heat[map->rows] = NULL;
    while (++i < map->rows)
        map->heat[i] = (int *)malloc(sizeof(int) * map->cols);
    i = -1;
    while (++i < 70)
    {
        map->value = i;
        start_heat(map);
    }
}