/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interact.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/28 10:49:36 by irhett            #+#    #+#             */
/*   Updated: 2017/05/29 15:16:57 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gg.h"

static unsigned int		ask(char *str)
{
	unsigned int	ret;
	char			*buff;
	int				temp;

	temp = -1;
	while (temp < 0)
	{
		printf("What is the %s?\n", str);
		ret = get_next_line(0, &buff);
		if (ret <= 0)
			exit(ft_error("Bad response"));
		check_exit(buff);
		temp = ft_atoi(buff);
		free(buff);
		if (temp < 0)
			printf("The number cannot be negative.\n");
	}
	ret = (unsigned int)temp;
	return (ret);
}

void	interact(int alpha)
{
	unsigned char	c[8];
	unsigned int	ret;
	unsigned int	steps;

	while (1)
	{
		printf("Colors! (responses will be truncated to 0-255)\n");
		if (alpha)
		{
			ret = ask("first Alpha Value");
			c[0] = ret % 256;
			ret = ask("second Alpha Value");
			c[1] = ret % 256;
		}
		else
		{
			c[0] = 0;
			c[1] = 0;
		}
		ret = ask("first Red Value");
		c[2] = ret % 256;
		ret = ask("second Red Value");
		c[3] = ret % 256;
		ret = ask("first Green Value");
		c[4] = ret % 256;
		ret = ask("second Green Value");
		c[5] = ret % 256;
		ret = ask("first Blue Value");
		c[6] = ret % 256;
		ret = ask("second Blue Value");
		c[7] = ret % 256;
		printf("\n");
		steps = ask("number of slices to make in the gradient?");
		printf("Generating...\n\n");
		generate(c, steps, alpha);
	}
}
