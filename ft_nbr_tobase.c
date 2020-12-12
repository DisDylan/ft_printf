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

static int	is_neg(unsigned int *nb, int *nbr)
{
	if (*nbr < 0)
	{
		*nbr *= -1;
		*nb *= -1;
		return (1);
	}
	return (0);
}

static void ft_ret_space(char *str)
{
	int i;
	char *tmp;

	while (str[i] != ' ')
		i++;
	tmp = (char*)malloc(sizeof(char*) * i);
	i = 0;
	while (str[i] != ' ')
	{
		tmp[i] = str[i];
		i++;
	}
	free(str);
	str = ft_strdup(tmp);
	free(tmp);
}

char	*ft_nbr_tobase(int nbr, char *base)
{
	int				i;
	int				len;
	int				nb_final[50];
	unsigned int	nb;
	char			*str;

	i = -1;
	len = 0;
	nb = nbr;
	str = (char*)malloc(sizeof(str) * (int)ft_strlen(ft_itoa(nb)));
	while (base[len])
		len++;
	while (nb)
	{
		nb_final[++i] = nb % len;
		nb /= len;
	}
	len = -1;
	is_neg(&nb, &nbr);
	while (i >= 0)
	{
		str[++len] = base[nb_final[i]];
		printf("str.len == %c && base.nb.i == %c\n", str[len], base[nb_final[i]]);
		printf("str entier vaut : %s!\n", str);
		i--;
	}
	printf("Valeur de x : |%s|", str);
	return (str);
}