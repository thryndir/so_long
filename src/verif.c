/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgalloux <lgalloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 01:40:12 by lgalloux          #+#    #+#             */
/*   Updated: 2024/02/16 17:52:54 by lgalloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_verif(t_env	*env)
{
	size_t	y;
	size_t	x;

	y = 0;
	x = 0;
	is_full(env);
	is_square(env);
	is_closed(env);
	pathway(&env->map, env->player.y, env->player.x);
	while (y < env->map.line_nbr)
	{
		if (!ft_strchr(env->map.map[y], 'E')
			&& !ft_strchr(env->map.map[y], 'C'))
			y++;
		else
			ft_error(env, "Exit or coin not accessible", 2);
	}
	if (env->collec.collec_nbr == 0)
		ft_error(env, "Not enough collectibles", 2);
	return (0);
}

int	is_closed(t_env	*env)
{
	size_t	y;
	size_t	x;

	x = 0;
	y = 0;
	while (y < env->map.line_nbr)
	{
		if (env->map.map[y][0] != '1'
			|| env->map.map[y][env->map.line_len - 2] != '1')
			ft_error(env, "You need a closed map on the sides", 2);
		y++;
	}
	while (x < env->map.line_len - 1)
	{
		if (env->map.map[0][x] != '1'
			|| env->map.map[env->map.line_nbr - 1][x] != '1')
			ft_error(env, "You need a closed map on the sides", 2);
		x++;
	}
	return (0);
}

int	is_full(t_env	*env)
{
	size_t	y;
	size_t	x;

	y = 0;
	while (y < env->map.line_nbr)
	{
		x = 0;
		while (env->map.map[y][x] != '\n' && env->map.map[y][x] != '\0')
		{
			if (env->map.map[y][x] == '1' || env->map.map[y][x] == 'C'
				|| env->map.map[y][x] == '0')
				x++;
			else if (env->map.map[y][x] == 'E' || env->map.map[y][x] == 'P')
			{
				x++;
				env->map.ep++;
			}
			else
				ft_error(env, "unknown item used in map", 2);
		}
		y++;
	}
	if (env->map.ep != 2)
		ft_error(env, "There is too much or not enough exit or player", 2);
	return (0);
}

int	is_square(t_env	*env)
{
	size_t	y;

	y = 0;
	while (y < env->map.line_nbr)
	{
		if (y == env->map.line_nbr - 1)
		{
			if (ft_strlen(env->map.map[y]) == env->map.line_len - 1)
				return (0);
			else
				ft_error(env, "You need a square map", 2);
		}
		else if (ft_strlen(env->map.map[y]) != env->map.line_len)
			ft_error(env, "You need a square map", 2);
		y++;
	}
	return (0);
}

void	pathway(t_map *map, size_t y, size_t x)
{
	if (ft_strchr("0EC", map->map[y][x]))
		map->map[y][x] *= -1;
	if (ft_strchr("0EC", map->map[y + 1][x]))
		pathway(map, y + 1, x);
	if (ft_strchr("0EC", map->map[y][x + 1]))
		pathway(map, y, x + 1);
	if (ft_strchr("0EC", map->map[y - 1][x]))
		pathway(map, y - 1, x);
	if (ft_strchr("0EC", map->map[y][x - 1]))
		pathway(map, y, x - 1);
}
