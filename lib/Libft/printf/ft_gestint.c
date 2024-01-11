/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gestint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgalloux <lgalloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 13:37:18 by lgalloux          #+#    #+#             */
/*   Updated: 2023/12/30 12:47:58 by lgalloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printnbr(int nb)
{
	long	l_nb;
	int		cpt_nbr;
	int		minus;

	l_nb = nb;
	cpt_nbr = 1;
	minus = 0;
	if (l_nb < 0)
	{
		l_nb = l_nb * -1;
		write(1, "-", 1);
		minus = 1;
		cpt_nbr++;
	}
	if (l_nb > 9)
	{
		cpt_nbr = ft_printnbr(l_nb / 10) + 1 + minus;
	}
	write(1, &(char){l_nb % 10 + '0'}, 1);
	return (cpt_nbr);
}

int	ft_printunbr_base(unsigned int nb, char *base)
{
	long	l_nb;
	int		cpt_nbr;
	int		len;

	l_nb = nb;
	cpt_nbr = 1;
	len = ft_strlen(base);
	if (l_nb > len - 1)
	{
		cpt_nbr = ft_printunbr_base(l_nb / len, base) + 1;
	}
	write(1, &(char){base[l_nb % len]}, 1);
	return (cpt_nbr);
}
