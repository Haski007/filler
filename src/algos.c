/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algos.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdemian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 17:28:26 by pdemian           #+#    #+#             */
/*   Updated: 2019/06/09 17:28:28 by pdemian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int                tactic1(t_map *map, t_oken *token)
{
    int     x;
    int     y;
    int     value;

    value = 999;
    y = -1;
    while (++y < map->rows)
    {
        x = -1;
        while (++x < map->cols)
        {
            if (valid_token(map, token, x, y) && map->heat[y][x] <= value)
            {
                map->fin_x = x - token->left;
                map->fin_y = y - token->up;
                value = map->heat[y][x];
            }
        }
    }
    if (value == 999)
        return (0);
    return(1);
}

int             tactic3(t_map *map, t_oken *token)
{
    int     x;
    int     y;
    int     value;

    value = 999;
    y = map->rows - 1;
    while (--y > 0)
    {
        x = -1;
        while (--x > 0)
        {
            if (valid_token(map, token, x, y) && map->heat[y][x] <= value)
            {
                map->fin_x = x - token->left;
                map->fin_y = y - token->up;
                value = map->heat[y][x];
            }
        }
    }
    if (value == 999)
        return (0);
    return(1);
}


int             tactic2(t_map *map, t_oken *token)
{
    int     x;
    int     y;
    int     value;

    value = 999;
    y = -1;
    while (--y > 0)
    {
        x = map->cols - 1;
        while (--x > 0)
        {
            if (valid_token(map, token, x, y) && map->heat[y][x] <= value)
            {
                map->fin_x = x - token->left;
                map->fin_y = y - token->up;
                value = map->heat[y][x];
            }
        }
    }
    if (value == 999)
        return (0);
    return(1);
}

int                tactic4(t_map *map, t_oken *token)
{
    int     x;
    int     y;
    int     value;

    value = 999;
    y = map->rows - 1;
    while (--y > 0)
    {
        x = map->cols - 1;
        while (--x > 0)
        {
            if (valid_token(map, token, x, y) && map->heat[y][x] <= value)
            {
                map->fin_x = x - token->left;
                map->fin_y = y - token->up;
                value = map->heat[y][x];
            }
        }
    }
    if (value == 999)
        return (0);
    return(1);
}

static int                check_all2(t_map *map, t_oken *token)
{
    int     x;
    int     y;

    y = map->rows - 1;
    while (++y < map->rows)
    {
        x = map->cols - 1;
        while (++x < map->cols)
        {
            if (valid_token(map, token, x, y))
            {
                map->fin_x = x - token->left;
                map->fin_y = y - token->up;
                return (1);
            }
        }
    }
    return(0);
}

int                check_all(t_map *map, t_oken *token)
{
    int     x;
    int     y;

    y = map->rows - 1;
    while (++y < map->rows)
    {
        x = map->cols - 1;
        while (++x < map->cols)
        {
            if (valid_token(map, token, x, y))
            {
                map->fin_x = x - token->left;
                map->fin_y = y - token->up;
                return (1);
            }
        }
    }
    return(check_all2(map, token));
}
