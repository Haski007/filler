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

static void         size_of_map(char *line, t_map *map)
{
    line = line + 8;
    map->rows = ft_atoi(line);
    printf("%s\n", line + 11);
    system("leaks a.out");
}

void                parse_map(t_map *map, t_oken *token)
{
    int     fd;
    int     i;
    char    *line;
    char    *tmp;

    i = 0;
    if (!(fd = open("../test.txt", O_RDONLY)))
        printf("Fuck off man, it does not open\n");
    while (get_next_line(fd, &line))
    {
        if (ft_strnequ(line, "Plateau", 7))
        {
            size_of_map(line, map);
            break ;
        }
        free(line);
    }
    map->map = malloc(sizeof(map->map) * map->rows);
    while (get_next_line(fd, &line))
    {
        if (line[0] >= '0' && line[0] <= '9')
        {
            tmp = line;
            map->map[i] = ft_strjoin(line + 4, "\n");
            // printf("%s", map->map[i]);
            i++;
        }
       free(line);
    }
    printf("rows = %d\ncols = %d", map->rows, map->cols);
    i = 0;
    while(map->map[i])
    {
        printf("%s", map->map[i]);
        i++;
    }
}