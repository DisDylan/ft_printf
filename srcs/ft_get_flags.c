/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoinsu <dpoinsu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 11:29:12 by dpoinsu           #+#    #+#             */
/*   Updated: 2020/12/09 16:58:37 by dpoinsu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

ft_flags		ft_flag_minus(ft_flags flags)
{
	flags.minus = 1;
	flags.zero = 0;
	return (flags);
}

ft_flags		ft_flag_digit(char c, ft_flags flags)
{
	if (flags.star == 1)
		flags.width = 0;
	flags.width = (flags.width * 10) + (c - '0');
	return (flags);
}

ft_flags		ft_flag_width(va_list arguments, ft_flags flags)
{
	flags.star = 1;
	flags.width = va_arg(argumentss, int);
	if (flags.width < 0)
	{
		flags.minus = 1;
		flags.width *= -1;
	}
	return (flags);
}

int			ft_flag_dot(const char *format, int start,
			ft_flags *flags, va_list arguments)
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

int 		ft_get_flag(const char *format, int index, va_list arguments, ft_flags *flags)
{
	unsigned char flag;

	while (format[index])
	{
		flag = format[index];
		if (!ft_isdigit(flag) && !ft_chrchr(flag) && !ft_is_flag(flag))
			break;
		if (flag == '0' && flags->width == 0 && flags->minus == 0)
			flags->zero = 1;
		if (flag == '.')
			index = ft_dot(format, index, flags, arguments);
		if (flag == '-')
			*flags = ft_minus(*flags);
		if (flag == '*')
			*flags = ft_width(*flags, arguments);
		if (ft_isdigit(flag))
			*flags = ft_flags_digit(*flags, flag);
		if (ft_chrchr(flag))
		{
			flags->type = flag;
			break;
		}
		index++;
	}
	return (index);
}