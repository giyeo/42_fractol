/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaulino <rpaulino@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 14:43:25 by rpaulino          #+#    #+#             */
/*   Updated: 2021/09/17 14:43:25 by rpaulino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

long double	my_fabs(long double number)
{
	if (number >= 0)
		return (number);
	else
		return (-number);
}

int	skip_render(t_complex_n c)
{
	if (my_fabs(c.real + 0.18) <= 0.43
		&& my_fabs(c.imag) <= 0.4)
		return (1);
	if (my_fabs(c.real + 1.0) <= 0.15
		&& my_fabs(c.imag) <= 0.2)
		return (1);
	return (0);
}

int	mandelbrot(t_complex_n c, int max_iterations)
{
	long double	temp;
	t_complex_n	z;
	int			n;

	if (skip_render(c))
		return (max_iterations);
	z.imag = 0;
	z.real = 0;
	n = 0;
	while ((my_fabs(z.real) + my_fabs(z.imag) < 4) && n < max_iterations)
	{
		temp = z.real * z.real - z.imag * z.imag + c.real;
		z.imag = 2 * z.real * z.imag + c.imag;
		z.real = temp;
		n += 1;
	}
	return (n);
}
