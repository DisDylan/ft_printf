/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoinsu <dpoinsu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 11:29:12 by dpoinsu           #+#    #+#             */
/*   Updated: 2020/12/07 11:51:22 by dpoinsu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_isdigit(format)
{
	while isdigit
		i *= 10 + format i
	return i
}

int	get_flags(va_list args, const char *format, ft_flags flags, char *conversion)
{
	int i;

	i = 0;
	while (!(ft_chrchr(conversion, format[i])))
	{
		if (format[i] == '-')
			ft_flags.minus = 1;
		else if (format[i] == '0')
			i++;
			ft_flags.zero = ft_isdigit(format + i);
		else if (format[i] == '.')
			i++;
			ft_flags.dot = ft_isdigit(format + i);
		else if (format[i] == '*')
		// GETARG
		else
			i++;
		
	}
}

static void put_item(char c, va_list arg)
{
	if (c == 'c')
		ft_putchar(arg);
	else if (c == 's')
		ft_putstr(arg);
	else if (c == 'p')
		write(1, &arg, 12);
	else if (c == 'x')
		ft_putnbr_base(arg, "0123456789abcdef");
	else if (c == 'X')
		ft_putnbr_base(arg, "0123456789ABCDEF");
	else if (c == 'd' || c == 'i')
		ft_putnbr(arg);
	else if (c == 'u')
		ft_putnbr((unsigned int)arg);
}

static int ft_chrchr(const char *str, char c)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	ft_printf(const char *format, ...)
{
	// FLAGS "-0"
	// PRECISION ".*"
	va_list args;
	char *conversion;
	int i;
	ft_flags flag_list;

	conversion = "cspdiuxX";
	i = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			get_flags(args, format + i, flag_list, conversion);
			i++;
			if (ft_chrchr(conversion, format[i]))
				put_item(format[i], args);
			else if (format[i] == '%')
				ft_putchar(format[i]);
		}
		write(1, &format[i], 1);
		i++;
	}
	va_end(args);
}
