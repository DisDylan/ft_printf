/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoinsu <dpoinsu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 11:29:12 by dpoinsu           #+#    #+#             */
/*   Updated: 2020/12/09 14:40:00 by dpoinsu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

static char *fill_zero(char *tmp, int zero)
{
	int newsize;
	char *str;

	str = tmp;
	newsize = zero - ft_strlen(tmp);
	while (newsize > 0)
	{
		write(1, "0", 1);
		str[ft_strlen(str) - 1] = '0';
		newsize--;
	}
	return (str);
}

static char *fill_width(char *tmp, int width)
{
	int newsize;
	char *str;

	str = tmp;
	newsize = width - (int)ft_strlen(tmp);
	while (newsize > 0)
	{
		write(1, " ", 1);
		str[ft_strlen(str) - 1] = ' ';
		newsize--;
	}
	return (str);
}

static char *trunc_word(char *tmp, int limit)
{
	int i;
	char *str;

	i = 0;
	str = "";
	while (i < limit)
	{
		str[i] = tmp[i];
		i++;
	}
	return (str);
}

int	write_and_size(va_list arg, ft_flags flags, char c)
{
	int i;
	char *tmp;
	char *str;

	if (c == 's')
		str = va_arg(arg, char*);
	else if (c == 'c')
		str = va_arg(arg, char);
	else
		str = va_arg(arg, int);
	printf("\n\n!!!!! Valeur de str: %s\n\n", str);
	if (flags.minus == 1)
	{
		tmp = str;
	}
	if (flags.width > 0)
		tmp = fill_width(tmp, flags.width);
	if (flags.zero > 0)
		tmp = fill_zero(tmp, flags.zero);
	if (flags.dot > 0)
		tmp = trunc_word(tmp, flags.dot);
	if (flags.minus == 0)
		tmp = ft_strjoin(tmp, str);
	i = ft_strlen(tmp);
	printf("CONTENU DE TMP: %s\n", tmp);
	printf("VALEUR DE I W&S: %d\n", i);
	return(i);
}
