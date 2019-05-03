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
    char    *str;
    int     i;

    i = -1;
    token->shape = (char **)malloc(sizeof(char*) * token->rows + 1);
    token->shape[token->cols] = NULL;
    while (++i < token->rows)
        token->shape[i] = ft_strnew(token->cols);
    i = 0;
    while (get_next_line(map->fd, &str))
    {
        if (str[0] == '.' || str[0] == '*')
        {
            token->shape[i] = ft_strjoin(str, "\n");
            i++;
        }
        else
        {       
            free(str);
            break ;
        }
        free(str);
    }
    system("leaks a.out");
    exit(1);
    // i = -1;
    // while (++i < token->rows)
    //     printf("%s", token->shape[i]);
}

static void             size_of_token(char *line, t_oken *token)
{
    line += 6;
    token->rows = ft_atoi(line);
    while (*line >= '0' && *line <= '9')
        line++;
    token->cols = ft_atoi(line);
}

void                    size_of_map(char *line, t_map *map)
{
    int     i;
    char    *tmp;

    while (get_next_line(map->fd, &line))
    {
        if (ft_strnequ(line, "Plateau", 7))
        {
            i = 0;
            tmp = line + 8;
            free(line);
            map->rows = ft_atoi(tmp);
            while (tmp[i] >= '0' && tmp[i] <= '9')
                i++;
            map->cols = ft_atoi(tmp + i);
            break ;
        }
        free(line);
    }
}

void                parse(t_map *map, t_oken *token)
{
    int     i;
    char    *line;
    char    *tmp;

    i = 0;
    map->fd = (!map->fd) ? open("../test.txt", O_RDONLY) : map->fd;
    map->map = (char **)malloc(sizeof(char *) * map->rows + 1);
	map->map[map->rows] = NULL;
    while (get_next_line(map->fd, &line))
    {
        if (line[0] >= '0' && line[0] <= '9')
        {
            map->map[i] = ft_strjoin(line + 4, "\n");
            i++;
        }
        if (line[0] == 'P')
        {
            size_of_token(line, token);
            get_token(map, token);
            free(line);
            break ;
        }
        free(line);
    }
    // printf("rows = %d\ncols = %d\n", map->rows, map->cols);
}