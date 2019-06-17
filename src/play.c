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

int                    valid_token(t_map *map, t_oken *token, int x, int y)
{
    int     j;
    int     i;
    int     on;

    if (token->right + 1 + x - token->left  > map->cols || token->down + 1 - token->up + y > map->rows)
        return (0);
    on = 0;
    j = -1 + token->up;
    while (++j < token->down + 1)
    {
        i = -1 + token->left;
        while (++i < token->right + 1)
        {
            if (token->shape[j][i] == '*' &&
            (map->map[y + j - token->up][x + i - token->left] == map->enemy
            || map->map[y + j - token->up][x + i - token->left] == ft_tolower(map->enemy)))
                return (0);
            else if (token->shape[j][i] == '*' &&
            (map->map[y + j - token->up][x + i - token->left] == map->me ||
            map->map[y + j - token->up][x + i - token->left] == ft_tolower(map->me)))
                on++;
        }
    }
    if (on == 1)
        return(1);
    return (0);
}

static int                     check_square(t_map *map, int x, int y)
{
    int     y2;
    int     x2;

    y2 = y + 4;
    x2 = x + 4;
    y = (y - 3 > 0) ? y - 4 : y - 3;
    while (++y < map->rows && y < y2)
    {
        x = (x - 3 > 0) ? x - 4 : x - 3;
        while (++x < map->cols && x < x2)
        {
            if (map->map[y][x] == map->enemy ||
            map->map[y][x] == ft_tolower(map->enemy))
                return (1);
        }
    }
    return (0);
}

static int                    is_contact(t_map *map)
{
    int     y;
    int     x;
    
    y = -1;
    while (++y < map->rows)
    {
        x = -1;
        while (++x < map->cols)
        {
            if (map->map[y][x] == ft_tolower(map->me) || map->map[y][x] == map->me)
                if (check_square(map, x, y))
                {
                map->contact = 1;
                return (1);
                }
        }
    }
    return (0);
}

int static                  go_to_enemy(t_map *map, t_oken *token)
{
    if (map->player && map->rows < 90)
        return (tactic4(map, token));
    else
        return (tactic1(map, token));
    return (0);   
}

int                     play(t_map *map, t_oken *token)
{
    // if (!map->contact)
    //     is_contact(map);
    // if (map->rows > 16)
    // {
    //     return (go_to_enemy(map, token));
    // }

    if (map->player && map->rows < 90)
        return (tactic1(map, token));
    else
        return (tactic4(map, token));
    return (0);
}