/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoinsu <dpoinsu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 12:12:04 by dpoinsu           #+#    #+#             */
/*   Updated: 2020/12/09 17:01:43 by dpoinsu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <stdio.h>

int main(void)
{
	int pf;
	int pft;

	pf = printf("PRINTF:%d\n", 42);
	pft = ft_printf("FT_printf:%d\n", 42);
	printf("%d pour printf et %d pour ft\n", pf, pft);
	pf = printf("PRINTF:%u\n", -42);
	pft = ft_printf("FT_printf:%u\n", -42);
	printf("%d pour printf et %d pour ft\n", pf, pft);
	pf = printf("PRINTF:%s\n", "une string");
	pft = ft_printf("FT_printf:%s\n", "une string");
	printf("%d pour printf et %d pour ft\n", pf, pft);
	pf = printf("PRINTF:%c\n", 'c');
	pft = ft_printf("FT_printf:%c\n", 'c');
	printf("%d pour printf et %d pour ft\n", pf, pft);
	pf = printf("PRINTF:%10s\n", "abcedef");
	pft = ft_printf("FT_printf:%10s\n", "abcedef");
	printf("%d pour printf et %d pour ft\n", pf, pft);
	pf = printf("PRINTF:%.5s\n", "abcdef");
	pft = ft_printf("FT_printf:%.5\n", "abcdef");
	printf("%d pour printf et %d pour ft\n", pf, pft);
	pf = printf("PRINTF:%10.5s\n", "abcedef");
	pft = ft_printf("FT_printf:%10.5s\n", "abcedef");
	printf("%d pour printf et %d pour ft\n", pf, pft);
}
