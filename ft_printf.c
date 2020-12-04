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

void ft_puthexa(va_list va_arg, char c)
{

}

void put_item(char c, va_list va_arg)
{
	if (c == 'c')
		ft_putchar(va_arg);
	else if (c == 's')
		ft_putstr(va_arg);
	else if (c == 'p' || c == 'x' || c == 'X')
		ft_puthexa(va_arg, c);
	else if (c == 'd' || c == 'i')
		ft_putnbr(va_arg);
	else if (c == 'u')
		ft_putnbr((unsigned int)va_arg);
}

int ft_chrchr(const char *str, char c)
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
	// va_list
	// va_start

	// char *flag
	// va_end
	// CONVERSION cspdiuxX%
		/*
			c = int en unsigned char (putchar)
			s = const char * (putstr)
			p = void * (PUTHEXA)
			d-i = int (putnbr)
			u = unsigned int (putnbr)
			x-X = unsigned hexadecimal (abcde-ABCDE) (PUTHEXA)
			% = affiche %
		*/
	// %[parameter][flags][width][.precision][length]type
	// FLAGS "-0"
	// PRECISION ".*"
	va_list *args;
	const char *conversion;
	int i;

	conversion = "cspdiuxX";
	i = 0;
	va_start(args, format)
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
}