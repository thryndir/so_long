/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgalloux <lgalloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 19:12:06 by lgalloux          #+#    #+#             */
/*   Updated: 2024/02/15 18:34:10 by lgalloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_env	env;
	int		i;

	i = ft_strlen(argv[1]);
	if (argc != 2)
		ft_error(&env, "Invalid arguments", 0);
	while (argv[1][i] != '.')
	{
		if (!ft_strchr("ber", argv[1][i]))
			ft_error(&env, "You need a .ber map", 0);
		i--;
	}
	map_init(&env, argv[1]);
	map_verif(&env);
	map_read(&env);
	mlx_key_hook(env.mlx, my_keyhook, &env);
	mlx_loop(env.mlx);
	ft_quit(&env, 2);
}
