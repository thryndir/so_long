/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgalloux <lgalloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 01:40:12 by lgalloux          #+#    #+#             */
/*   Updated: 2024/01/11 12:49:39 by lgalloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_verif(t_env	*env)
{
	size_t	x;
	size_t	y;

	x = 0;
	y = 0;
	is_full(env);
	is_square(env);
	is_closed(env);
	pathway(&env->map, env->player.x, env->player.y);
	while (x < env->map.line_nbr)
	{
		if (!ft_strchr(env->map.map[x], 'E')
			&& !ft_strchr(env->map.map[x], 'C'))
			x++;
		else
			ft_error(env, "Exit or coin not accessible", 2);
	}
	return (0);
}

int	is_closed(t_env	*env)
{
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	while (i < env->map.line_nbr)
	{
		if (env->map.map[i][0] != '1'
			|| env->map.map[i][env->map.line_len - 2] != '1')
			ft_error(env, "You need a closed map on top or bottom", 2);
		i++;
	}
	while (j < env->map.line_len - 1)
	{
		if (env->map.map[0][j] != '1'
			|| env->map.map[env->map.line_nbr - 1][j] != '1')
			ft_error(env, "You need a closed map on the sides", 2);
		j++;
	}
	return (0);
}

int	is_full(t_env	*env)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < env->map.line_nbr)
	{
		j = 0;
		while (env->map.map[i][j] != '\n' && env->map.map[i][j] != '\0')
		{
			if (env->map.map[i][j] == '1' || env->map.map[i][j] == 'C'
				|| env->map.map[i][j] == '0')
				j++;
			else if (env->map.map[i][j] == 'E' || env->map.map[i][j] == 'P')
			{
				j++;
				env->map.ep++;
			}
			else
				ft_error(env, "unknown item used in map", 2);
		}
		i++;
	}
	if (env->map.ep != 2)
		ft_error(env, "There is too much or not enough exit or player", 2);
	return (0);
}

int	is_square(t_env	*env)
{
	size_t	i;

	i = 0;
	while (i < env->map.line_nbr)
	{
		if (i == env->map.line_nbr - 1)
		{
			if (ft_strlen(env->map.map[i]) == env->map.line_len - 1)
				return (0);
			else
				ft_error(env, "You need a square map", 2);
		}
		else if (ft_strlen(env->map.map[i]) != env->map.line_len)
			ft_error(env, "You need a square map", 2);
		i++;
	}
	return (0);
}

void	pathway(t_map *map, size_t x, size_t y)
{
	if (ft_strchr("0EC", map->map[x][y]))
		map->map[x][y] *= -1;
	if (ft_strchr("0EC", map->map[x + 1][y]))
		pathway(map, x + 1, y);
	if (ft_strchr("0EC", map->map[x][y + 1]))
		pathway(map, x, y + 1);
	if (ft_strchr("0EC", map->map[x - 1][y]))
		pathway(map, x - 1, y);
	if (ft_strchr("0EC", map->map[x][y - 1]))
		pathway(map, x, y - 1);
}
