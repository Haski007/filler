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

typedef struct	s_map
{
	char		**map;
	int			**heat;
	char		player;
	char		*me;
	char		*en;
	int			rows;
	int			cols;
	int			fin_y;
	int			fin_x;
}				t_map;

typedef struct	s_oken
{
	char		**shape;
	int			rows;
	int			cols;
	int			up;
	int			left;
	int			down;
	int			right;
}				t_oken;

void			get_parse(t_map *map, t_oken *token);
void			parse_enemy(t_map *map);
void			heat_map(t_map *map);
int				play(t_map *map, t_oken *token);
void			get_real_token(t_oken *token);

#endif
