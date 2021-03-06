/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treats_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoinsu <dpoinsu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 16:29:15 by dpoinsu           #+#    #+#             */
/*   Updated: 2021/01/05 16:49:32 by dpoinsu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int		ft_flag_str(char *str, t_flags flags)
{
	int char_count;

	char_count = 0;
	if (flags.dot >= 0)
	{
		char_count += ft_put_width(flags.dot, ft_strlen(str), 0);
		char_count += ft_putstrprec(str, flags.dot);
	}
	else
	{
		char_count += ft_putstrprec(str, ft_strlen(str));
	}
	return (char_count);
}

static int		ft_flag_pointer(char *str, t_flags flags)
{
	int char_count;

	char_count = 0;
	char_count += ft_putstrprec("0x", 2);
	if (flags.dot >= 0)
	{
		char_count += ft_put_width(flags.dot, ft_strlen(str), 1);
		char_count += ft_putstrprec(str, flags.dot);
	}
	else
		char_count += ft_putstrprec(str, ft_strlen(str));
	return (char_count);
}

int				ft_char(char c, t_flags flags)
{
	int char_count;

	char_count = 0;
	if (flags.minus == 1)
		ft_putchar_fd(c, 1);
	char_count = ft_put_width(flags.width, 1, 0);
	if (flags.minus == 0)
		ft_putchar_fd(c, 1);
	return (char_count + 1);
}

int				ft_string(char *str, t_flags flags)
{
	int char_count;

	char_count = 0;
	if (!str)
		str = "(null)";
	if (flags.dot >= 0 && (size_t)flags.dot > ft_strlen(str))
		flags.dot = ft_strlen(str);
	if (flags.minus == 1)
		char_count += ft_flag_str(str, flags);
	if (flags.dot >= 0)
		char_count += ft_put_width(flags.width, flags.dot, 0);
	else
		char_count += ft_put_width(flags.width, ft_strlen(str), 0);
	if (flags.minus == 0)
		char_count += ft_flag_str(str, flags);
	return (char_count);
}

int				ft_pointer(unsigned long long ull, t_flags flags)
{
	char	*str;
	int		char_count;

	char_count = 0;
	if (ull == 0 && flags.dot == 0)
	{
		char_count += ft_putstrprec("0x", 2);
		return (char_count += ft_put_width(flags.width, 0, 1));
	}
	str = ft_pointer_base(ull, 16);
	str = ft_str_tolower(str);
	if ((size_t)flags.dot < ft_strlen(str))
		flags.dot = ft_strlen(str);
	if (flags.minus == 1)
		char_count += ft_flag_pointer(str, flags);
	char_count += ft_put_width(flags.width, ft_strlen(str) + 2, 0);
	if (flags.minus == 0)
		char_count += ft_flag_pointer(str, flags);
	free(str);
	return (char_count);
}
