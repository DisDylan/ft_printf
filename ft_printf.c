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
}