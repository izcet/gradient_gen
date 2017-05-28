/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/28 10:02:54 by irhett            #+#    #+#             */
/*   Updated: 2017/05/28 11:17:46 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gg.h"

int		main(void)
{
	char	*str;
	int		ret;
	int		alpha;

	alpha = -1;
	printf("At any time, type \"exit\" (without quotes) to exit.\n\n");
	printf("Will you be using alpha today? (yes/no)\n");
	while (alpha < 0)
	{
		ret = get_next_line(0, &str);
		if (ret <= 0)
			return (1);
		check_exit(str);
		if (ft_strcmp(str, "yes") == 0)
			alpha = 1;
		else if (ft_strcmp(str, "no") == 0)
			alpha = 0;
		else
			printf("I didn't quite understand, \"%s\" is not valid.\n", str);
	}
	interact(alpha);
	return (0);
}
