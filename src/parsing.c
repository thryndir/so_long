/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgalloux <lgalloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 19:29:39 by lgalloux          #+#    #+#             */
/*   Updated: 2023/12/30 12:53:34 by lgalloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"

size_t	ft_parsing(t_map info, char *argv)
{
	size_t	j;
	int	fd;
	size_t	line_nbr;

	fd = open(&argv[1], O_RDONLY);
	line_nbr = 0;
	while (get_next_line(fd))
		line_nbr++;
	close(fd);
	info.map = malloc(info.line_nbr * sizeof(char *) + 1);
	if (!info.map)
		return (0);
	j = 0;
	fd = open(&argv[1], O_RDONLY);
	while (j <= line_nbr)
		info.map[j++] = get_next_line(fd);
	info.line_len = ft_strlen(info.map[0]);
	close(fd);
	return(line_nbr);
}

int	ft_verif(t_map info)
{
	if (ft_strlen(info.map[0]) != ft_strlen(info.map[info.line_nbr]))
		ft_printf("You need a square map");
	if (count_side(info, 0) == '0' || count_side(info, info.line_len) == '0')
		ft_printf("You need a square map");
	if (!as_long_as(info.map[0], '1') || !as_long_as(info.map[info.line_nbr], '1'))
		ft_printf("You need a closed map");
	if (verif_border(info, info.map, '1'))
		ft_printf("You need a closed map");
	return (0);
}