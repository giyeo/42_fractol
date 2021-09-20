/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaulino <rpaulino@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 14:10:51 by rpaulino          #+#    #+#             */
/*   Updated: 2021/09/18 13:44:13 by rpaulino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

char	char_handler(char **number)
{
	while (ft_isspace(**number))
		(*number)++;
	if (**number == '-')
	{
		(*number)++;
		return (1);
	}
	else
	{
		if (**number == '+')
			(*number)++;
		return (0);
	}
}

double	my_atof(char *number)
{
	double	value;
	double	fraction;
	char	sign;

	sign = char_handler(&number);
	value = 0.0;
	fraction = 0.1;
	while (ft_isdigit(*number))
		value = 10.0 * value + (*number++ - '0');
	if (*number++ == '.')
	{
		while (ft_isdigit(*number))
		{
			value += (*number++ - '0') * fraction;
			fraction *= 0.1;
		}
	}
	if (sign)
		value *= -1.0;
	return (value);
}
