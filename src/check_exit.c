/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/28 10:23:52 by irhett            #+#    #+#             */
/*   Updated: 2017/05/28 11:27:47 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gg.h"

void	check_exit(char *str)
{
	ft_strtolower(str);
	if (ft_strcmp("exit", str) == 0)
		exit(0);
}
