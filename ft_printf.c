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

void put_item(char c, va_arg)
{
	if (c == 'c')
		ft_putchar(1, va_arg, 1);
	else if (c == 's')
		ft_putstr(1, va_arg, ft_strlen(va_arg));
	else if (c == 'p')
		ft_puthexa(1, va_arg, ???);
	else if (c == 'd' || c == 'i')
		ft_putnbr(1, va_arg, ft_strlen(ft_itoa(va_arg)));
	else if (c == 'u')
		ft_putnbr(1, (unsigned int)va_arg, ft_strlen(ft_itoa(va_arg)));
	else if (c == 'x' || c == 'X')
		ft_puthexa(1, va_arg, ???);
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
	// FLAGS -0.*
	const char *conversion;
	int i;

	conversion = "cspdiuxX";
	i = 0;
	/*
		while s[i] // Tant qu'il y a un truc dans la string
			if s[i] == '%' // si le char est un modulo
				i++;
				if flag = strschr(s, *FLAGS) != NULL // Si une des str de FLAGS est -> string
					i += ft_strlen(flag)
				if strchr(s, CONVERSION) // Si un des char de conversion est dans la string
					check(s[i], va_list) // On va checker a quoi correspond le caractère et 						faire un put_str/putchar/putnbr ect.
			write(1, s[i], 1); // On écrit le char
			i++;
	*/
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (ft_chrchr(conversion, format[i]))
				/*put_item*/(format[i], va_arg);
			else if (format[i] == '%')
				ft_putchar(format[i]);
		}
		write(1, &format[i], 1);
		i++;
	}
}