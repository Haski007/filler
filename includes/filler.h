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
    char            *me;
    char            *enemy;
    int             value;
    int             rows;
    int             cols;
    int             fd;
    int             me_x;
    int             me_y;
    int             enemy_x;
    int             enemy_y;
    int             fin_y;
    int             fin_x;
}                   t_map;

typedef struct      s_oken
{
    char            **shape;
    int             rows;
    int             cols;
    int             up;
    int             left;
    int             down;
    int             right;
}                   t_oken;

void                get_parse(t_map *map, t_oken *token);
void                parse_enemy(t_map *map);
void                heat_map(t_map *map);
void                get_real_token(t_oken *token);
int                 play(t_map *map, t_oken *token);
void                size_of_token(char *line, t_oken *token);
int                tactic1(t_map *map, t_oken *token);
int                tactic4(t_map *map, t_oken *token);
int                 tactic3(t_map *map, t_oken *token);
int                 tactic2(t_map *map, t_oken *token);
void                ready(t_map *map, t_oken *token);
int                check_all(t_map *map, t_oken *token);
void                parse_enemy(t_map *map);



void                paint_map(t_map *map);
void                paint_heat(t_map *map);
void                paint_token(t_oken *token);

#endif