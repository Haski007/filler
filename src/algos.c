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

static int                    valid_token(t_map *map, t_oken *token, int x, int y)
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
            (map->map[y + j - token->up][x + i - token->left] == map->enemy[0]
            || map->map[y + j - token->up][x + i - token->left] == map->enemy[1]))
                return (0);
            else if (token->shape[j][i] == '*' &&
            (map->map[y + j - token->up][x + i - token->left] == map->me[0] ||
            map->map[y + j - token->up][x + i - token->left] == map->me[1]))
                on++;
        }
    }
    if (on == 1)
        return(1);
    return (0);
}

int                tactic1(t_map *map, t_oken *token)
{
    int     x;
    int     y;

    y = -1;
    while (++y < map->rows)
    {
        x = -1;
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

int                tactic4(t_map *map, t_oken *token)
{
    int     x;
    int     y;
    
    y = map->rows - 1;
    while (--y > 0)
    {
        x = map->cols - 1;
        while (--x > 0)
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