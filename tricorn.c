/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tricorn.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaulino <rpaulino@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 09:10:41 by rpaulino          #+#    #+#             */
/*   Updated: 2021/09/19 09:10:42 by rpaulino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	tricorn(t_complex_n c, int max_iterations)
{
	long double	temp;
	t_complex_n	z;
	int			n;

	z.imag = 0;
	z.real = 0;
	n = 0;
	while ((z.real * z.real + z.imag * z.imag < 4) && n < max_iterations)
	{
		temp = z.real * z.real - z.imag * z.imag + c.real;
		z.imag = -2 * z.real * z.imag + c.imag;
		z.real = temp;
		n += 1;
	}
	return (n);
}
