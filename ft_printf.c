/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoinsu <dpoinsu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 11:29:12 by dpoinsu           #+#    #+#             */
/*   Updated: 2020/12/09 16:58:37 by dpoinsu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
!SAVE!
#include "includes/ft_printf.h"

// Initialisation de ma structure de flags
static ft_flags init_flags(void)
{
	ft_flags flags;

	flags.width = 0;
	flags.minus = 0;
	flags.zero = 0;
	flags.dot = 0;
	return (flags);
}

// On recherche si le caractère est un de ceux que l'on doit convertir
int ft_chrchr(char format_letter)
{
	char *conversion;
	int i;

	conversion = "cspdiuxX";
	i = 0;
	while (conversion[i])
	{
		if (conversion[i] == format_letter)
			return (1);
		i++;
	}
	return (0);
}

// On retourne soit la valeur d'un des arguments si *, sinon le nombre passé en paramètre
int ft_star_or_digit(const char *format, va_list arguments, int *index)
{
	int count;
	int flag_many;

	count = 0;
	if (format[0] == '*')
	{
		count += 1;
		flag_many = va_arg(arg int)
	}
	else
	{
		count += ft_atoi(ft_strlen(ft_itoa(ft_atoi(format))));
		flag_many = ft_atoi(format);
	}
	*index += count;
	return (flag_many)
}

// On assigne les valeurs passées en paramètres aux flags et/ou la width
void ft_get_flag(const char *format, ft_flags *flags, va_liste arguments, int *index)
{
	char flag;

	flag = format[0];
	if (flag == '0' || flag == '.' || flag == '-')
		*index += 1;
	if (flag == '0')
		flag->zero = ft_star_or_digit(format + 1, arguments, *index);
	if (flag == '.')
		flag->dot = ft_star_or_digit(format + 1, arguments, *index);
	if (flag == '-')
		flag->minus = 1;
	if (ft_isdigit(flag) || flag == '*')
		flag->width = ft_star_or_digit(format, arguments, *index);
}

// On parcours les flags dans une boucle, tant que ce ne sont pas des caractères à convertir on y reste
void ft_treat_flags(const char *format, char *printable, int *index, va_list arguments)
{
	ft_flags flags;
	int new_index;

	flags = init_flags();
	new_index = 0;
	while (!(ft_chrchr(format[new_index])))
	{
		ft_get_flag(format + new_index, &flags, arguments, *index);
		new_index++;
	}
	*index += new_index;
}

ft_treat_convert(const char *format, char *printable)
{
	char c;

	c = format[0];
	if (c == 'c')
	if (c == 's')
	if (c == 'p')
	if (c == 'd' || c == 'i')
	if (c == 'u')
	if (c == 'x')
	if (c == 'X')
}

// Fonction principale où l'on va parcourir le format à la recherche d'un signe % pour effectuer une conversion
int	ft_printf(const char *format, ...)
{
	va_list arguments;
	int index;
	char *printable;

	printable = NULL;	
	va_start(arguments, format);
	// FONCTIONS TRAITEMENT DE LA CHAINE
	while format[index]
		if (format[index] == '%')
		{
			//TRAITEMENT DE LA CHAINE
			index++;
			if (format[index] == '%')
			{
				index++;
				ft_putchar_fd('%', 1);
			}
			ft_treat_flags(format + index, printable, &index, arguments);
			ft_treat_convert(format + index);
		}
		else
			printable[index] = format[index];
		index++;
	va_end(arguments);
	return (ft_strlen(printable));
}
