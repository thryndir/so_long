/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgalloux <lgalloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 19:12:06 by lgalloux          #+#    #+#             */
/*   Updated: 2024/02/16 17:53:26 by lgalloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_env	env;
	int		x;

	if (argc != 2)
		ft_error(&env, "Invalid arguments", 0);
	x = ft_strlen(argv[1]);
	while (argv[1][x] != '.')
	{
		if (!ft_strchr("ber", argv[1][x]))
			ft_error(&env, "You need a .ber map", 0);
		x--;
	}
	map_init(&env, argv[1]);
	map_verif(&env);
	map_read(&env);
	mlx_key_hook(env.mlx, my_keyhook, &env);
	mlx_loop(env.mlx);
	ft_quit(&env, 2);
}
