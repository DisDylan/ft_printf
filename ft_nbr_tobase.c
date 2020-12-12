/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoinsu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 14:07:25 by dpoinsu           #+#    #+#             */
/*   Updated: 2020/07/16 15:24:20 by dpoinsu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

char	*ft_nbr_tobase(int nbr, char *base)
{
	int				i;
	int				len;
	int				nb_final[50];
	char			*str;

	i = -1;
	len = (int)ft_strlen(ft_itoa((unsigned int)nbr)) + 1;
	printf("value len : %d\n", len);
	str = (char*)malloc(sizeof(char) * len);
	printf("str vaut [%s]\n", str);
	len = 0;
	while (base[len])
		len++;
	while ((unsigned int)nbr)
	{
		nb_final[++i] = (unsigned int)nbr % len;
		(unsigned int)nbr /= len;
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