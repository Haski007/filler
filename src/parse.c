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

        token->shape = (char **)malloc(sizeof(char*) * token->rows + 1);
        token->shape[token->cols] = NULL;
    i = -1;
    j = -1;
    while (1)
    {
            // dprintf(2, "\nHUI\n");
        if (get_next_line(map->fd, &line) < 1)
            break ;
            // dprintf(2, "\npizda\n");
        if (line[0] >= '0' && line[0] <= '9')
            ft_strcpy(map->map[++i], line + 4);
        else if (ft_strstr(line, "Piece"))
        {
            size_of_token(line, token);
            ft_strdel(&line);
        }
        else if (line[0] == '.' || line[0] == '*')
        {
            token->shape[++j] = ft_strdup(line);
            if (j == token->rows - 1)
            {
                ft_strdel(&line);
                break ;
            }
        }
        ft_strdel(&line);
    }
    // dprintf(2, "\npizda\n");

    // paint_map(map);
    // paint_token(token);
    get_real_token(token);
    heat_map(map);
    // parse_enemy(map);
    if (!map->me_x)
    {
        get_my_pos(map);
    }
}