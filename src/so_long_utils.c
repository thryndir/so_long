/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgalloux <lgalloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 01:40:12 by lgalloux          #+#    #+#             */
/*   Updated: 2023/12/30 12:53:46 by lgalloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"

char	*verif_border(t_map info, char **string, int srchar)
{
	int i;
	int oscill;

	i = 0;
	oscill = 0;
	while (string[i][oscill] == srchar)
	{
		oscill = 0;
		if (string[i][oscill] != (unsigned char)srchar)
			return (NULL);
		oscill = info.line_len;
		if (string[i][oscill] != (unsigned char)srchar)
			return (NULL);
		i++;
	}
	if (string[i][oscill] != (unsigned char)srchar)
		return (NULL);
	return (string[i]);
}

char	*as_long_as(const char *string, int src_char)
{
	while (*string != '\0')
	{
		if (*string != (unsigned char)src_char)
			return (NULL);
		string++;
	}
	if (*string == (const char)src_char)
		return ((char *)string);
	return (NULL);
}

int    count_side(t_map info, int j)
{
	size_t i;

	i = 0;
	while (i <= info.line_nbr && info.map[i][j] != '\0')
		i++;
	if (i == info.line_nbr)
		return (1);
	else
		return (0);
}