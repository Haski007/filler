/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdemian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 18:41:18 by pdemian           #+#    #+#             */
/*   Updated: 2019/05/01 18:41:19 by pdemian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void        parse_enemy(t_map *map)
{
    int     x;
    int     y;
    int     i = 0;

    y = -1;
    while (++y < map->rows)
    {
        x = -1;
        while (++x < map->cols)
        {
            if (map->map[y][x] == ft_tolower(map->enemy))
            {
                map->enemy_x = x;
                map->enemy_y = y;
            }
        }
    }
}