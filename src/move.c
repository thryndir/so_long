/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgalloux <lgalloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 23:00:04 by lgalloux          #+#    #+#             */
/*   Updated: 2024/01/09 13:55:43 by lgalloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	my_keyhook(mlx_key_data_t keydata, void *params)
{
	size_t	x;
	size_t	y;
	t_env	*env;

	env = params;
	x = env->player.x;
	y = env->player.y;
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
	if (ft_strchr("0EC", env->map.map[x][y]))
	{
		if (env->collec.collec_cpt == env->collec.collec_nbr)
			ft_error("C'est fini !");
		if (env->map.map[x][y] == 'C')
			env->collec.collec_cpt += 1;
		if (env->map.map[env->player.x][env->player.y] == 'P')
			env->map.map[env->player.x][env->player.y] = '0';
		env->map.map[x][y] = 'P';
		env->player.x = x;
		env->player.y = y;
		env->images.player->instances[0].x = y * 32;
		env->images.player->instances[0].y = x * 32;
	}
}
