/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoinsu <dpoinsu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 11:29:12 by dpoinsu           #+#    #+#             */
/*   Updated: 2020/12/09 12:27:53 by dpoinsu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

static int	ft_getdigits(const char *format, va_list arg, int *pos)
{
	int i;
	int res;

	i = 0;
	res = 0;
	if (format[i] == '*')
		return (va_arg(arg, int));
	while (ft_isdigit(format[i]))
	{
		res *= 10;
		res += format[i] - 48;
		*pos += 1;
		i++;
	}
	return (res);
}

void		get_flags(va_list args, const char *format,
		ft_flags *flags, char *conversion, int *index)
{
	int i;

	i = 0;
	printf("format dans get flags vaut : %s\n", format);
	while (!(ft_chrchr(conversion, format[i])) && format[i])
	{
		if (format[i] == '-')
			flags->minus = 1;
		else if (format[i] == '0' && flags->minus != 1)
			flags->zero = ft_getdigits(format + (i + 1), args, &i);
		else if (format[i] == '.')
			flags->dot = ft_getdigits(format + (i + 1), args, &i);
		else if (ft_isdigit(format[i]) || format[i] == '*')
			flags->width = ft_getdigits(format + i, args, &i);
		i++;
	}
	*index += i;
}
