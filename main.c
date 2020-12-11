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

	printf("\n\n\n\n|||||||||||||||||||||||NEW TEST|||||||||||||||||||||\n");
	pf = printf("PRINTF:%d$\n", 42);
	pft = ft_printf("FT_ptf:%d$\n", 42);
	if (pf == pft)
		printf(GREEN "| OK |\n" RESET);
	else
		printf(RED "| KO |\n" RESET);
	
	printf("\n\n\n\n|||||||||||||||||||||||NEW TEST|||||||||||||||||||||\n");
	pf = printf("PRINTF:%d Hello l'ami\n", 42);
	pft = ft_printf("FT_ptf:%d Hello l'ami\n", 42);
	if (pf == pft)
		printf(GREEN "| OK |\n" RESET);
	else
		printf(RED "| KO |\n" RESET);

	printf("\n\n\n\n|||||||||||||||||||||||NEW TEST|||||||||||||||||||||\n");
	pf = printf("PRINTF:%u$\n", -42);
	pft = ft_printf("FT_ptf:%u$\n", -42);
	if (pf == pft)
		printf(GREEN "| OK |\n" RESET);
	else
		printf(RED "| KO |\n" RESET);

	printf("\n\n\n\n|||||||||||||||||||||||NEW TEST|||||||||||||||||||||\n");
	pf = printf("PRINTF:%s$\n", "une string");
	pft = ft_printf("FT_ptf:%s$\n", "une string");
	if (pf == pft)
		printf(GREEN "| OK |\n" RESET);
	else
		printf(RED "| KO |\n" RESET);

	printf("\n\n\n\n|||||||||||||||||||||||NEW TEST|||||||||||||||||||||\n");
	pf = printf("PRINTF:%%$\n");
	pft = ft_printf("FT_ptf:%%$\n");
	if (pf == pft)
		printf(GREEN "| OK |\n" RESET);
	else
		printf(RED "| KO |\n" RESET);

	/*printf("\n\n\n\n|||||||||||||||||||||||NEW TEST|||||||||||||||||||||\n");
	pf = printf("PRINTF:%c\n", 'c');
	pft = ft_printf("FT_printf:%c\n", 'c');
	printf("%d pour printf et %d pour ft\n", pf, pft);
	if (pf == pft)
		printf(GREEN "| OK |\n" RESET);
	else
		printf(RED "| KO |\n" RESET);*/

	printf("\n\n\n\n|||||||||||||||||||||||NEW TEST|||||||||||||||||||||\n");
	pf = printf("PRINTF: %10s$\n", "abcedef");
	pft = ft_printf("FT_ptf: %10s$\n", "abcedef");
	if (pf == pft)
		printf(GREEN "| OK |\n" RESET);
	else
		printf(RED "| KO |\n" RESET);

	printf("\n\n\n\n|||||||||||||||||||||||NEW TEST|||||||||||||||||||||\n");
	pf = printf("PRINTF:%.5s\n", "abcdef");
	pft = ft_printf("FT_printf:%.5s\n", "abcdef");
	if (pf == pft)
		printf(GREEN "| OK |\n" RESET);
	else
		printf(RED "| KO |\n" RESET);

	printf("\n\n\n\n|||||||||||||||||||||||NEW TEST|||||||||||||||||||||\n");
	pf = printf("PRINTF:%10.5s\n", "abcedef");
	pft = ft_printf("FT_printf:%10.5s\n", "abcedef");
	if (pf == pft)
		printf(GREEN "| OK |\n" RESET);
	else
		printf(RED "| KO |\n" RESET);
}
