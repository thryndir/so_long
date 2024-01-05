/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgalloux <lgalloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 01:40:12 by lgalloux          #+#    #+#             */
/*   Updated: 2024/01/05 18:01:11 by lgalloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"

/*Empecher les .txt*/

int	ft_verif(t_env	*env)
{
	size_t	x;
	size_t	y;

	x = 0;
	y = 0;
	is_full(&env->map);
	is_square(&env->map);
	is_closed(&env->map);
	pathway(&env->map, env->player.x, env->player.y);
	while (x < env->map.line_nbr)
	{
		if (!ft_strchr(env->map.map[x], 'E') 
			&& !ft_strchr(env->map.map[x], 'C'))
			x++;
		else
			ft_error("Exit or coin not accessible");
	}
	return (0);
}

int	is_closed(t_map	*map)
{
	size_t i;
	size_t j;

	j = 0;
	i = 0;
	while (i < map->line_nbr)
	{
		if (map->map[i][0] != '1' 
			|| map->map[i][map->line_len - 2] != '1')
			ft_error("You need a closed map on top or bottom");
		i++;
	}
	while (j < map->line_len - 1)
	{
		if (map->map[0][j] != '1' 
			|| map->map[map->line_nbr - 1][j] != '1')
			ft_error("You need a closed map on the sides");
		j++;
	}
	return (0);
}

int	is_full(t_map	*map)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < map->line_nbr)
	{
		j = 0;
		while (map->map[i][j] != '\n' && map->map[i][j] != '\0')
		{
			if (map->map[i][j] == '1' || map->map[i][j] == 'C' 
				|| map->map[i][j] == '0')
				j++;
			else if (map->map[i][j] == 'E' || map->map[i][j] == 'P')
			{
				j++;
				map->ep++;
			}
			else
				ft_error("unknown item used in map");
		}
		i++;
	}
	if (map->ep != 2)
		ft_error("There is too much or not enough exit or player");
	return (0);
}

int	is_square(t_map	*map)
{
	size_t	i;

	i = 0;
	while (i < map->line_nbr)
	{
		if (i == map->line_nbr - 1)
		{
			if (ft_strlen(map->map[i]) == map->line_len - 1)
				return (0);
			else
				ft_error("You need a square map");
		}
		else if (ft_strlen(map->map[i]) != map->line_len)
			ft_error("You need a square map");
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
