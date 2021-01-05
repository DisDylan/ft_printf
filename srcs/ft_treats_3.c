/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treats_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoinsu <dpoinsu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 16:32:37 by dpoinsu           #+#    #+#             */
/*   Updated: 2021/01/05 16:48:33 by dpoinsu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_min_uint(char *unsi_int, t_flags flags)
{
	int char_count;

	char_count = 0;
	if (flags.dot >= 0)
		char_count += ft_put_width(flags.dot - 1, ft_strlen(unsi_int) - 1, 1);
	char_count += ft_putstrprec(unsi_int, ft_strlen(unsi_int));
	return (char_count);
}

static int	ft_flag_uint(char *unsi_int, t_flags flags)
{
	int char_count;

	char_count = 0;
	if (flags.minus == 1)
		char_count += ft_min_uint(unsi_int, flags);
	if (flags.dot >= 0 && (size_t)flags.dot < ft_strlen(unsi_int))
		flags.dot = ft_strlen(unsi_int);
	if (flags.dot >= 0)
	{
		flags.width -= flags.dot;
		char_count += ft_put_width(flags.width, 0, 0);
	}
	else
		char_count += ft_put_width(flags.width,
		ft_strlen(unsi_int), flags.zero);
	if (flags.minus == 0)
		char_count += ft_min_uint(unsi_int, flags);
	return (char_count);
}

int			ft_u_int(unsigned int unsi, t_flags flags)
{
	char	*unsi_int;
	int		char_count;

	char_count = 0;
	unsi = (unsigned int)(4294967295 + 1
				+ unsi);
	if (flags.dot == 0 && unsi == 0)
	{
		char_count += ft_put_width(flags.width, 0, 0);
		return (char_count);
	}
	unsi_int = ft_itoa_u(unsi);
	char_count += ft_flag_uint(unsi_int, flags);
	free(unsi_int);
	return (char_count);
}

int			ft_put_width(int width, int minus, int has_zero)
{
	int char_count;

	char_count = 0;
	while (width - minus > 0)
	{
		if (has_zero)
			ft_putchar_fd('0', 1);
		else
			ft_putchar_fd(' ', 1);
		width -= 1;
		char_count++;
	}
	return (char_count);
}
