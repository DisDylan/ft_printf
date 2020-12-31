/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoinsu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 14:07:25 by dpoinsu           #+#    #+#             */
/*   Updated: 2020/12/28 10:42:16 by dpoinsu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_nbr_tobase(int nbr, char *base)
{
	int				i;
	int				len;
	int				nb_final[50];
	unsigned int	nb;
	char			*str;

	i = -1;
	nb = nbr;
	len = (int)ft_strlen(ft_itoa(nb)) + 1;
	str = (char*)malloc(sizeof(char) * len);
	len = 0;
	while (base[len])
		len++;
	while (nb)
	{
		nb_final[++i] = nb % len;
		nb /= len;
	}
	len = 0;
	while (i >= 0)
	{
		str[len] = base[nb_final[i]];
		i--;
		len++;
	}
	return (str);
}