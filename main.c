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
	int max;
	int note;
	
	printf("\nTEST: d\n");
	pf = printf("PRINTF:%d Hello l'ami$\n", 42);
	pft = ft_printf("FT_ptf:%d Hello l'ami$\n", 42);
	if (pf == pft)
	{
		note++;
		printf(GREEN "| OK |\n" RESET);
	}
	else
		printf(RED "| KO |\n" RESET);
	max++;

	printf("\nTEST: u\n");
	pf = printf("PRINTF:%u$\n", -42);
	pft = ft_printf("FT_ptf:%u$\n", -42);
	if (pf == pft)
	{
		note++;
		printf(GREEN "| OK |\n" RESET);
	}
	else
		printf(RED "| KO |\n" RESET);
	max++;

	printf("\nTEST: s\n");
	pf = printf("PRINTF:%s$\n", "une string");
	pft = ft_printf("FT_ptf:%s$\n", "une string");
	if (pf == pft)
	{
		note++;
		printf(GREEN "| OK |\n" RESET);
	}
	else
		printf(RED "| KO |\n" RESET);
	max++;

	printf("\nTEST: %%\n");
	pf = printf("PRINTF:%%$\n");
	pft = ft_printf("FT_ptf:%%$\n");
	if (pf == pft)
	{
		note++;
		printf(GREEN "| OK |\n" RESET);
	}
	else
		printf(RED "| KO |\n" RESET);
	max++;

	/*printf("\n\n\n\n|||||||||||||||||||||||NEW TEST|||||||||||||||||||||\n");
	pf = printf("PRINTF:%c\n", 'c');
	pft = ft_printf("FT_printf:%c\n", 'c');
	printf("%d pour printf et %d pour ft\n", pf, pft);
	if (pf == pft)
		printf(GREEN "| OK |\n" RESET);
	else
		printf(RED "| KO |\n" RESET);*/

	printf("\nTEST: 10s\n");
	pf = printf("PRINTF:%10s$\n", "abcedef");
	pft = ft_printf("FT_ptf:%10s$\n", "abcedef");
	if (pf == pft)
	{
		note++;
		printf(GREEN "| OK |\n" RESET);
	}
	else
		printf(RED "| KO |\n" RESET);
	max++;

	printf("\nTEST: .5s\n");
	pf = printf("PRINTF:%.5s$\n", "abcdef");
	pft = ft_printf("FT_ptf:%.5s$\n", "abcdef");
	if (pf == pft)
	{
		note++;
		printf(GREEN "| OK |\n" RESET);
	}
	else
		printf(RED "| KO |\n" RESET);
	max++;

	printf("\nTEST: 10.5s\n");
	pf = printf("PRINTF:%10.5s$\n", "abcedef");
	pft = ft_printf("FT_ptf:%10.5s$\n", "abcedef");
	if (pf == pft)
	{
		note++;
		printf(GREEN "| OK |\n" RESET);
	}
	else
		printf(RED "| KO |\n" RESET);
	max++;

	printf("\nTEST: 025d\n");
	pf = printf("PRINTF:%025d$\n", 42);
	pft = ft_printf("FT_ptf:%025d$\n", 42);
	if (pf == pft)
	{
		note++;
		printf(GREEN "| OK |\n" RESET);
	}
	else
		printf(RED "| KO |\n" RESET);
	max++;

	printf("\nTEST: 10.*s\n");
	pf = printf("PRINTF:%10.*s$\n", 5, "abcedef");
	pft = ft_printf("FT_ptf:%10.*s$\n", 5, "abcedef");
	if (pf == pft)
	{
		note++;
		printf(GREEN "| OK |\n" RESET);
	}
	else
		printf(RED "| KO |\n" RESET);
	max++;

	if (note == max)
		printf(GREEN "BRAVO:\n%d/%d\n", note, max);
	else
	{
		printf(RED "PERDU:\n%d/%d\n", note, max);
	}
	
}
