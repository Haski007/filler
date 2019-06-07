/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdemian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 17:00:57 by pdemian           #+#    #+#             */
/*   Updated: 2019/06/04 17:00:58 by pdemian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static void             find_error(t_oken *token)
{
    int     i;
    int     j;

    j = token->rows;
    while (--j > -1)
    {
        i = (token->err_x) ? token->err_x - 1 : token->cols;
        while (--i > -1)
        {
            if (token->shape[j][i] == '*')
            {
                token->err_x = i;
                token->err_y = j;
                return ;
            }
        }
    }
}

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
                if (map->heat[y][x - 1] < max)
                    map->me_x = x;
                else if (map->heat[y][x + 1] < max)
                    map->me_x = x;
                if (map->heat[y - 1][x] < max)
                    map->me_y = y;
                else if (map->heat[y + 1][x] < max)
                    map->me_y = y;
                max = map->heat[map->me_y][map->me_x];
            }
            x++;
        }
        y++;
    }
}

void                    play2(t_map *map, t_oken *token)
{

    int     i;

    i = 0;
    dprintf(2, "____________________\n");
    get_my_pos(map);
    find_error(token);
    dprintf(2, "err_y = %d\nerr_x = %d\n", token->err_y, token->err_x);
    dprintf(2, "me_y = %d\nme_x = %d\n", map->me_y, map->me_x);
    map->fin_y = map->me_y - token->err_y;
    map->fin_x = map->me_x - token->err_x;
    while (i < 20)
    {
        find_error(token);
        map->fin_y = map->me_y - token->err_y;
        map->fin_x = map->me_x - token->err_x;
        i++;
    }
    dprintf(2, "--------------------\n");
    ft_putnbr(map->fin_y);
    ft_putchar(' ');
    ft_putnbr(map->fin_x);
    ft_putchar('\n');
    // ft_free_arr(&map->map);
    // ft_free_arr(&token->shape);
}