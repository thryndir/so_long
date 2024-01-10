/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgalloux <lgalloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 16:17:09 by lgalloux          #+#    #+#             */
/*   Updated: 2024/01/10 14:03:03 by lgalloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void ft_error(char *error)
{
	ft_printf("Error: %s\n", error);
	exit(EXIT_FAILURE);
}

int	ft_create_texture(t_env *env, mlx_image_t *image, int offset)
{
	if (mlx_image_to_window(env->mlx, image,
	env->images.y * 32 + offset, env->images.x * 32) < 0)
        ft_error("Error when exporting image to window");
	image->instances[image->count - 1].z = 0;
	return (0);
}

int	which_texture(t_env *env, char *texture)
{
	if (*texture < 0)
		*texture *= -1;
	if (*texture == '0')
		ft_create_texture(env, env->images.ground, 0);
	if (*texture == '1')
		ft_create_texture(env, env->images.wall, 0);
	if (*texture == 'C')
	{
		ft_create_texture(env, env->images.ground, 0);
		ft_create_texture(env, env->images.collec, 8);
		env->images.collec->instances[env->images.collec->count - 1].z = 1;
	}
	if (*texture == 'E')
		ft_create_texture(env, env->images.exit, 0);
	if (*texture == 'P')
	{
		ft_create_texture(env, env->images.ground, 0);
		ft_create_texture(env, env->images.player, 0);
		env->images.player->instances[env->images.player->count - 1].z = 3;
	}
	return (0);
}

int	map_read(t_env *env)
{
	size_t	x;
	int	y;
	x = 0;
	while (x < env->map.line_nbr)
	{
		y = 0;
		while (env->map.map[x][y])
		{
			env->images.x = x;
			env->images.y = y;
			which_texture(env, &env->map.map[x][y]);
			y++;
		}
		x++;
	}
	return (0);
}
