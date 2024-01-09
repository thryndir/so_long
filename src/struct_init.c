/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgalloux <lgalloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 19:29:39 by lgalloux          #+#    #+#             */
/*   Updated: 2024/01/09 13:28:39 by lgalloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"

int	map_init(t_env *env, char *argv)
{
	size_t	j;
	int	fd;
	env->map.ep = 0;

	fd = open(argv, O_RDONLY);
	env->map.line_nbr = 0;
	while (get_next_line(fd))
		env->map.line_nbr++;
	close(fd);
	if (env->map.line_nbr == 0)
		ft_error("Empty file");
	env->map.map = malloc((env->map.line_nbr + 1) * sizeof(char *));
	if (!env->map.map)
		ft_error("Malloc failed");
	j = 0;
	fd = open(argv, O_RDONLY);
	while (j <= env->map.line_nbr)
		env->map.map[j++] = get_next_line(fd);
	env->map.line_len = ft_strlen(env->map.map[0]);
	close(fd);
	pce_init(env);
	my_mlx_init(env);
	textures_init(env);
	return(0);
}

int	my_mlx_init(t_env *env)
{
	size_t	width;
	size_t	height;

	width = (env->map.line_len -1) * 32;
	height = env->map.line_nbr * 32;
	env->mlx = mlx_init(width, height, "so_long", true);
	if (!env->mlx)
		ft_error("Error when initializing");
	return (0);
}

void pce_init(t_env *env)
{
	size_t	x;
	size_t	y;

	x = 0;
	while (x < env->map.line_nbr)
	{
		y = 0;
		while (env->map.map[x][y] != '\n' && env->map.map[x][y] != '\0')
		{
			if (env->map.map[x][y] == 'P')
				{
					env->player.x = x;
					env->player.y = y;
				}
			else if (env->map.map[x][y] == 'E')
				{
					env->exit.x = x;
					env->exit.y = y;
				}
				else if (env->map.map[x][y] == 'E')
					env->collec.collec_nbr++;
			y++;
		}
		x++;
	}
}

void	textures_init(t_env *env)
{
	env->texture.ground = mlx_load_png("./sprites/tiles/ground.png");
	if (!env->texture.ground)
		ft_error("Error when creating texture 0");
	env->texture.wall = mlx_load_png("./sprites/tiles/wall.png");
	if (!env->texture.wall)
        ft_error("Error when creating texture 1");
	env->texture.player = mlx_load_png
	("./sprites/hero/idle/idle-knight-r-1.png");
	if (!env->texture.player)
        ft_error("Error when creating texture 2");
	env->texture.exit = mlx_load_png("./sprites/tiles/door.png");
	if (!env->texture.exit)
        ft_error("Error when creating texture 3");
	env->texture.collec = mlx_load_png("./sprites/collectibles/axe.png");
	if (!env->texture.collec)
        ft_error("Error when creating texture 4");
	images_init(env);
}
void	images_init(t_env *env)
{
	env->images.ground = mlx_texture_to_image(env->mlx, env->texture.ground);
	if (!env->images.ground)
		ft_error("Error when creating image 0");
	env->images.wall = mlx_texture_to_image(env->mlx, env->texture.wall);
	if (!env->images.wall)
		ft_error("Error when creating image 1");
	env->images.player = mlx_texture_to_image (env->mlx, env->texture.player);
	if (!env->images.player)
		ft_error("Error when creating image 2");
	env->images.exit = mlx_texture_to_image(env->mlx, env->texture.exit);
	if (!env->images.exit)
		ft_error("Error when creating image 3");
	env->images.collec = mlx_texture_to_image(env->mlx, env->texture.collec);
	if (!env->images.collec)
		ft_error("Error when creating image 4");
}
