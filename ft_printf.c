/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoinsu <dpoinsu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 11:29:12 by dpoinsu           #+#    #+#             */
/*   Updated: 2020/12/08 15:19:12 by dpoinsu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void put_item(char c, va_list arg, const char *str)
{
	if (c == 'c')
		ft_putchar(va_arg(str, char));
	else if (c == 's')
		ft_putstr(va_arg(str, char*));
	else if (c == 'p')
		write(1, &arg, 12);
	else if (c == 'x')
		ft_putnbr_base(va_arg(str, char*), "0123456789abcdef");
	else if (c == 'X')
		ft_putnbr_base(va_arg(str, char*) "0123456789ABCDEF");
	else if (c == 'd' || c == 'i')
		ft_putnbr(va_arg(str, int));
	else if (c == 'u')
		ft_putnbr(va_arg(str, unsigned int));
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
