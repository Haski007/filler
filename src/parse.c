/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_array.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdemian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 17:21:51 by pdemian           #+#    #+#             */
/*   Updated: 2019/04/26 17:21:52 by pdemian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static void             get_my_pos(t_map *map)
{
    int     y;
    int     x;

    y = -1;
    while (++y < map->rows)
    {
        x = -1;
        while (++x < map->cols)
        {
            if (map->map[y][x] == map->enemy || map->map[y][x] == ft_tolower(map->enemy))
            {
                map->enemy_y = x;
                map->enemy_y = y;
            }
            else if (map->map[y][x] == map->me || map->map[y][x] == ft_tolower(map->me))
            {
                map->me_x = x;
                map->me_y = y;
            }
        }
    }
}


static void             get_token(t_map *map, t_oken *token)
{
    char    *line;
    int     i;

    token->shape = (char **)malloc(sizeof(char*) * token->rows + 1);
    token->shape[token->cols] = NULL;
    i = -1;
    while (++i < token->rows)
    {
        if (!(get_next_line(map->fd, &line)))
            break ;
        token->shape[i] = ft_strdup(line);
        // free(line);
    }
    // printf("\n----------------\n");
    // paint_token(token);
    // printf("----------------\n");
    // printf("err_x = %d\nerr_y = %d\n", token->err_y, token->err_x);
}

void             size_of_token(char *line, t_oken *token)
{
    line += 6;
    token->rows = ft_atoi(line);
    while (*line >= '0' && *line <= '9')
        line++;
    token->cols = ft_atoi(line);
}


void                get_map(t_map *map, t_oken *token)
{
    int     i;
    char    *line;
    char    *tmp;
    static int  fuck = 0;
    int     j = 0;

    // map->fd = (!map->fd) ? open("../test.txt", O_RDONLY) : map->fd;
    if (!map->map)
    {
        map->map = (char **)malloc(sizeof(char *) * map->rows + 1);
	    map->map[map->rows] = NULL;
    }
    // printf("\n\n\nHUI\n\n\n");
    // dprintf(2, "fuck = %d\n", ++fuck);
    i = -1;
    while (get_next_line(map->fd, &line) > 0)
    {
        if (line[0] >= '0' && line[0] <= '9')
            map->map[++i] = ft_strdup(line + 4);
        if (ft_strstr(line, "Piece"))
        {
            ft_bzero(token, sizeof(t_oken));
            size_of_token(line, token);
            get_token(map, token);
            // free(line);
            break ;
        }
        // free(line);
        j++;
    }
    if (!map->enemy_x)
        get_my_pos(map);
}