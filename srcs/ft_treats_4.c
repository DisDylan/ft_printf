
#include "../includes/ft_printf.h"

static int		ft_min_hexa(char *hexa, t_flags flags)
{
	int char_count;

	char_count = 0;
	if (flags.dot >= 0)
		char_count += ft_width(flags.dot - 1, ft_strlen(hexa) - 1, 1);
	char_count += ft_putstrprec(hexa, ft_strlen(hexa));
	return (char_count);
}

static int		ft_flag_hexa(char *hexa, t_flags flags)
{
	int char_count;

	char_count = 0;
	if (flags.minus == 1)
		char_count += ft_min_hexa(hexa, flags);
	if (flags.dot >= 0 && (size_t)flags.dot < ft_strlen(hexa))
		flags.dot = ft_strlen(hexa);
	if (flags.dot >= 0)
	{
		flags.width -= flags.dot;
		char_count += ft_width(flags.width, 0, 0);
	}
	else
		char_count += ft_width(flags.width,
		ft_strlen(hexa), flags.zero);
	if (flags.minus == 0)
		char_count += ft_min_hexa(hexa, flags);
	return (char_count);
}

int				ft_hexa(unsigned int ui, int lower, t_flags flags)
{
	char	*hexa;
	int		char_count;

	char_count = 0;
	ui = (unsigned int)(4294967295 + 1
				+ ui);
	if (flags.dot == 0 && ui == 0)
	{
		char_count += ft_width(flags.width, 0, 0);
		return (char_count);
	}
	hexa = ft_nbr_tobase((unsigned long long)ui, 16);
	if (lower == 1)
		hexa = ft_str_tolower(hexa);
	char_count += ft_flag_hexa(hexa, flags);
	return (char_count);
}

int		ft_putstrprec(char *str, int prec)
{
	int char_count;

	char_count = 0;
	while (str[char_count] && char_count < prec)
		ft_putchar_fd(str[char_count++], 1);
	return (char_count);
}

int		ft_treat_percent(t_flags flags)
{
	int char_count;

	char_count = 0;
	if (flags.minus == 1)
		char_count += ft_putstrprec("%", 1);
	char_count += ft_width(flags.width, 1, flags.zero);
	if (flags.minus == 0)
		char_count += ft_putstrprec("%", 1);
	return (char_count);
}
