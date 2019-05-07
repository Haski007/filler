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
    int             value;
    int             rows;
    int             cols;
    int             fd;
    int             my_pos_x;
    int             my_pos_y;
    int             fin_y;
    int             fin_x;
}                   t_map;

typedef struct      s_oken
{
    char            **shape;
    int             rows;
    int             cols;
}                   t_oken;

void                parse(t_map *map, t_oken *token);
void                size_of_map(char *line, t_map *map);
void                parse_enemy(t_map *map);
void                heat_map(t_map *map);
void                play(t_map *map, t_oken *token);




void                paint_map(t_map *map);
void                paint_heat(t_map *map);

#endif