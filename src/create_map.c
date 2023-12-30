/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgalloux <lgalloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 16:17:09 by lgalloux          #+#    #+#             */
/*   Updated: 2023/12/30 12:53:31 by lgalloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"

static void error(void)
{
	fprintf(stderr, "%s", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

mlx_t	*ft_initialize(t_map info)
{
	info.mlx = mlx_init(WIDTH, HEIGHT, "so_long", true);
	if (!info.mlx)
		error();
	return (info.mlx);
}

int	ft_create_texture(t_map info, char *image)
{
	mlx_texture_t* texture = mlx_load_png(image);
	if (!texture)
        	error();
	mlx_image_t* img = mlx_texture_to_image(info.mlx, texture);
	if (!img)
		error();
	if (mlx_image_to_window(info.mlx, img, 0, 0) < 0)
        	error();
	mlx_loop(info.mlx);
	return (0);
}

int	which_texture(t_map info, char texture)
{
	if (texture == '0')
		ft_create_texture(info, "./sprites/tiles/ground.png");
	if (texture == '1')
		ft_create_texture(info, "./sprites/tiles/wall.png");
	if (texture == 'C')
		ft_create_texture(info, "./sprites/tiles/ground.png");
	if (texture == 'E')
		ft_create_texture(info, "./sprites/tiles/door.png");
	if (texture == 'P')
		ft_create_texture(info, "./sprites/tiles/ground.png");
	if (texture == '\n')
		printf("%d", '\n');
	return (0);
}

int	reading_map(t_map info)
{
	int	i;
	int	j;
	i = 0;
	j = 0;
	while (info.map[i])
	{
		while (info.map[i][j])
		{
			which_texture(info, info.map[i][j]);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}
