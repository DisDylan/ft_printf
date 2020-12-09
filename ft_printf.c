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

str = flags + arg
write str
return ft_strlen(str)

static void put_item(char c, va_list arg, const char *str)
{
	if (c == 'c')
		ft_putstr(va_arg(arg, int));
	else if (c == 's')
		ft_putstr(va_arg(arg, int));
	else if (c == 'p')
		write(1, &va_arg(arg, int), 12);
	else if (c == 'x')
		ft_putnbr_base(va_arg(arg, int), "0123456789abcdef");
	else if (c == 'X')
		ft_putnbr_base(va_arg(arg, int), "0123456789ABCDEF");
	else if (c == 'd' || c == 'i')
		ft_putnbr(va_arg(arg, int));
	else if (c == 'u')
		ft_putnbr(va_arg(arg, unsigned int));
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

// Traiter la chaine
// Quand un % est rencontré, traiter la suite
// Si il y a un flag, modfier dans la structure
// Quand on rencontre un char conversion, le traiter
// AJOUTER A CHAQUE FOIS LE TOUT A UNE VAR INT pour le strlen à return