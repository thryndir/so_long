/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgalloux <lgalloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 18:20:08 by lgalloux          #+#    #+#             */
/*   Updated: 2024/01/10 13:23:48 by lgalloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdio.h>
# include <unistd.h>
# include "MLX42.h"
# include "libft.h"


typedef struct s_map
{
	size_t line_len;
	size_t line_nbr;
	char **map;
	int	ep;
} t_map;

typedef struct s_texture
{
	mlx_texture_t	*ground;
	mlx_texture_t	*wall;
	mlx_texture_t	*player;
	mlx_texture_t	*collec;
	mlx_texture_t	*exit;
} t_texture;

typedef struct s_images
{
	mlx_image_t	*ground;
	mlx_image_t	*wall;
	mlx_image_t	*player;
	mlx_image_t	*collec;
	mlx_image_t	*exit;
	size_t x;
	size_t	y;
} t_images;

typedef struct s_player
{
	size_t x;
	size_t	y;
	size_t	movement;
} t_player;

typedef struct collectibles
{
	size_t collec_nbr;
	size_t collec_cpt;
} t_collectibles;

typedef struct s_exit
{
	size_t x;
	size_t y;
} t_exit;

typedef struct s_env
{
	struct	s_map map;
	t_player player;
	t_exit	exit;
	t_collectibles collec;
	t_texture texture;
	t_images	images;
	mlx_t	*mlx;
} t_env;

int	map_init(t_env *env, char *argv);
void	pce_init(t_env *env);
void	textures_init(t_env *env);
void	images_init(t_env *env);
int	which_texture(t_env *env, char *texture);
int	ft_create_texture(t_env *env, mlx_image_t *image, int offset);
int	map_read(t_env *env);
int	my_mlx_init(t_env *env);
int	is_closed(t_map *map);
int	is_full(t_map *map);
int	is_square(t_map *map);
int	map_verif(t_env *env);
void	ft_error(char *error);
void	pathway(t_map *map, size_t x, size_t y);
void	my_keyhook(mlx_key_data_t keydata, void *params);
void	player_move(t_env *env, size_t x, size_t y);

#endif