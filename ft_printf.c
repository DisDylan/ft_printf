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

static int put_item(char c, va_list arg)
{
	char *str;
	int nb;

	nb = 0;
	str = NULL;
	if (c == 'c' || c == 's')
		str = va_arg(arg, char*);
	else if (c == 'p')
		nb = va_arg(arg, int);
	else if (c == 'x')
		str = ft_itoa(va_arg(arg, int));
	//ft_putnbr_base(va_arg(arg, int), "0123456789abcdef");
	else if (c == 'X')
		str = ft_itoa(va_arg(arg, int));
	//ft_putnbr_base(va_arg(arg, int), "0123456789ABCDEF");
	else if (c == 'd' || c == 'i')
		str = ft_itoa(va_arg(arg, int));
	else if (c == 'u')
		str = ft_itoa(va_arg(arg, unsigned int));
	if (str != NULL)
	{
		ft_putstr_fd(str, 1);
		return ((int)ft_strlen(str));
	}
	ft_putnbr_fd(nb, 1);
	return ((int)ft_strlen(ft_itoa(nb)));
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
				res += put_item(format[i], args);
				//res += write_and_size(args, flag_list, format[i]);
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
		}
	}
	va_end(args);
	return (res);
}
