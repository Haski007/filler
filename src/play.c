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

static void             get_my_pos(t_map *map)
{
    int     y;
    int     x;
    int     max;

    y = 0;
    max = 999;
    while (y < map->rows)
    {
        x = 0;
        while (x < map->cols)
        {
            if (map->map[y][x] == map->me || map->map[y][x] == ft_tolower(map->me))
            {
                if (map->heat[y][x - 1] <= max)
                    map->me_x = x;
                else if (map->heat[y][x + 1] <= max)
                    map->me_x = x;
                if (map->heat[y - 1][x] <= max)
                    map->me_y = y;
                else if (map->heat[y + 1][x] <= max)
                    map->me_y = y;
                max = map->heat[map->me_y][map->me_x];
            }
            x++;
        }
        y++;
    }
}

void                    play(t_map *map, t_oken *token)
{
    int     y;
    int     x;

    y = 0;
    get_my_pos(map);
    ft_putnbr(map->me_y);
    ft_putchar(' ');
    ft_putnbr(map->me_x);
    ft_putchar('\n');
}