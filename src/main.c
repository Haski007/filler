/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdemian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 21:55:32 by pdemian           #+#    #+#             */
/*   Updated: 2019/04/20 21:55:33 by pdemian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void                paint_map(t_map *map)
{
    int i = 0;

    while(i < map->rows)
    {
        printf("%s", map->map[i]);
        i++;
    }
}

static void         learn_map(t_map *map)
{
    int     i;
    char    *line;

    i = 0;
    map->fd = open("../test.txt", O_RDONLY);
    while (get_next_line(map->fd, &line))
    {
        map->player = (ft_strnequ(line, "$$$ exec p1 : [./pdemian", 24)) ? 1 : 0;
        if (line[0] == '$')
        {
            free(line);
            break ;
        }
        free(line);
    }
    size_of_map(line, map);
}

int                 main(void)
{
    t_oken      token;
    t_map       map;
    int         i = 0;

    learn_map(&map);
    parse_map(&map, &token);
    parse_enemy(&map);
    heat_map(&map);
    paint_map(&map);
    printf("Enemy position:\nx = %d\ny = %d\n", map.e_start_x, map.e_start_y);
    // system("leaks a.out");
    return (0);
}