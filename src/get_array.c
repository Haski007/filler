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

static void            get_token(t_map *map, t_oken *token)
{
    char    *line;
    int     i;
    int     j;

    i = -1;
    token->shape = (char **)malloc(sizeof(char*) * token->rows + 1);
    token->shape[token->cols] = NULL;
    i = -1;
    while (++i < token->rows)
    {
        get_next_line(map->fd, &line);
        dprintf(2, "%s\n", line);
        token->shape[i] = ft_strjoin(line, "\n");
        free(line);
    }
    j = -1;
    while (++j < token->rows)
    {
        i = -1;
        while (++i < token->cols)
        {
            if (token->shape[j][i] == '*')
            {
                token->err_x = i;
                token->err_y = j;
                // paint_token(token);                
                return ;
            }
        }
    }
    // printf("\n----------------\n");
    // paint_token(token);
    // printf("----------------\n");
    // printf("err_x = %d\nerr_y = %d\n", token->err_y, token->err_x);
}

static void             size_of_token(char *line, t_oken *token)
{
    line += 6;
    token->rows = ft_atoi(line);
    while (*line >= '0' && *line <= '9')
        line++;
    token->cols = ft_atoi(line);
}


void                parse(t_map *map, t_oken *token)
{
    int     i;
    char    *line;
    char    *tmp;

    i = 0;
    // map->fd = (!map->fd) ? open("../test.txt", O_RDONLY) : map->fd;
    if (!map->map)
    {
        map->map = (char **)malloc(sizeof(char *) * map->rows + 1);
	    map->map[map->rows] = NULL;
    }
    // printf("\n\n\nHUI\n\n\n");
    while (get_next_line(map->fd, &line) > 0)
    {
        if (line[0] >= '0' && line[0] <= '9')
        {
            map->map[i] = ft_strjoin(line + 4, "\n");
            i++;
        }
        if (line[0] == 'P')
        {
            ft_bzero(token, sizeof(t_oken));
            size_of_token(line, token);
            free(line);
            get_token(map, token);
            break ;
        }
        free(line);
    }
    // ft_putchar('\n');
    // paint_map(map);
    // system("leaks a.out");
    heat_map(map);
    play(map, token);
    // printf("rows = %d\ncols = %d\n", map->rows, map->cols);
}