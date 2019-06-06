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
    int     yy;
    int     xx;
    int     max;

    y = 0;
    max = 999;
    while (y < map->rows)
    {
        x = 0;
        while (map->map[y][x])
        {
            if (map->map[y][x] == map->me || map->map[y][x] == ft_tolower(map->me))
            {
                if (map->heat[y][x - 1] <= max)
                    xx = x;
                else if (map->heat[y][x + 1] <= max)
                    xx = x;
                if (map->heat[y - 1][x] <= max)
                    yy = y;
                else if (map->heat[y + 1][x] <= max)
                    yy = y;
                max = map->heat[yy][xx];
            }
            x++;
        }
        y++;
    }
    map->me_x = xx;
    map->me_y = yy;
}

void                    play(t_map *map, t_oken *token)
{
    static int  i = 0;

    get_my_pos(map);
    map->fin_x = map->me_x - token->err_x;
    map->fin_y = map->me_y - token->err_y;
    if (!(valid_token(map, token)))
        map->fd = 333;
    i++;
    // dprintf(2, "\ni = %d\n", i);
    // dprintf(2, "\nIt's trapped!!\n");
    // dprintf(2, "\ny = %d\nx = %d\n", map->fin_y, map->fin_x);
    ft_putnbr(map->fin_y);
    ft_putchar(' ');
    ft_putnbr(map->fin_x);
    ft_putchar('\n');
}