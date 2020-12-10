/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoinsu <dpoinsu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 11:30:55 by dpoinsu           #+#    #+#             */
/*   Updated: 2020/12/09 15:24:02 by dpoinsu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
#include <stdio.h>
# include "libft.h"

typedef struct ft_flags
{
	int	width;
	int	minus;
	int	zero;
	int	dot;
} ft_flags;


int	ft_printf(const char *format, ...);

#endif
