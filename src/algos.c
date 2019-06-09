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

    // dprintf(2, "\nHUI\n");
    y = map->rows - 1;
    while (--y > 0)
    {
        x = map->cols - 1;
        while (--x > 0)
        {
            if (valid_token(map, token, x, y))
            {
                // dprintf(2, "y = %d\nx = %d\n", map->fin_y, map->fin_x);
                map->fin_x = x;
                map->fin_y = y;
                ready(map);
                return (1);
            }
        }
    }
    return(0);
}