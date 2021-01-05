#include "../includes/ft_printf.h"

int ft_chrchr(char c)
{
	return ((c == 'c') || (c == 's') || (c == 'p') || (c == 'd') || (c == 'i')
			|| (c == 'u') || (c == 'x') || (c == 'X') || (c == '%'));
}

int		ft_is_flag(char c)
{
	return ((c == '-') || (c == ' ') || (c == '0') || (c == '.') || (c == '*'));
}

int ft_treat_convert(char c, ft_flags flags, va_list arguments)
{
	int char_count;

	char_count = 0;
	if (c == 'c')
		char_count = ft_char(va_arg(arguments, int), flags);
	else if (c == 's')
		char_count = ft_string(va_arg(arguments, char *), flags);
	else if (c == 'p')
		char_count = ft_pointer(va_arg(arguments, unsigned long long), flags);
	else if (c == 'd' || c == 'i')
		char_count = ft_int(va_arg(arguments, int), flags);
	else if (c == 'u')
		char_count += ft_u_int((unsigned int)va_arg(arguments, unsigned int),
		flags);
	else if (c == 'x')
		char_count += ft_hexa(va_arg(arguments, unsigned int), 1, flags);
	else if (c == 'X')
		char_count += ft_hexa(va_arg(arguments, unsigned int), 0, flags);
	else if (c == '%')
		char_count += ft_percent(flags);
	return (char_count);
}