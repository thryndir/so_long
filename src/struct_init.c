/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgalloux <lgalloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 19:29:39 by lgalloux          #+#    #+#             */
/*   Updated: 2024/01/10 18:59:49 by lgalloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_init(t_env *env, char *argv)
{
	size_t	j;
	int	fd;
 
	env->map.ep = 0;
	env->collec.collec_cpt = 0;
	env->collec.collec_nbr = 0;
	env->player.movement = 0;
	count_line(env, argv);
	if (env->map.line_nbr == 0)
		ft_error(env, "Empty file", 0);
	env->map.map = malloc((env->map.line_nbr + 1) * sizeof(char *));
	if (!env->map.map)
		ft_error(env, "Malloc failed", 1);
	j = 0;
	fd = open(argv, O_RDONLY);
	while (j <= env->map.line_nbr)
		env->map.map[j++] = get_next_line(fd);
	env->map.line_len = ft_strlen(env->map.map[0]);
	close(fd);
	my_mlx_init(env);
	pce_init(env);
	textures_init(env);
}

void	count_line(t_env *env, char *argv)
{
	char	*line;
	int	fd;
	env->map.ep = 0;

	fd = open(argv, O_RDONLY);
	env->map.line_nbr = 0;
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		env->map.line_nbr++;
	}
	close(fd);
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
			else if (env->map.map[x][y] == 'C')
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
		ft_error(env, "Error when creating texture 0", 3);
	env->texture.g_bool = 1;
	env->texture.wall = mlx_load_png("./sprites/tiles/wall.png");
	if (!env->texture.wall)
        ft_error(env, "Error when creating texture 1", 3);
	env->texture.w_bool = 1;
	env->texture.player = mlx_load_png
	("./sprites/hero/idle/idle-knight-r-1.png");
	if (!env->texture.player)
        ft_error(env, "Error when creating texture 2", 3);
	env->texture.p_bool = 1;
	env->texture.exit = mlx_load_png("./sprites/tiles/door.png");
	if (!env->texture.exit)
        ft_error(env, "Error when creating texture 3", 3);
	env->texture.e_bool = 1;
	env->texture.collec = mlx_load_png("./sprites/collectibles/axe.png");
	if (!env->texture.collec)
        ft_error(env, "Error when creating texture 4", 3);
	env->texture.c_bool = 1;
	images_init(env);
}
void	images_init(t_env *env)
{
	env->images.ground = mlx_texture_to_image(env->mlx, env->texture.ground);
	mlx_delete_texture(env->texture.ground);
	if (!env->images.ground)
		ft_error(env, "Error when creating image 0", 2);
	env->images.wall = mlx_texture_to_image(env->mlx, env->texture.wall);
	mlx_delete_texture(env->texture.wall);
	if (!env->images.wall)
		ft_error(env, "Error when creating image 1", 2);
	env->images.player = mlx_texture_to_image (env->mlx, env->texture.player);
	mlx_delete_texture(env->texture.player);
	if (!env->images.player)
		ft_error(env, "Error when creating image 2", 2);
	env->images.exit = mlx_texture_to_image(env->mlx, env->texture.exit);
	mlx_delete_texture(env->texture.exit);
	if (!env->images.exit)
		ft_error(env, "Error when creating image 3", 2);
	env->images.collec = mlx_texture_to_image(env->mlx, env->texture.collec);
	mlx_delete_texture(env->texture.collec);
	if (!env->images.collec)
		ft_error(env, "Error when creating image 4", 2);
}
