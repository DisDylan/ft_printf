/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoinsu <dpoinsu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 11:29:12 by dpoinsu           #+#    #+#             */
/*   Updated: 2020/12/09 16:58:37 by dpoinsu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

static ft_flags init_flags(void)
{
	ft_flags flags;

	flags.width = 0;
	flags.minus = 0;
	flags.zero = 0;
	flags.dot = 0;
	return (flags);
}

void put_item(char c, va_list arg)
{
	if (c == 'c')
		ft_putstr_fd(va_arg(arg, char *), 1);
	else if (c == 's')
		ft_putstr_fd(va_arg(arg, char *), 1);
	else if (c == 'p')
		write(1, &arg, 12);
	else if (c == 'x')
		ft_putnbr_base(va_arg(arg, int), "0123456789abcdef");
	else if (c == 'X')
		ft_putnbr_base(va_arg(arg, int), "0123456789ABCDEF");
	else if (c == 'd' || c == 'i')
		ft_putnbr_fd(va_arg(arg, int), 1);
	else if (c == 'u')
		ft_putnbr_fd(va_arg(arg, int), 1);
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
	flag_list = init_flags();
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			get_flags(args, format + i, flag_list, conversion, &i);
			if (ft_chrchr(conversion, format[i]))
			{
				put_item(format[i], args);
				res += write_and_size(args, flag_list);
				printf("VALEUR DE RES APRES WRITE: %d", res);
				i++;
			}
			else if (format[i] == '%')
			{
				ft_putchar_fd(format[i], 1);
				res++;
			}
		}
		else
		{
			write(1, &format[i], 1);
			i++;
			res++;
			printf("VALEUR DE RES APRES WRITE SANS MODULO: %d", res);
		}
	}
	va_end(args);
	return (res);
}
