/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoinsu <dpoinsu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 11:29:12 by dpoinsu           #+#    #+#             */
/*   Updated: 2020/12/08 15:14:50 by dpoinsu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_getdigits(const char *format)
{
	int i;
	int res;

	i = 0;
	res = 0;
	while (ft_isdigit(format[i]))
	{
		i *= 10;
		i += format[i] + 48;
	}
	return (i);
}

static void	ft_star(const char *str, ft_flags flags, int pos, va_list arg)
{
	if (str[pos - 1] == '0')
		flags.dot = va_arg(str, int);
	else if (str[pos - 1] == '%')
		flags.width = va_arg(str, int);
	else if (str[pos - 1] == '.')
		flags.width = va_arg(str, int);
}

void		get_flags(va_list args, const char *format,
		ft_flags flags, char *conversion)
{
	int i;

	i = 0;
	while (!(ft_chrchr(conversion, format[i])) && format[i])
	{
		if (format[i] == '-')
		{
			i++;
			flags.minus = 1;
		}
		else if (format[i] == '0' && format[i - 1] != '-')
			flags.zero = ft_getdigits(format + (i + 1));
		else if (format[i] == '.')
			flags.dot = ft_getdigits(format + (i + 1));
		else if (format[i] == '*')
			ft_star(format, flags, i, args);
		else if (isdigit)
			flags.width = ft_getdigits(format + (i + 1));
		i++;
	}
}
