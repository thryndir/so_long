/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgalloux <lgalloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 19:29:39 by lgalloux          #+#    #+#             */
/*   Updated: 2024/01/05 14:23:10 by lgalloux         ###   ########.fr       */
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
	env->map.map = malloc(env->map.line_nbr * sizeof(char *) + 1);
	if (!env->map.map)
		ft_error("Malloc failed");
	j = 0;
	fd = open(argv, O_RDONLY);
	while (j <= env->map.line_nbr)
		env->map.map[j++] = get_next_line(fd);
	env->map.line_len = ft_strlen(env->map.map[0]);
	close(fd);
	player_init(env);
	return(0);
}

int player_init(t_env *env)
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
					return (0);
				}
			y++;
		}
		x++;
	}
	return (0);
}