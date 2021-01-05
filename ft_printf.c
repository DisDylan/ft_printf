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
	flags.dot = -1;
	flags.star = 0;
	flags.type = 0;
	return (flags);
}

int			ft_treat_all(const char *format, va_list arguments)
{
	int			i;
	ft_flags		flags;
	int			char_count;

	i = 0;
	char_count = 0;
	while (format[i])
	{
		flags = init_flags();
		if (format[i] == '%')
		{
			i++;
			i = ft_get_flag(format, i, arguments, &flags);
			if (ft_chrchr(format[i]))
				char_count += ft_treat_convert((char)flags.type, flags, arguments);
			else if (save[i])
				char_count += ft_putchar_fd(format[i], 1);
		}
		else if (save[i] != '%')
			char_count += ft_putchar_fd(format[i], 1);
		i++;
	}
	return (char_count);
}

int			ft_printf(const char *format, ...)
{
	va_list		arguments;
	int			char_count;

	char_count = 0;
	va_start(arguments, format);
	char_count += ft_treat_all(format, arguments);
	va_end(arguments);
	return (char_count);
}