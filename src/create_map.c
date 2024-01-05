/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgalloux <lgalloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 16:17:09 by lgalloux          #+#    #+#             */
/*   Updated: 2024/01/05 19:24:53 by lgalloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"

void ft_error(char *error)
{
	ft_printf("Error: %s\n", error);
	exit(EXIT_FAILURE);
}

int	ft_initialize(t_env *env)
{
	env->mlx = mlx_init(WIDTH, HEIGHT, "so_long", true);
	if (!env->mlx)
		ft_error("Error when initializing");
	return (0);
}

int	ft_create_texture(t_env *env, char *image)
{
	mlx_texture_t* texture = mlx_load_png(image);
	if (!texture)
        ft_error("Error when creating texture");
	mlx_image_t* img = mlx_texture_to_image(env->mlx, texture);
	if (!img)
		ft_error("Error when creating image");
	if (mlx_image_to_window(env->mlx,
		img, env->texture.y * 32, env->texture.x * 32) < 0)
        ft_error("Error when exporting image to window");
	return (0);
}

int	which_texture(t_env *env, char texture)
{
	if (texture < 0)
		texture *= -1;
	if (texture == '0')
		ft_create_texture(env, "./sprites/tiles/ground.png");
	if (texture == '1')
		ft_create_texture(env, "./sprites/tiles/wall.png");
	if (texture == 'C')
		ft_create_texture(env, "./sprites/tiles/ground.png");
	if (texture == 'E')
		ft_create_texture(env, "./sprites/tiles/door.png");
	if (texture == 'P')
	{
		ft_create_texture(env, "./sprites/tiles/ground.png");
		ft_create_texture(env, "./sprites/hero/idle/idle-knight-r-1.png");
	}
	return (0);
}

int	reading_map(t_env *env)
{
	size_t	x;
	int	y;
	x = 0;
	while (x < env->map.line_nbr)
	{
		y = 0;
		while (env->map.map[x][y])
		{
			env->texture.x = x;
			env->texture.y = y;
			which_texture(env, env->map.map[x][y]);
			y++;
		}
		x++;
	}
	return (0);
}
