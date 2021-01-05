/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoinsu <dpoinsu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 11:30:55 by dpoinsu           #+#    #+#             */
/*   Updated: 2021/01/05 16:10:25 by dpoinsu          ###   ########.fr       */
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

typedef	struct	s_flags
{
	int	width;
	int	minus;
	int	zero;
	int	dot;
	int type;
	int star;
	int printed;
}				t_flags;

int				ft_printf(const char *format, ...);
char			*ft_itoa_u(unsigned int n);
char			*ft_nbr_tobase(unsigned long long nbr, char *base);
t_flags			ft_minus(t_flags flags);
t_flags			ft_width(va_list arguments, t_flags flags);
t_flags			ft_digit(char c, t_flags flags);
int				ft_get_flag(const char *format, int index, va_list arguments,
		t_flags *flags);
int				ft_chrchr(char c);
int				ft_is_flag(char c);
int				ft_treat_convert(char c, t_flags flags, va_list arguments);
int				ft_pointer(unsigned long long ull, t_flags flags);
int				ft_string(char *str, t_flags flags);
int				ft_char(char c, t_flags flags);
int				ft_int(int i, t_flags flags);
int				ft_u_int(unsigned int unsi, t_flags flags);
int				ft_hexa(unsigned int ui, int lower, t_flags flags);
int				ft_percent(t_flags flags);
int				ft_put_width(int width, int minus, int has_zero);
int				ft_putstrprec(char *str, int prec);
char			*ft_str_tolower(char *str);
char			*ft_pointer_base(unsigned long long ull, int base);

#endif
