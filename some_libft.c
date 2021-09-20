/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   some_libft.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaulino <rpaulino@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 14:18:23 by rpaulino          #+#    #+#             */
/*   Updated: 2021/09/17 14:19:33 by rpaulino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_isdigit(int argument)
{
	if (argument >= 48 && argument <= 57)
		return (1);
	return (0);
}

int	ft_isspace(int argument)
{
	if (argument == ' ')
		return (1);
	return (0);
}

int	ft_strcmp(const char *str1, const char *str2)
{
	while (*str1 == *str2++)
		if (*str1++ == 0)
			return (1);
	return (0);
}
