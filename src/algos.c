/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algos.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdemian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 17:28:26 by pdemian           #+#    #+#             */
/*   Updated: 2019/06/09 17:28:28 by pdemian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static int			valid_token(t_map *map, t_oken *token, int x, int y)
{
	int j;
	int i;
	int on;

	if (token->right + 1 + x - token->left > map->cols ||
	token->down + 1 - token->up + y > map->rows)
		return (0);
	on = 0;
	j = -1 + token->up;
	while (++j < token->down + 1)
	{
		i = -1 + token->left;
		while (++i < token->right + 1)
		{
			if (token->shape[j][i] == '*' &&
			(map->map[y + j - token->up][x + i - token->left] == map->en[0] ||
			map->map[y + j - token->up][x + i - token->left] == map->en[1]))
				return (0);
			else if (token->shape[j][i] == '*' &&
			(map->map[y + j - token->up][x + i - token->left] == map->me[0] ||
			map->map[y + j - token->up][x + i - token->left] == map->me[1]))
				on++;
		}
	}
	return ((on == 1) ? 1 : 0);
}

static int			tactic1(t_map *map, t_oken *token)
{
	int x;
	int y;
	int value;

	value = 999;
	y = -1;
	while (++y < map->rows)
	{
		x = -1;
		while (++x < map->cols)
		{
			if (valid_token(map, token, x, y) && map->heat[y][x] <= value)
			{
				map->fin_x = x - token->left;
				map->fin_y = y - token->up;
				value = map->heat[y][x];
			}
		}
	}
	if (value == 999)
		return (0);
	return (1);
}

static int			tactic4(t_map *map, t_oken *token)
{
	int x;
	int y;
	int value;

	value = 999;
	y = map->rows - 1;
	while (--y > 0)
	{
		x = map->cols - 1;
		while (--x > 0)
		{
			if (valid_token(map, token, x, y) && map->heat[y][x] <= value)
			{
				map->fin_x = x - token->left;
				map->fin_y = y - token->up;
				value = map->heat[y][x];
			}
		}
	}
	if (value == 999)
		return (0);
	return (1);
}

int					play(t_map *map, t_oken *token)
{
	token->down = 0;
	token->right = 0;
	get_real_token(token);
	if (map->player && map->rows < 90)
		return (tactic1(map, token));
	else
		return (tactic4(map, token));
	return (0);
}
