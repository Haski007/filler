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
// #include "parse.c"
// #include "algos.c"
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
// #include "../libft/ft_putstr.c"
// #include "../libft/ft_strdel.c"
// #include "enemy.c"

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
        printf("%s\n", map->map[i]);
        i++;
    }
}

static void         end_game(t_map *map, t_oken *token)
{
    int         i;

    i = -1;
    while (++i < map->rows)
        ft_strdel(&map->map[i]);
    map->map = NULL;
    ft_putstr("0 0\n");
    exit(0);
}

void                ready(t_map *map, t_oken *token)
{
    int         i;

    ft_putnbr(map->fin_y);
    ft_putchar(' ');
    ft_putnbr(map->fin_x);
    ft_putchar('\n');
    map->me_x = map->fin_x;
    map->me_y = map->fin_y;
    i = -1;
    // while (++i < token->rows)
    //     ft_strdel(&token->shape[i]);
    // free(token->shape);
    // dprintf(2, "rows = %d\n", token->rows);
    // paint_token(token);
    // token->shape = NULL;
    // dprintf(2, "rows = %d", token->rows);
    // token->shape = NULL;
    // system("leaks pdemian.filler");
    // exit(1);
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
    int i;

    if (ft_strnequ(line, "$$$ exec p1 : [./pdemian", 24))
        map->player = 1;
    while (get_next_line(map->fd, &line))
    {
        if (line[0] == 'P')
        {
            size_of_map(line, map);
            ft_strdel(&line);
            break ;
        }
        ft_strdel(&line);
    }
    map->map = (char **)malloc(sizeof(char *) * map->rows + 1);
	map->map[map->rows] = NULL;
    i = -1;
    while (++i < map->rows)
        map->map[i] = ft_strnew(map->cols);
    map->map[i] = NULL;
    map->me = (map->player) ? 'O' : 'X';
    map->enemy = (map->player) ? 'X' : 'O';
}

int                 main(void)
{
    t_oken      token;
    t_map       map;
    char        *line;
    int         i = -1;

    ft_bzero(&map, sizeof(t_map));
    ft_bzero(&token, sizeof(t_oken));
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
            ft_strdel(&line);
            while (1)
            {
                get_map(&map, &token);
                if (play(&map, &token))
                    ready(&map, &token);
                else
                    if (check_all(&map, &token))
                        ready(&map, &token);
                    else
                        end_game(&map, &token);
            }
        }
        ft_strdel(&line);
    }
    return (0);
}