/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoinsu <dpoinsu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 11:30:55 by dpoinsu           #+#    #+#             */
/*   Updated: 2020/12/28 10:39:38 by dpoinsu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include "../libft/libft.h"
# define RED     "\x1b[31m"
# define GREEN   "\x1b[32m"
# define YELLOW  "\x1b[33m"
# define BLUE    "\x1b[34m"
# define MAGENTA "\x1b[35m"
# define CYAN    "\x1b[36m"
# define RESET   "\x1b[0m"

typedef struct ft_flags
{
	int	width;
	int	minus;
	int	zero;
	int	dot;
	int type;
	int star;
	int printed;
} ft_flags;


int			ft_printf(const char *format, ...);
char		*ft_itoa_u(unsigned int n);
char		*ft_nbr_tobase(unsigned long long nbr, char *base);
ft_flags		ft_minus(ft_flags flags);
ft_flags		ft_width(va_list arguments, ft_flags flags);
ft_flags		ft_digit(char c, ft_flags flags);
int 		ft_get_flag(const char *format, int index, va_list arguments, ft_flags *flags);
int ft_chrchr(char c);
int		ft_is_flag(char c);
int ft_treat_convert(char c, ft_flags flags, va_list arguments);
int			ft_pointer(unsigned long long ull, ft_flags flags);
int				ft_string(char *str, ft_flags flags);
int		ft_char(char c, ft_flags flags);

#endif
