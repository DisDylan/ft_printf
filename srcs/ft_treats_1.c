#include "../includes/ft_printf.h"

static int		ft_flag_str(char *str, ft_flags flags)
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

static int	ft_flag_pointer(char *str, ft_flags flags)
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

int		ft_char(char c, ft_flags flags)
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

int				ft_string(char *str, ft_flags flags)
{
	int char_count;

	char_count = 0;
	printf("OK EARLY STRING\n");
	if (!str)
		str = "(null)";
	if (flags.dot >= 0 && (size_t)flags.dot > ft_strlen(str))
		flags.dot = ft_strlen(str);
	printf("OK2\n");
	if (flags.minus == 1)
		char_count += ft_flag_str(str, flags);
	printf("%d & %d\n", flags.width, flags.dot);
	if (flags.dot >= 0)
		char_count += ft_put_width(flags.width, flags.dot, 0);
	else
	{
		printf("ok avant put width\n");
		char_count += ft_put_width(flags.width, ft_strlen(str), 0);
	}
	printf("OK2\n");
	if (flags.minus == 0)
		char_count += ft_flag_str(str, flags);
	printf("OK2\n");
	return (char_count);
}

int			ft_pointer(unsigned long long ull, ft_flags flags)
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