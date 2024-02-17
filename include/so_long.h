/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgalloux <lgalloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 18:20:08 by lgalloux          #+#    #+#             */
/*   Updated: 2024/02/16 17:58:40 by lgalloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include "MLX42.h"
# include "libft.h"

typedef struct s_map
{
	size_t		line_len;
	size_t		line_nbr;
	char		**map;
	int			ep;
}	t_map;

typedef struct s_texture
{
	mlx_texture_t	*ground;
	int				g_bool;
	mlx_texture_t	*wall;
	int				w_bool;
	mlx_texture_t	*player;
	int				p_bool;
	mlx_texture_t	*collec;
	int				c_bool;
	mlx_texture_t	*exit;
	int				e_bool;
}	t_texture;

typedef struct s_images
{
	mlx_image_t	*ground;
	mlx_image_t	*wall;
	mlx_image_t	*player;
	mlx_image_t	*collec;
	mlx_image_t	*exit;
	size_t		y;
	size_t		x;
}	t_images;

typedef struct s_player
{
	size_t	y;
	size_t	x;
	size_t	movement;
}	t_player;

typedef struct collectibles
{
	size_t	collec_nbr;
	size_t	collec_cpt;
}	t_collectibles;

typedef struct s_exit
{
	size_t	y;
	size_t	x;
}	t_exit;

typedef struct s_env
{
	t_map			map;
	t_player		player;
	t_exit			exit;
	t_collectibles	collec;
	t_texture		texture;
	t_images		images;
	mlx_t			*mlx;
}	t_env;

void	map_init(t_env *env, char *argv);
void	pce_init(t_env *env);
void	textures_init(t_env *env);
void	count_line(t_env *env, char *argv);
void	images_init(t_env *env);
int		which_image(t_env *env, char *texture);
int		display_images(t_env *env, mlx_image_t *image, int offset);
int		map_read(t_env *env);
int		my_mlx_init(t_env *env);
int		is_closed(t_env *env);
int		is_full(t_env *env);
int		is_square(t_env *env);
int		map_verif(t_env *env);
void	ft_error(t_env *env, char *error, int nbr);
void	pathway(t_map *map, size_t y, size_t x);
void	my_keyhook(mlx_key_data_t keydata, void *params);
void	player_move(t_env *env, size_t y, size_t x);
void	ft_quit(t_env *env, int nbr);
void	del_textures(t_env *env);

#endif