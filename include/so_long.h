/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgalloux <lgalloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 18:20:08 by lgalloux          #+#    #+#             */
/*   Updated: 2023/12/30 12:50:28 by lgalloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# define WIDTH 500
# define HEIGHT 500

# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <stdarg.h>
# include <fcntl.h>
# include <unistd.h>
# include "MLX42.h"
# include "libft.h"

typedef struct s_map
{
	size_t line_len;
	size_t line_nbr;
	int	fd;
	char **map;
	mlx_t *mlx;
} t_map;

char	*get_next_line(int fd);
size_t	ft_strlen(const char *str);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
char	*ft_strjoin(const char *str1, const char *str2);
char	*ft_strchr(const char *string, int searchedChar);
size_t	ft_parsing(t_map info, char *argv);
int	which_texture(t_map info, char texture);
int	reading_map(t_map info);
mlx_t	*ft_initialize(t_map info);
char	*verif_border(t_map info, char **string, int srchar);
char	*as_long_as(const char *string, int src_char);
int		count_side(t_map info, int j);
int		ft_verif(t_map info);

#endif
