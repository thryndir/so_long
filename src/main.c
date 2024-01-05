/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgalloux <lgalloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 19:12:06 by lgalloux          #+#    #+#             */
/*   Updated: 2024/01/05 19:00:42 by lgalloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"

int	main(int argc, char **argv)
{
	t_env	env;
	(void)argc;
	map_init(&env, argv[1]);
	ft_verif(&env);
	ft_initialize(&env);
	reading_map(&env);
	mlx_loop(env.mlx);
}
