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

void			get_real_token(t_oken *token)
{
	int y;
	int x;

	token->left = token->cols;
	token->up = token->rows;
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

static void		size_of_token(char *line, t_oken *token)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = line + 6;
	token->rows = ft_atoi(tmp);
	while (tmp[i] >= '0' && tmp[i] <= '9')
		i++;
	token->cols = ft_atoi(tmp + i);
	token->shape = (char **)malloc(sizeof(char *) * token->rows + 1);
	token->shape[token->rows] = NULL;
	i = -1;
	while (++i < token->rows)
		token->shape[i] = (char *)malloc(sizeof(char) * token->cols + 1);
}

void			get_parse(t_map *map, t_oken *token)
{
	char	*line;
	int		i;
	int		j;

	i = -1;
	j = -1;
	while (get_next_line(0, &line) > 0)
	{
		if (line[0] == '0')
			ft_strcpy(map->map[++i], line + 4);
		else if (ft_strstr(line, "Piece"))
			size_of_token(line, token);
		else if (line[0] == '.' || line[0] == '*')
		{
			ft_strcpy(token->shape[++j], line);
			if (j == token->rows - 1)
			{
				ft_strdel(&line);
				break ;
			}
		}
		ft_strdel(&line);
	}
}
