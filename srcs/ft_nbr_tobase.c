/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoinsu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 14:07:25 by dpoinsu           #+#    #+#             */
/*   Updated: 2021/01/05 16:41:00 by dpoinsu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_nbr_tobase(unsigned long long nbr,
		char *base)
{
	int					i;
	int					len;
	int					nb_final[50];
	char				*str;

	i = -1;
	len = (int)ft_strlen(ft_itoa(nbr)) + 1;
	str = (char*)malloc(sizeof(char) * len);
	len = 0;
	while (base[len])
		len++;
	while (nbr)
	{
		nb_final[++i] = nbr % len;
		nbr /= len;
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
