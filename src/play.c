/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdemian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 18:45:16 by pdemian           #+#    #+#             */
/*   Updated: 2019/05/05 18:45:18 by pdemian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static void     get_my_pos(t_map *map)
{
    int     y;
    int     x;
    char    me;

    me = (map->player) ? 'O' : 'X';
    y = 0;
    while (y < map->rows)
    {
        x = 0;
        while (x < map->cols)
        {
            if (map->map[y][x] == me || map->map[y][x] == ft_tolower(me))
            {
                if (map->heat[y][x - 1] < map->fd)
                    map->my_pos_x = x;
                else if (map->heat[y][x + 1] < map->fd)
                    map->my_pos_x = x;
                else if (map->heat[y][x + 1] == map->heat[y][x - 1])
                    map->my_pos_x = x;
                if (map->heat[y - 1][x] < map->fd)
                    map->my_pos_y = y;
                else if (map->heat[y + 1][x] < map->fd)
                    map->my_pos_y = y;
                else if (map->heat[y + 1][x] == map->heat[y - 1][x])
                    map->my_pos_y = y;
            }
            x++;
        }
        y++;
    }
}

void            play(t_map *map, t_oken *token)
{
    int     y;
    int     x;

    get_my_pos(map);
    printf("x = %d\ny = %d\n", map->my_pos_x, map->my_pos_y);
    y = 0;
    while (y < map->rows)
    {
        x = 0;
        y++;
    }
}