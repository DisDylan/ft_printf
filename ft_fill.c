/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoinsu <dpoinsu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 11:29:12 by dpoinsu           #+#    #+#             */
/*   Updated: 2020/12/09 14:40:00 by dpoinsu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

static char *fill_zero(char *tmp, int zero)
{
	int newsize;
	char *str;
	int i;

	str = tmp;
	newsize = zero - ft_strlen(tmp);
	i = 0;
	while (newsize > 0)
	{
		str[i] = '0';
		i++;
	}
	return (str);
}

static char *fill_width(char *tmp, int width)
{
	int newsize;
	char *str;
	int i;

	str = ft_strdup(tmp);
	i = 0;
	printf("Dans fill_width, str vaut %s et tmp %s\n", str, tmp);
	newsize = width - (int)ft_strlen(tmp);
	while (i <= newsize)
	{
		str[i] = ':';
		i++;
	}
	printf("Dans fill_width, str vaut a la fin %s\n", str);
	return (str);
}

static char *trunc_word(char *tmp, int limit)
{
	int i;
	char *str;

	i = 0;
	str = NULL;
	printf("Dans trunc_word, tmp vaut %s\n", tmp);
	while (i < limit)
	{
		str[i] = tmp[i];
		i++;
	}
	return (str);
}


static char *rev_str(char *origin, char *actual)
{
	char *swap;
	char *tmp;
	int last_index;
	int i;
	int j;

	i = 0;
	tmp = NULL;
	swap = actual;
	last_index = (int)ft_strlen(actual) - (int)ft_strlen(origin);
	j = last_index;
	while (j < (int)ft_strlen(actual))
		tmp[i++] = swap[j++];
	i = -1;
	while(tmp[++i])
		swap[i] = tmp[i];
	while(i >= 0)
	{
		swap[j - i] = actual[i];
		i--;
	}
	return (swap);
}



char	*write_and_size(char *str, ft_flags *flags)
{
	char *tmp;

	tmp = str;
	printf("len de str avant les flags : %d\n", (int)ft_strlen(str));
	if (flags->width > (int)ft_strlen(str))
		tmp = fill_width(str, flags->width);
	if (flags->dot < (int)ft_strlen(str) && flags->dot > 0)
		tmp = trunc_word(str, flags->dot);
	if (flags->zero > (int)ft_strlen(str) && flags->minus == 0)
		tmp = fill_zero(str, flags->zero);
	if (flags->minus == 1)
		tmp = rev_str(str, tmp);
	return (tmp);
}