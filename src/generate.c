/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/28 10:06:56 by irhett            #+#    #+#             */
/*   Updated: 2017/05/28 11:58:08 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gg.h"

#define F float

static void	put_color(unsigned char a, unsigned char r, 
		unsigned char g, unsigned char b)
{
	char *str = "0123456789ABCDEF";

	ft_putstr("0x");
	ft_putchar(str[a / 16]);
	ft_putchar(str[a % 16]);
	ft_putchar(str[r / 16]);
	ft_putchar(str[r % 16]);
	ft_putchar(str[g / 16]);
	ft_putchar(str[g % 16]);
	ft_putchar(str[b / 16]);
	ft_putchar(str[b % 16]);
	ft_putchar('\n');
}

void		generate(unsigned char c[8], unsigned int steps, int is_alpha)
{
	unsigned int	i;
	unsigned char	a;
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;

	steps -= 1;
	i = 0;
	while (i <= steps)
	{
		if (is_alpha)
		{
			a = (c[1] * ((F)i / (F)steps)) + 
				(c[0] * ((F)(steps - i) / (F)steps));
		}
		else
			a = 0;
		r = (c[3] * ((F)i / (F)steps)) + (c[2] * ((F)(steps - i) / (F)steps));
		g = (c[5] * ((F)i / (F)steps)) + (c[4] * ((F)(steps - i) / (F)steps));
		b = (c[7] * ((F)i / (F)steps)) + (c[6] * (F)(steps - i) / (F)steps);
		i++;
		put_color(a, r, g, b);
	}
	printf("\n");
}
