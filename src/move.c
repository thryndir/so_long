/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgalloux <lgalloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 23:00:04 by lgalloux          #+#    #+#             */
/*   Updated: 2024/01/10 14:01:28 by lgalloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_quit(t_env *env)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (env->map.map[x])
	{
		free(env->map.map[x]);
		x++;
	}
	free(env->map.map);
	mlx_terminate(env->mlx);
	exit(0);
}

void	my_keyhook(mlx_key_data_t keydata, void *params)
{
	size_t	x;
	size_t	y;
	t_env	*env;

	env = params;
	x = env->player.x;
	y = env->player.y;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		ft_quit(env);
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		player_move(env, x - 1, y);
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		player_move(env, x, y - 1);
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		player_move(env, x + 1, y);
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		player_move(env, x, y + 1);
}

void	player_move(t_env *env, size_t x, size_t y)
{
	// printf("%s\n", env->map.map[x]);
	if (ft_strchr("0EC", env->map.map[x][y]))
	{
		if (env->map.map[x][y] == 'E' 
			&& env->collec.collec_cpt == env->collec.collec_nbr)
				ft_quit(env);
		if (env->map.map[x][y] == 'C')
		{
			mlx_image_to_window(env->mlx, env->images.ground, y * 32, x * 32);
			env->images.ground->instances[env->images.ground->count - 1].z = 2;
			env->collec.collec_cpt++;
		}
		if (env->map.map[env->player.x][env->player.y] == 'P')
			env->map.map[env->player.x][env->player.y] = '0';
		if (env->map.map[x][y] != 'E')
			env->map.map[x][y] = 'P';
		env->player.x = x;
		env->player.y = y;
		env->images.player->instances[0].x = y * 32;
		env->images.player->instances[0].y = x * 32;
	}
}
