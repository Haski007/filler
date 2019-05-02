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
    x = 0;
    y = 0;
    while (y < map->rows)
    {
        x = 0;
        while (x < map->cols)
        {
            if (map->map[y][x] == 'X' && map->player)
            {
                map->e_start_x = x;
                map->e_start_y = y;
            }
            else if (map->map[y][x] == 'O' && !map->player)
            {
                map->e_start_x = x;
                map->e_start_y = y;
            }
            x++;
        }
        y++;
    }
}