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

void         size_of_map(char *line, t_map *map)
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

void                parse_map(t_map *map, t_oken *token)
{
    int     i;
    char    *line;
    char    *tmp;

    i = 0;
    map->fd = (!map->fd) ? open("../test.txt", O_RDONLY) : map->fd;
    map->map = malloc(sizeof(map->map) * map->rows);
    while (get_next_line(map->fd, &line))
    {
        // printf("%s\n", line);
        if (line[0] >= '0' && line[0] <= '9')
        {
            map->map[i] = ft_strjoin(line + 4, "\n");
            // printf("%s", map->map[i]);
            i++;
        }
        free(line);
    }
    printf("rows = %d\ncols = %d\n", map->rows, map->cols);
}