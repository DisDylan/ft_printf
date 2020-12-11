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
	int count;
	int flag_many;

	count = 0;
	if (format[0] == '*')
	{
		count += 1;
		flag_many = va_arg(arguments, int);
	}
	else
	{
		count += (int)ft_strlen(ft_itoa(ft_atoi(format)));
		flag_many = ft_atoi(format);
	}
	*index += count;
	return (flag_many);
}

// On rempli la chaîne avec le caractère passé en paramètre sur n caractères
static char *ft_fill(char *str, char c, int nb)
{
	char *strfilled;
	int i;

	strfilled = NULL;
	ft_bzero(strfilled, (size_t)nb);
	i = 0;
	while (str[i])
	{
		strfilled[i] = str[i];
		i++;
	}
	while (i < nb)
	{
		strfilled[i] = c;
	}
	return (strfilled);
}

// On assigne les valeurs passées en paramètres aux flags et/ou la width
static void ft_get_flag(const char *format, ft_flags *flags, va_list arguments, int *index)
{
	char flag;

	flag = format[0];
	if (flag == '0' || flag == '.' || flag == '-')
		*index += 1;
	if (flag == '0')
		flags->zero = ft_star_or_digit(format + 1, arguments, &*index);
	if (flag == '.')
		flags->dot = ft_star_or_digit(format + 1, arguments, &*index);
	if (flag == '-')
		flags->minus = 1;
	if (ft_isdigit(flag) || flag == '*')
		flags->width = ft_star_or_digit(format, arguments, &*index);
}

// On parcours les flags dans une boucle, tant que ce ne sont pas des caractères à convertir on y reste
static void ft_treat_flags(const char *format, int *index, va_list arguments, ft_flags *flags)
{
	int new_index;

	new_index = 0;
	while (!(ft_chrchr(format[new_index])))
	{
		ft_get_flag(format + new_index, &*flags, arguments, &*index);
		new_index++;
	}
	*index += new_index;
}

// On traite le caractère à convertir
static char *ft_treat_convert(const char *format, va_list arguments)
{
	char c;
	char *str;

	c = format[0];
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

// Fonction où l'on va modifier la chaine de caractères en fonction des flags
static char *ft_treat_all(char *str, ft_flags flags)
{
	int size;
	char *newstr;

	size = ft_strlen(str);
	newstr = NULL;
	if (flags.dot < size)
		newstr = ft_substr(str, 0, flags.dot);
	else
		newstr = ft_strdup(str);
	free(str);
	if (flags.width > (int)ft_strlen(newstr))
		newstr = ft_strdup((const char*)ft_fill(str, ' ', flags.width));
	if (flags.zero > (int)ft_strlen(newstr))
		newstr = ft_strdup((const char*)ft_fill(str, ' ', flags.width));
	return (newstr);
}

// Fonction principale où l'on va parcourir le format à la recherche d'un signe % pour effectuer une conversion
int	ft_printf(const char *format, ...)
{
	ft_flags flags;
	va_list arguments;
	int index;
	char *printable;
	char *tmp;

	flags = init_flags();
	printable = NULL;
	index = 0;
	tmp = NULL;	
	va_start(arguments, format);
	// FONCTIONS TRAITEMENT DE LA CHAINE
	/*
	while (format[index])
	{
		if (format[index] == '%')
		{
			//TRAITEMENT DE LA CHAINE
			index++;
			if (format[index] == '%')
			{
				printable[index] = '%';
				index++;
			}
			//ft_treat_flags(format + index, &index, arguments, &flags);
			//tmp = ft_treat_all(ft_treat_convert(format + index, arguments), flags);
			printable = ft_strjoin(printable, tmp);
			index++;
		}
		else
			printable[index] = format[index];
		index++;
	}
	*/
	va_end(arguments);
	//ft_putstr_fd(printable, 1);
	return (ft_strlen(printable));
}
