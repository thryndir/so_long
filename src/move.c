/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgalloux <lgalloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 23:00:04 by lgalloux          #+#    #+#             */
/*   Updated: 2024/02/16 17:53:12 by lgalloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	del_textures(t_env *env)
{
	if (env->texture.g_bool == 1)
		mlx_delete_texture(env->texture.ground);
	if (env->texture.w_bool == 1)
		mlx_delete_texture(env->texture.wall);
	if (env->texture.p_bool == 1)
		mlx_delete_texture(env->texture.player);
	if (env->texture.e_bool == 1)
		mlx_delete_texture(env->texture.exit);
	if (env->texture.c_bool == 1)
		mlx_delete_texture(env->texture.collec);
}

void	ft_quit(t_env *env, int nbr)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (env->map.map[y])
	{
		free(env->map.map[y]);
		y++;
	}
	free(env->map.map);
	if (nbr >= 2)
	{
		mlx_terminate(env->mlx);
		if (nbr >= 3)
			del_textures(env);
	}
	exit(EXIT_SUCCESS);
}

void	my_keyhook(mlx_key_data_t keydata, void *params)
{
	size_t	y;
	size_t	x;
	t_env	*env;

	env = params;
	y = env->player.y;
	x = env->player.x;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(env->mlx);
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		player_move(env, y - 1, x);
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		player_move(env, y, x - 1);
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		player_move(env, y + 1, x);
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		player_move(env, y, x + 1);
}

void	player_move(t_env *env, size_t y, size_t x)
{
	if (ft_strchr("0EC", env->map.map[y][x]))
	{
		if (env->map.map[y][x] == 'E'
			&& env->collec.collec_cpt == env->collec.collec_nbr)
			mlx_close_window(env->mlx);
		if (env->map.map[y][x] == 'C')
		{
			mlx_image_to_window(env->mlx, env->images.ground, x * 32, y * 32);
			env->images.ground->instances[env->images.ground->count - 1].z = 2;
			env->collec.collec_cpt++;
		}
		if (env->map.map[env->player.y][env->player.x] == 'P')
			env->map.map[env->player.y][env->player.x] = '0';
		if (env->map.map[y][x] != 'E')
			env->map.map[y][x] = 'P';
		env->player.y = y;
		env->player.x = x;
		env->images.player->instances[0].x = x * 32;
		env->images.player->instances[0].y = y * 32;
		ft_printf("%d\n", (int)env->player.movement);
		env->player.movement++;
	}
}
