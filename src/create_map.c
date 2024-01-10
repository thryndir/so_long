/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgalloux <lgalloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 16:17:09 by lgalloux          #+#    #+#             */
/*   Updated: 2024/01/10 19:10:12 by lgalloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void ft_error(t_env *env, char *error, int nbr)
{
	ft_printf("Error: %s\n", error);
	if (nbr >= 1)
		ft_quit(env, nbr);
	exit(EXIT_FAILURE);
}

int	my_mlx_init(t_env *env)
{
	size_t	width;
	size_t	height;

	width = (env->map.line_len -1) * 32;
	height = env->map.line_nbr * 32;
	env->mlx = mlx_init(width, height, "so_long", true);
	if (!env->mlx)
		ft_error(env, "Error when initializing", 2);
	return (0);
}

int	display_images(t_env *env, mlx_image_t *image, int offset)
{
	if (mlx_image_to_window(env->mlx, image,
	env->images.y * 32 + offset, env->images.x * 32) < 0)
        ft_error(env, "Error when exporting image to window", 2);
	image->instances[image->count - 1].z = 0;
	return (0);
}

int	which_image(t_env *env, char *texture)
{
	if (*texture < 0)
		*texture *= -1;
	if (*texture == '0')
		display_images(env, env->images.ground, 0);
	if (*texture == '1')
		display_images(env, env->images.wall, 0);
	if (*texture == 'C')
	{
		display_images(env, env->images.ground, 0);
		display_images(env, env->images.collec, 8);
		env->images.collec->instances[env->images.collec->count - 1].z = 1;
	}
	if (*texture == 'E')
		display_images(env, env->images.exit, 0);
	if (*texture == 'P')
	{
		display_images(env, env->images.ground, 0);
		display_images(env, env->images.player, 0);
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
			which_image(env, &env->map.map[x][y]);
			y++;
		}
		x++;
	}
	return (0);
}
