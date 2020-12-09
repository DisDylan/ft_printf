/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoinsu <dpoinsu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 11:30:55 by dpoinsu           #+#    #+#             */
/*   Updated: 2020/12/02 11:31:19 by dpoinsu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>

typedef struct ft_flags
{
	int	width = 0;
	int	minus = 0;
	int	zero = 0;
	int	dot = 0;
	int	star = 0;
} ft_flags;


int	ft_printf(const char *format, ...);
int ft_chrchr(const char *str, char c);
void		get_flags(va_list args, const char *format, ft_flags flags, char *conversion);

#endif