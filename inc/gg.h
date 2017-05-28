/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gg.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irhett <irhett@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/28 09:59:24 by irhett            #+#    #+#             */
/*   Updated: 2017/05/28 11:18:43 by irhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRADIENT_GEN_H
# define GRADIENT_GEN_H

# include "libft.h"
# include <stdio.h>

void	interact(int alpha);
void	generate(unsigned char c[8], unsigned int steps, int is_alpha);
void	check_exit(char *str);

#endif
