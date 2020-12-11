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
static int ft_chrchr(char format_letter)
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
static int ft_star_or_digit(const char *format, va_list arguments, int *index)
{
	int flag_many;

	if (format[*index] == '*')
	{
		*index += 1;
		flag_many = va_arg(arguments, int);
	}
	else
	{
		flag_many = ft_atoi(format + *index);
		*index += (int)ft_strlen(ft_itoa(ft_atoi(format + *index)));
	}
	return (flag_many);
}

// On assigne les valeurs passées en paramètres aux flags et/ou la width
static ft_flags ft_get_flag(const char *format, int *index, va_list arguments)
{
	char flag;
	ft_flags flags;

	flag = format[*index];
	while (!(ft_chrchr(format[*index])))
	{
		if (flag == '0' || flag == '.' || flag == '-')
			*index += 1;
		if (flag == '0')
			flags.zero = ft_star_or_digit(format, arguments, index);
		if (flag == '.')
			flags.dot = ft_star_or_digit(format, arguments, index);
		if (flag == '-')
			flags.minus = 1;
		if (ft_isdigit(flag) || flag == '*')
			flags.width = ft_star_or_digit(format, arguments, index);
	}
	return (flags);
}

// On rempli la chaîne avec le caractère passé en paramètre sur n caractères
static char *ft_fill(char *str, char c, int nb)
{
	char *strfilled;
	int i;
	int size_fill;

	printf("str = %s\n", str);
	size_fill = nb - (int)ft_strlen(str) - 1;
	strfilled = (char*)malloc(sizeof(*strfilled) * nb + 1);
	i = 0;
	while (i < size_fill)
	{
		strfilled[i] = c;
		i++;
	}
	while (i < nb)
	{
		strfilled[i] = c;
		i++;
	}
	strfilled[i] = '\0';
	return (strfilled);
}

// On traite le caractère à convertir
static char *ft_treat_convert(const char *format, int *index, va_list arguments)
{
	char c;
	char *str;

	c = format[*index];
	//if (c == 'c')
	//	str = ft_strdup(va_arg(arguments, int));
	if (c == 's')
		str = ft_strdup(va_arg(arguments, char*));
	//if (c == 'p')
	//	str = ft_strdup(va_arg(arguments, int));
	if (c == 'd' || c == 'i')
		str = ft_strdup(ft_itoa(va_arg(arguments, int)));
	if (c == 'u')
		str = ft_strdup(ft_itoa(va_arg(arguments, unsigned int)));
	if (c == 'x')
		str = ft_strdup(ft_itoa(va_arg(arguments, int)));
	if (c == 'X')
		str = ft_strdup(ft_itoa(va_arg(arguments, int)));
	return (str);
}

// On rempli la chaîne avec le caractère passé en paramètre sur n caractères
static char *ft_fill_minus(char *str, char c, int nb)
{
	char *strfilled;
	int i;

	strfilled = (char*)malloc(sizeof(*strfilled) * nb + 1);
	i = 0;
	while (str[i])
	{
		strfilled[i] = str[i];
		i++;
	}
	while (i < nb)
	{
		strfilled[i] = c;
		i++;
	}
	strfilled[i] = '\0';
	return (strfilled);
}

// Fonction où l'on va modifier la chaine de caractères en fonction des flags
static char *ft_treat_all(char *str, ft_flags flags)
{
	int size;
	char *newstr;

	size = ft_strlen(str);
	if (flags.dot < size && flags.dot > 0)
		newstr = ft_substr(str, 0, flags.dot);
	else
		newstr = ft_strdup(str);
	if (flags.width > size)
	{
		free(newstr);
		newstr = ft_fill(str, ' ', flags.width);
	}
	if (flags.zero > size)
	{
		free(newstr);
		newstr = ft_fill(str, ' ', flags.width);
	}
	free(str);
	return (newstr);
}

// Fonction principale où l'on va parcourir le format à la recherche d'un signe % pour effectuer une conversion
int	ft_printf(const char *format, ...)
{
	ft_flags flags;
	va_list arguments;
	int index;
	int size;
	char *tmp;

	//flags = init_flags();
	index = 0;
	size = 0;
	va_start(arguments, format);
	// FONCTIONS TRAITEMENT DE LA CHAINE
	while (format[index])
	{
		if (format[index] == '%')
		{
			index++;
			if (format[index] != '%')
			{
				flags = ft_get_flag(format, &index, arguments);
				tmp = ft_treat_all(ft_treat_convert(format, &index, arguments), flags);
				ft_putstr_fd(tmp, 1);
				size += (int)ft_strlen(tmp);
				free(tmp);
				index++;
			}
		}
		ft_putchar_fd(format[index], 1);
		index++;
		size++;
	}
	va_end(arguments);
	return (size);
}
