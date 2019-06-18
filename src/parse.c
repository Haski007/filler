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

void             malloc_map(t_map *map)
{
    int         i;

    map->map = (char **)malloc(sizeof(char *) * map->rows + 1);
	map->map[map->rows] = NULL;
    i = -1;
    while (++i < map->cols)
    {
        map->map[i] = ft_strnew(map->cols);
    }
}

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

static void             get_real_token(t_oken *token)
{
    int     y;
    int     x;

    token->left = token->cols;
    token->up = token->rows;
    token->down = 0;
    token->right = 0;
    y = -1;
    while (++y < token->rows)
    {
        x = -1;
        while (++x < token->cols)
        {
            if (token->shape[y][x] == '*')
            {
                if (x < token->left)
                    token->left = x;
                if (x > token->right)
                    token->right = x;
                if (y < token->up)
                    token->up = y;
                if (y > token->down)
                    token->down = y;
            }
        }
    }
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
    int     j;

    if (!token->shape)
    {
        token->shape = (char **)malloc(sizeof(char*) * token->rows + 1);
        token->shape[token->rows] = NULL;
    }
    i = -1;
    j = -1;
    while (get_next_line(map->fd, &line) > 0)
    {
        // dprintf(2, "j = %d\n", j);        
        if (line[0] >= '0' && line[0] <= '9')
        {
            ft_strcpy(map->map[++i], line + 4);
        }
        else if (ft_strstr(line, "Piece"))
        {
            size_of_token(line, token);
        }
        else if (line[0] == '.' || line[0] == '*')
        {
            // dprintf(2, "rows = %d\n", token->rows);
            // dprintf(2, "j = %d\n", j);
            token->shape[++j] = ft_strdup(line);
            if (j == token->rows - 1)
            {
                ft_strdel(&line);
                break ;
            }
        }
        ft_strdel(&line);
    }
    // paint_token(token);
    get_real_token(token);
    heat_map(map);
    // parse_enemy(map);
    if (!map->me_x)
    {
        get_my_pos(map);
    }
}