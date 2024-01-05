/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgalloux <lgalloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 18:20:08 by lgalloux          #+#    #+#             */
/*   Updated: 2024/01/05 18:37:47 by lgalloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# define WIDTH 500
# define HEIGHT 500

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
	size_t x;
	size_t	y;
} t_texture;

typedef struct s_player
{
	size_t x;
	size_t	y;
} t_player;

typedef struct s_env
{
	struct	s_map map;
	t_player player;
	t_texture texture;
	mlx_t	*mlx;
} t_env;

int	map_init(t_env *env, char *argv);
int	which_texture(t_env *env, char texture);
int	ft_create_texture(t_env *env, char *image);
int	reading_map(t_env *env);
int	ft_initialize(t_env *env);
int	is_closed(t_map *map);
int	is_full(t_map *map);
int	is_square(t_map *map);
int	ft_verif(t_env *env);
void	ft_error(char *error);
void	pathway(t_map *map, size_t x, size_t y);
int	player_init(t_env *env);

#endif