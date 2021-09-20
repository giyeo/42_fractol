/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaulino <rpaulino@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 15:03:01 by rpaulino          #+#    #+#             */
/*   Updated: 2021/09/19 09:46:59 by rpaulino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	julia(t_complex_n c, t_complex_n z, int max_iterations)
{
	long double	temp;
	int			n;

	n = 0;
	while ((my_fabs(z.real) + my_fabs(z.imag) < 4) && n < max_iterations)
	{
		temp = (z.real * z.real - z.imag * z.imag) + c.real;
		z.imag = (2 * z.real * z.imag) + c.imag;
		z.real = temp;
		n += 1;
	}
	return (n);
}
