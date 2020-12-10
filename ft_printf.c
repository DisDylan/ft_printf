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

static char *put_item(char c, va_list arg)
{
	char *str;
	int nb;
	char ch;

	nb = 0;
	str = NULL;
	ch = 0;
	// FONCTION CHECK CHARS && CHECK INT && CHECK BASE
	if (c == 'c')
		ch = va_arg(arg, int);
	if (c == 's')
		str = va_arg(arg, char*);
	else if (c == 'p')
		nb = va_arg(arg, int);
	else if (c == 'x')
		str = ft_itoa(va_arg(arg, int));
	//str = ft_nbr_base(va_arg(arg, int), "0123456789abcdef");
	else if (c == 'X')
		str = ft_itoa(va_arg(arg, int));
	//str = ft_nbr_base(va_arg(arg, int), "0123456789ABCDEF");
	else if (c == 'd' || c == 'i')
		str = ft_itoa(va_arg(arg, int));
	else if (c == 'u')
		str = ft_itoa(va_arg(arg, unsigned int));
	if (str != NULL)
		return (str);
	//if (ch != 0)
	//	return (ch);
	return (ft_itoa(nb));
}

int	ft_printf(const char *format, ...)
{
	va_list args;
	char *conversion;
	int i;
	ft_flags flag_list;
	int res;
	char *printit;

	printit = NULL;
	conversion = "cspdiuxX";
	i = 0;
	res = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			flag_list = init_flags();
			get_flags(args, format + i, &flag_list, conversion, &i);
			//printf("\n\nFLAGS VALUE:\n------%d dot %d width %d zero\n", flag_list.dot, flag_list.width, flag_list.zero);
			if (ft_chrchr(conversion, format[i]))
			{
				printit = put_item(format[i], args);
				printit = write_and_size(printit, flag_list);
				res += ft_strlen(printit);
				ft_putstr_fd(printit, 1);
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
