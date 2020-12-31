/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoinsu <dpoinsu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 12:12:04 by dpoinsu           #+#    #+#             */
/*   Updated: 2020/12/28 16:29:23 by dpoinsu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "includes/ft_printf.h"

int main(void)
{
	int pf;
	int pft;
	int max;
	int note;

	max = 0;
	note = 0;
	printf(YELLOW "\nTEST: d\n" RESET);
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

	printf(YELLOW "\nTEST: u\n" RESET);
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

	printf(YELLOW "\nTEST: u\n" RESET);
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

	printf(YELLOW "\nTEST: s\n" RESET);
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

	printf(YELLOW "\nTEST: %%\n" RESET);
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

	printf(YELLOW "\nTEST: c\n" RESET);
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

	printf(YELLOW "\nTEST: 10s\n" RESET);
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

	printf(YELLOW "\nTEST: .5s\n" RESET);
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

	printf(YELLOW "\nTEST: 10.5s\n" RESET);
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

	printf(YELLOW "\nTEST: 025d\n" RESET);
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
	printf(YELLOW "\nTEST: 10.*s\n" RESET);
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

	printf(YELLOW "\nTEST: *.*s\n" RESET);
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

	printf(YELLOW "\nTEST: -d\n" RESET);
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

	printf(YELLOW "\nTEST: -d\n" RESET);
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
	printf(YELLOW "\nTEST: -20d\n" RESET);
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

	printf(YELLOW "\nTEST: x\n" RESET);
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

	printf(YELLOW "\nTEST: X\n" RESET);
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

	printf(YELLOW "\nTEST: X\n" RESET);
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

	printf(YELLOW "\nTEST: x\n" RESET);
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

	void *nb;
	nb = "ok";
	printf(YELLOW "\nTEST: p\n" RESET);
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
	
	printf(YELLOW "\nTEST: %5%\n" RESET);
	pf = printf("PRINTF:%5%$\n");
	pft = ft_printf("FT_ptf:%5%$\n");
	if (pf == pft)
	{
		note++;
		printf(GREEN "| OK |\n" RESET);
	}
	else
		printf(RED "| KO |\n" RESET);
	max++;
	
	printf(YELLOW "\nTEST: allPrintable\n" RESET);
	pf = printf("PRINTF: %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",' ','!','"','#','$','%','&','\'','(',')','*','+',',','-','.','/','0','1','2','3','4','5','6','7','8','9',':',';','<','=','>','?','@','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W', 'X', 'Y','Z','[','\\',']','^','_','`','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','{','|','}','~');
	pft = ft_printf("FT_ptf: %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",' ','!','"','#','$','%','&','\'','(',')','*','+',',','-','.','/','0','1','2','3','4','5','6','7','8','9',':',';','<','=','>','?','@','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','[','\\',']','^','_','`','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','{','|','}','~');
	if (pf == pft)
	{
		note++;
		printf(GREEN "| OK |\n" RESET);
	}
	else
		printf(RED "| KO |\n" RESET);
	max++;
	
	printf(YELLOW "\nTEST: c = \\0\n" RESET);
	pf = printf("PRINTF:%c$\n", '\0');
	printf("%d\n", pf);
	pft = ft_printf("FT_ptf:%c$\n", '\0');
	printf("%d\n", pft);
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
