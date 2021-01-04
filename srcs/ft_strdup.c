/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoinsu <dpoinsu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 16:37:36 by dpoinsu           #+#    #+#             */
/*   Updated: 2020/11/20 14:51:13 by dpoinsu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_strdup(const char *s)
{
	char *str;
	int i;

	i = 0;
	printf("ok la");
	if (*s == '\0')
		return ((char*)ft_calloc(sizeof(char), (ft_strlen(s) + 1)));
	while (s[i])
		i++;
	if (!(str = malloc(sizeof(*str) * (i + 1))))
		return (0);
	i = 0;
	if (s == NULL)
	{
		str = NULL;
		return (str);
	}
	while (s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
