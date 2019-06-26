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
                dprintf(2, " %d ", map->heat[y][x]);
            else
                dprintf(2, "%d ", map->heat[y][x]);
            x++;
        }
        dprintf(2, "\n");
        y++;
    }
}

void                paint_token(t_oken *token)
{
    int     i = 0;

    while (i < token->rows)
    {
        dprintf(2, "%s\n", token->shape[i]);
        i++;
    }
    dprintf(2, "--------------------------\n");
}

void                paint_map(t_map *map)
{
    int i = 0;

    while(i < map->rows)
    {
        dprintf(2, "%s\n", map->map[i]);
        i++;
    }
    dprintf(2, "----------------------------\n");
}

static void         end_game(t_map *map)
{
    int         i;

    i = -1;
    while (++i < map->rows)
    {
        map->map[i] = NULL;
        free(map->map[i]);
    }
    free(map->map);
    map->map = NULL;
    ft_putstr("0 0\n");
    exit(1);
}

static void          ready(t_map *map, t_oken *token)
{
    int i;

    ft_putnbr(map->fin_y);
    ft_putchar(' ');
    ft_putnbr(map->fin_x);
    ft_putchar('\n');
    i = -1;
    while (++i < token->rows)
        ft_strdel(&token->shape[i]);
    free(token->shape);
    token->shape = NULL;
}

static void             size_of_map(char *line, t_map *map)
{
    int     i;
    char    *tmp;

    i = 0;
    tmp = line + 8;
    map->rows = ft_atoi(tmp);
    while (tmp[i] >= '0' && tmp[i] <= '9')
        i++;
    map->cols = ft_atoi(tmp + i);
}

static void         map_info(t_map *map)
{
    char    *line;
    int     i;

    while (get_next_line(map->fd, &line) > 0)
    {
        if (ft_strstr(line, "p1 : [./pdemian.filler"))
            map->player = 1;
        else if (ft_strstr(line, "Plateau"))
        {
            size_of_map(line, map);
            ft_strdel(&line);
            break ;
        }
        ft_strdel(&line);
    }
    map->map = (char**)malloc(sizeof(char*) * map->rows + 1);
    map->map[map->rows] = NULL;
    i = -1;
    while (++i < map->rows)
        map->map[i] = (char*)malloc(sizeof(char) * map->cols + 1);
    map->heat = (int**)malloc(sizeof(int*) * map->rows);
    i = -1;
    while (++i < map->rows)
        map->heat[i] = malloc(sizeof(int) * map->cols);
    map->me = (map->player) ? "Oo" : "Xx";
    map->en = (map->player) ? "Xx" : "Oo";
}

int                 main(void)
{
    t_oken      token;
    t_map       map;
    int         i = -1;

    ft_bzero(&map, sizeof(t_map));
    ft_bzero(&token, sizeof(t_oken));
    map.fd = 0;
    // map.fd = open("test.txt", O_RDONLY);
    map_info(&map);
    while (1)
    {
        get_parse(&map, &token);
        heat_map(&map);
        // paint_heat(&map);
        if (play(&map, &token))
            ready(&map, &token);
        else
            end_game(&map);
    }
    // system("leaks pdemian.filler");
    return (0);
}