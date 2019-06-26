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

int                     play(t_map *map, t_oken *token)
{
    get_real_token(token);
    if (map->player && map->rows < 90)
        return (tactic4(map, token));
    else
        return (tactic1(map, token));
    return (0);
}