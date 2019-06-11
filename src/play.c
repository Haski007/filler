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
    int     a = 0;

    on = 0;
    if (token->cols + x  > map->cols || token->rows + y > map->rows)
        return (0);
    j = -1 + token->up;
    while (++j < token->rows)
    {
        i = -1 + token->left;
        while (++i < token->cols)
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

int                     play(t_map *map, t_oken *token)
{
    // dprintf(2, "me_y = %d\nme_x = %d\n", map->me_y, map->me_x);
    // dprintf(2, "---------------------\n");
    // dprintf(2, "enemy_y = %d\nenemy_x = %d\n", map->enemy_y, map->enemy_x);
    // dprintf(2, "me_y = %d\nme_x = %d\n", map->me_y, map->me_x);
    if (map->me_y < map->enemy_y && map->me_x < map->cols / 2)
        return (tactic4(map, token));
    else if (map->me_y < map->enemy_y && map->me_x >= map->cols / 2)
        return (for_balance3(map, token));
    else if (map->me_y >= map->enemy_y && map->me_x < map->cols / 2)
        return (for_balance2(map, token));
    else if (map->me_y >= map->enemy_y && map->me_x >= map->cols / 2)
        return (tactic1(map, token));
    // dprintf(2, "rows =%d\ncols = %d\n", token->rows, token->cols);
    return (0);
    // dprintf(2, "err_y = %d\nerr_x = %d\n", token->err_y, token->err_x);
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