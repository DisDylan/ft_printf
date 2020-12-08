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

static int ft_getdigits(const char *format)
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

static void	get_flags(va_list args, const char *format, ft_flags flags, char *conversion)
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
		{
			i++;
			flags.zero = ft_isdigit(format + i);
		}
		else if (format[i] == '.')
		{
			i++;
			flags.dot = ft_isdigit(format + i);
		}
		else if (format[i] == '*')
			ft_star(format, flags, i, args);
		else if (isdigit)
			flags.width = ft_getdigits(format + i);
		else
			i++;
		
	}
}

static void put_item(char c, va_list arg)
{
	if (c == 'c')
		ft_putchar(va_arg(arg, char));
	else if (c == 's')
		ft_putstr(va_arg(arg, char*));
	else if (c == 'p')
		write(1, &arg, 12);
	else if (c == 'x')
		ft_putnbr_base(va_arg(arg, char*), "0123456789abcdef");
	else if (c == 'X')
		ft_putnbr_base(va_arg(arg, char*) "0123456789ABCDEF");
	else if (c == 'd' || c == 'i')
		ft_putnbr(va_arg(arg, int));
	else if (c == 'u')
		ft_putnbr(va_arg(arg, unsigned int));
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
