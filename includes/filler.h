/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdemian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 21:53:56 by pdemian           #+#    #+#             */
/*   Updated: 2019/04/20 21:54:10 by pdemian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

# include "../libft/libft.h"

typedef struct      s_map
{
    char            **map;
    int             **heat;
    char            player;
    char            me;
    char            enemy;
    int             value;
    int             rows;
    int             cols;
    int             fd;
    int             me_x;
    int             me_y;
    int             fin_y;
    int             fin_x;
}                   t_map;

typedef struct      s_oken
{
    char            **shape;
    int             rows;
    int             cols;
    int             err_y;
    int             err_x;
}                   t_oken;

void                parse(t_map *map, t_oken *token);
void                parse_enemy(t_map *map);
void                heat_map(t_map *map);
void                play(t_map *map, t_oken *token);
void                play2(t_map *map, t_oken *token);



void                paint_map(t_map *map);
void                paint_heat(t_map *map);
void                paint_token(t_oken *token);

#endif