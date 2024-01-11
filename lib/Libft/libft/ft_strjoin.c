/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgalloux <lgalloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 15:29:17 by lgalloux          #+#    #+#             */
/*   Updated: 2023/12/30 16:26:35 by lgalloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *str1, const char *str2)
{
	char	*result;
	int		strs_len;
	int		str1_len;
	int		str2_len;

	str1_len = ft_strlen(str1);
	str2_len = ft_strlen(str2);
	strs_len = str1_len + str2_len;
	result = malloc((strs_len + 1));
	if (result == NULL)
		return (NULL);
	ft_strlcpy(result, str1, str1_len + 1);
	ft_strlcat(result, str2, strs_len + 1);
	free((void *)str1);
	return (result);
}

/*int	main(void)
{
	char *str1 = "Les tests";
	char *str2 = "du codeur";
	printf("%s\n", ft_strjoin(str1, str2));
}*/