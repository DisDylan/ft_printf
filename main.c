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

	pf = printf("%d\n", 42);
	pft = ft_printf("%d\n", 42);
	printf("%d pour printf et %d pour ft\n", pf, pft);
	pf = printf("%u\n", -42);
	pft = ft_printf("%u\n", -42);
	printf("%d pour printf et %d pour ft\n", pf, pft);
	pf = printf("%s\n", "une string");
	pft = ft_printf("%s\n", "une string");
	printf("%d pour printf et %d pour ft\n", pf, pft);
	pf = printf("%c\n", 'c');
	pft = ft_printf("%c\n", 'c');
	printf("%d pour printf et %d pour ft\n", pf, pft);
	pf = printf("%10.5s\n", "abcedefghij");
	pft = ft_printf("%10.5s\n", "abcedefghij");
	printf("%d pour printf et %d pour ft\n", pf, pft);
	pf = printf("%c\n", 'c');
	pft = ft_printf("%c\n", 'c');
	printf("%d pour printf et %d pour ft\n", pf, pft);
}
