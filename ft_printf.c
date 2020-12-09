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

static void init_flags(ft_flags flags)
{
	flags.width = 0;
	flags.minus = 0;
	flags.zero = 0;
	flags.dot = 0;
}

void put_item(char c, va_list arg)
{
	if (c == 'c')
		ft_putstr(arg);
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
		ft_putnbr(arg);
}

int	ft_printf(const char *format, ...)
{
	va_list args;
	char *conversion;
	int i;
	ft_flags flag_list;
	int res;

	conversion = "cspdiuxX";
	i = 0;
	res = 0;
	init_flags(flag_list);
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			get_flags(args, format + i, flag_list, conversion, &i);
			if (ft_chrchr(conversion, format[i]))
				write_and_size(args, flag_list, format[i]);
			else if (format[i] == '%')
				ft_putchar(format[i]);
		}
		write(1, &format[i], 1);
		i++;
	}
	va_end(args);
}