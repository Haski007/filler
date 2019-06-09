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

static void             go_to_enemy(t_map *map)
{
}

int                    valid_token(t_map *map, t_oken *token, int x, int y)
{
    int     j;
    int     i;
    int     on;
    int     a = 0;

    j = -1;
    on = 0;
    while (++j < token->rows)
    {
        i = -1;
        while (++i < token->cols)
        {
            printf("%d\n", ++a);
            if (token->shape[j][i] == '*' && (!map->map[y + j][x + i]
            || map->map[y + j][x + i] == map->enemy
            || map->map[y + j][x + i] == ft_tolower(map->enemy)))
                return (0);
            else if (token->shape[j][i] == '*' &&
            (map->map[y + j][x + i] == map->me ||
            map->map[y + j][x + i] == ft_tolower(map->me)))
                on++;
        }
    }
    if (on == 1)
        return(1);
    return (0);
}

static void             find_error(t_oken *token)
{
    int     i;
    int     j;

    j = -1;
    while (++j < token->rows)
    {
        i = -1;
        while (++i < token->cols)
        {
            if (token->shape[j][i] == '*')
            {
                token->err_x = i;
                token->err_y = j;
                // paint_token(token);                
                return ;
            }
        }
    }
}

int                     play(t_map *map, t_oken *token)
{
    int     i;

    i = 0;
    // dprintf(2, "____________________\n");
    while (tactic1(map, token) == 1)
        get_map(map, token);
    // dprintf(2, "rows =%d\ncols = %d\n", token->rows, token->cols);
    return (0);
    // dprintf(2, "err_y = %d\nerr_x = %d\n", token->err_y, token->err_x);
    // dprintf(2, "me_y = %d\nme_x = %d\n", map->me_y, map->me_x);
    // map->fin_y = map->me_y - token->err_y;
    // map->fin_x = map->me_x - token->err_x;
    // while (!(valid_token(map, token)))
    // {
    //     find_error(token);
    //     map->fin_y = map->me_y - token->err_y;
    //     map->fin_x = map->me_x - token->err_x;
    // }
    // dprintf(2, "--------------------\n");
    // ft_free_arr(&map->map);
    // ft_free_arr(&token->shape);
}