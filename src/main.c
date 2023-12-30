/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgalloux <lgalloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 19:12:06 by lgalloux          #+#    #+#             */
/*   Updated: 2023/12/30 12:53:37 by lgalloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"

int	main(int argc, char **argv)
{
	t_map	info;
	(void)argc;
	info.fd = 3;
	info.line_nbr = ft_parsing(info, argv[1]);
	ft_verif(info);
	ft_initialize(info);
	reading_map(info);
}
