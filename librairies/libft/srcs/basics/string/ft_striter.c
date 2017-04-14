/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 15:33:08 by qfremeau          #+#    #+#             */
/*   Updated: 2016/08/17 14:53:47 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striter(char *str, void (*f)(char *))
{
	if (!str || !f)
		return ;
	while (*str != '\0')
	{
		f(str);
		str++;
	}
}
