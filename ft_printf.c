/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoinsu <dpoinsu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 11:29:12 by dpoinsu           #+#    #+#             */
/*   Updated: 2020/12/02 11:30:32 by dpoinsu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void put_item(char c, va_list arg)
{
	if (c == 'c')
		ft_putchar(va_arg);
	else if (c == 's')
		ft_putstr(va_arg);
	else if (c == 'p')
		write(1, &va_arg, 12);
	else if (c == 'x')
		ft_putnbr_base(va_arg, "0123456789abcdef");
	else if (c == 'X')
		ft_putnbr_base(va_arg, "0123456789ABCDEF");
	else if (c == 'd' || c == 'i')
		ft_putnbr(va_arg);
	else if (c == 'u')
		ft_putnbr((unsigned int)va_arg);
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

	conversion = "cspdiuxX";
	i = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (ft_chrchr(conversion, format[i]))
				put_item(format[i], va_arg);
			else if (format[i] == '%')
				ft_putchar(format[i]);
		}
		write(1, &format[i], 1);
		i++;
	}
	va_end(args)
}