/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgalloux <lgalloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 19:12:06 by lgalloux          #+#    #+#             */
/*   Updated: 2024/01/11 12:54:49 by lgalloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_env	env;

	(void)argc;
	map_init(&env, argv[1]);
	map_verif(&env);
	map_read(&env);
	mlx_key_hook(env.mlx, my_keyhook, &env);
	mlx_loop(env.mlx);
	ft_quit(&env, 2);
}
