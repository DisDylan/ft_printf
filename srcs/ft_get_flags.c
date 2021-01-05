/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoinsu <dpoinsu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 16:27:02 by dpoinsu           #+#    #+#             */
/*   Updated: 2021/01/05 16:52:18 by dpoinsu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_flags		ft_minus(t_flags flags)
{
	flags.minus = 1;
	flags.zero = 0;
	return (flags);
}

t_flags		ft_digit(char c, t_flags flags)
{
	if (flags.star == 1)
		flags.width = 0;
	flags.width = (flags.width * 10) + (c - '0');
	return (flags);
}

t_flags		ft_width(va_list arguments, t_flags flags)
{
	flags.star = 1;
	flags.width = va_arg(arguments, int);
	if (flags.width < 0)
	{
		flags.minus = 1;
		flags.width *= -1;
	}
	return (flags);
}

int			ft_dot(const char *format, int start,
			t_flags *flags, va_list arguments)
{
	int i;

	i = start + 1;
	if (format[i] == '*')
	{
		flags->dot = va_arg(arguments, int);
		i++;
	}
	else
	{
		flags->dot = 0;
		while (ft_isdigit(format[i]))
			flags->dot = (flags->dot * 10) + (format[i++] - '0');
	}
	return (i);
}

int			ft_get_flag(const char *format, int index, va_list arguments,
		t_flags *flags)
{
	while (format[index])
	{
		if (!ft_isdigit(format[index]) && !ft_chrchr(format[index]) &&
				!ft_is_flag(format[index]))
			break ;
		if (format[index] == '0' && flags->width == 0 && flags->minus == 0)
			flags->zero = 1;
		if (format[index] == '.')
			index = ft_dot(format, index, flags, arguments);
		if (format[index] == '-')
			*flags = ft_minus(*flags);
		if (format[index] == '*')
			*flags = ft_width(arguments, *flags);
		if (ft_isdigit(format[index]))
			*flags = ft_digit(format[index], *flags);
		if (ft_chrchr(format[index]))
		{
			flags->type = format[index];
			break ;
		}
		index++;
	}
	return (index);
}
