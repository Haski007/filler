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
// #include "heat_map.c"
// #include "play.c"
// #include "get_array.c"
// #include "../libft/get_next_line.c"
// #include "../libft/ft_strlen.c"
// #include "../libft/ft_bzero.c"
// #include "../libft/ft_numlen.c"
// #include "../libft/ft_strnew.c"
// #include "../libft/ft_lstadd.c"
// #include "../libft/ft_lstnew.c"
// #include "../libft/ft_memalloc.c"
// #include "../libft/ft_strchr.c"
// #include "../libft/ft_strdup.c"
// #include "../libft/ft_strjoin.c"
// #include "../libft/ft_memcpy.c"
// #include "../libft/ft_memset.c"
// #include "../libft/ft_strcat.c"
// #include "../libft/ft_strcpy.c"
// #include "../libft/ft_free_arr.c"
// #include "../libft/ft_strnequ.c"
// #include "../libft/ft_strncmp.c"
// #include "../libft/ft_atoi.c"
// #include "../libft/ft_tolower.c"
// #include "../libft/ft_putchar.c"
// #include "../libft/ft_putnbr.c"
// #include "../libft/ft_strstr.c"

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

void         paint_token(t_oken *token)
{
    int     i = 0;

    while (i < token->rows)
    {
        dprintf(2, "%s", token->shape[i]);
        i++;
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

static void         size_of_map(char *line, t_map *map)
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

static void         map_info(char *line, t_map *map)
{
    if (ft_strnequ(line, "$$$ exec p1 : [./pdemian", 24))
        map->player = 1;
    while (get_next_line(map->fd, &line))
    {
        if (line[0] == 'P')
        {
            size_of_map(line, map);
            // free(line);
            break ;
        }
        // free(line);
    }
    map->me = (map->player) ? 'O' : 'X';
    map->enemy = (map->player) ? 'X' : 'O';
}

int                 main(void)
{
    t_oken      token;
    t_map       map;
    char        *line;
    int         i = 0;

    ft_bzero(&map, sizeof(t_map));
    map.fd = 0;
    // map.fd = open("test.txt", O_RDONLY);
    while (1)
    {
        if (!(get_next_line(map.fd, &line)))
            break ;
        if (ft_strstr(line, "$$$"))
        {
            map_info(line, &map);
        }
        else if (ft_strstr(line, "01234567890123"))
        {
            parse(&map, &token);
        }
        free(line);
    }
    // paint_map(&map);
    // paint_heat(&map);
    // paint_token(token);
    // system("leaks a.out");
    // exit(1);
    return (0);
}