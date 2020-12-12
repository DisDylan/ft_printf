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

	max = 0;
	note = 0;
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
	pf = printf("PRINTF:%u$\n", 42);
	pft = ft_printf("FT_ptf:%u$\n", 42);
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

	printf("\nTEST: c\n");
	pf = printf("PRINTF: %c\n", 'c');
	pft = ft_printf("FT_ptf: %c\n", 'c');
	if (pf == pft)
	{
		note++;
		printf(GREEN "| OK |\n" RESET);
	}
	else
		printf(RED "| KO |\n" RESET);
	max++;

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
/*	OKOKOKOKOKOK
	printf("\nTEST: 025s\n");
	pf = printf("PRINTF:%025s$\n", "Hello world");
	pft = ft_printf("FT_ptf:%025s$\n", "Hello world");
	if (pf == pft)
	{
		note++;
		printf(GREEN "| OK |\n" RESET);
	}
	else
		printf(RED "| KO |\n" RESET);
	max++;
*/
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

	printf("\nTEST: *.*s\n");
	pf = printf("PRINTF:%*.*s$\n", 10, 5, "abcedef");
	pft = ft_printf("FT_ptf:%*.*s$\n", 10, 5, "abcedef");
	if (pf == pft)
	{
		note++;
		printf(GREEN "| OK |\n" RESET);
	}
	else
		printf(RED "| KO |\n" RESET);
	max++;

	printf("\nTEST: -d\n");
	pf = printf("PRINTF:%-d$\n", 42);
	pft = ft_printf("FT_ptf:%-d$\n", 42);
	if (pf == pft)
	{
		note++;
		printf(GREEN "| OK |\n" RESET);
	}
	else
		printf(RED "| KO |\n" RESET);
	max++;

	printf("\nTEST: -d\n");
	pf = printf("PRINTF:%-d$\n", -42);
	pft = ft_printf("FT_ptf:%-d$\n", -42);
	if (pf == pft)
	{
		note++;
		printf(GREEN "| OK |\n" RESET);
	}
	else
		printf(RED "| KO |\n" RESET);
	max++;
/*	OKOKOKOKOK
	printf("\nTEST: -010d\n");
	pf = printf("PRINTF:%-010d$\n", 666);
	pft = ft_printf("FT_ptf:%-010d$\n", 666);
	if (pf == pft)
	{
		note++;
		printf(GREEN "| OK |\n" RESET);
	}
	else
		printf(RED "| KO |\n" RESET);
	max++;
*/
	printf("\nTEST: -20d\n");
	pf = printf("PRINTF:%-20d$\n", 666);
	pft = ft_printf("FT_ptf:%-20d$\n", 666);
	if (pf == pft)
	{
		note++;
		printf(GREEN "| OK |\n" RESET);
	}
	else
		printf(RED "| KO |\n" RESET);
	max++;

	printf("\nTEST: x\n");
	pf = printf("PRINTF:%x$\n", 4667);
	pft = ft_printf("FT_ptf:%x$\n", 4667);
	if (pf == pft)
	{
		note++;
		printf(GREEN "| OK |\n" RESET);
	}
	else
		printf(RED "| KO |\n" RESET);
	max++;

	printf("\nTEST: X\n");
	pf = printf("PRINTF:%X$\n", 42);
	pft = ft_printf("FT_ptf:%X$\n", 42);
	if (pf == pft)
	{
		note++;
		printf(GREEN "| OK |\n" RESET);
	}
	else
		printf(RED "| KO |\n" RESET);
	max++;

	printf("\nTEST: X\n");
	pf = printf("PRINTF:%X$\n", -42);
	pft = ft_printf("FT_ptf:%X$\n", -42);
	if (pf == pft)
	{
		note++;
		printf(GREEN "| OK |\n" RESET);
	}
	else
		printf(RED "| KO |\n" RESET);
	max++;

	printf("\nTEST: x\n");
	pf = printf("PRINTF:%x$\n", -89564);
	pft = ft_printf("FT_ptf:%x$\n", -89564);
	if (pf == pft)
	{
		note++;
		printf(GREEN "| OK |\n" RESET);
	}
	else
		printf(RED "| KO |\n" RESET);
	max++;

	void *nb = 5;
	printf("\nTEST: p\n");
	pf = printf("PRINTF:%p$\n", nb);
	pft = ft_printf("FT_ptf:%p$\n", nb);
	if (pf == pft)
	{
		note++;
		printf(GREEN "| OK |\n" RESET);
	}
	else
		printf(RED "| KO |\n" RESET);
	max++;

	if (note == max)
		printf(GREEN "\nBRAVO:\n%d/%d\n", note, max);
	else
	{
		printf(RED "\nPERDU:\n%d/%d\n", note, max);
	}
	
}
