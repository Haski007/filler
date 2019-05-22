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

void                paint_heat(t_map *map)
{
    int y = 0;
    int x = 0;

    while (y < map->rows)
    {
        x = 0;
        while (x < map->cols)
        {
            if (ft_numlen(map->heat[y][x]) == 1 && map->heat[y][x] != -1)
                printf(" %d ", map->heat[y][x]);
            else
                printf("%d ", map->heat[y][x]);
            x++;
        }
        printf("\n");
        y++;
    }
}

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
    char    *line1;

    i = 0;
    map->fd = open("../test.txt", O_RDONLY);
    while (get_next_line(map->fd, &line1))
    {
        if (ft_strnequ(line1, "$$$ exec p1 : [./pdemian", 24))
            map->player = 1;
        if (line1[0] == '$')
        {
            free(line1);
            break ;
        }
        free(line1);
    }
    map->me = (map->player) ? 'O' : 'X';
    map->enemy = (map->player) ? 'X' : 'O';
    size_of_map(line1, map);
}

int                 main(void)
{
    t_oken      token;
    t_map       map;
    int         i = 0;

    ft_bzero(&map, sizeof(t_map));
    learn_map(&map);
    parse(&map, &token);
    // paint_map(&map);
    heat_map(&map);
    // parse_token(&token);
    paint_heat(&map);
    play(&map, &token);
    // printf("Enemy position:\nx = %d\ny = %d\n", map.e_start_x, map.e_start_y);
    // system("leaks a.out");
    // exit(1);
    return (0);
}