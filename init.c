/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaulino <rpaulino@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 15:02:53 by rpaulino          #+#    #+#             */
/*   Updated: 2021/09/20 11:16:18 by rpaulino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_julia_complex(t_draw *image, char *argv[])
{
	image->julia.real = my_atof(argv[2]);
	image->julia.imag = my_atof(argv[3]);
	init_julia(image);
}

void	init_julia(t_draw *image)
{
	image->re_start = -2;
	image->re_end = 2;
	image->im_start = 2;
	image->im_end = -2;
	image->width = 600;
	image->height = 600;
	image->zoom = 1;
	image->max_iterations = 80;
	image->set = 'j';
	image->mode = 0;
	image->re_e_minus_s0 = image->re_end - image->re_start;
	image->im_e_minus_s0 = image->im_end - image->im_start;
}

void	init_mandelbrot(t_draw *image)
{
	image->re_start = -2.25;
	image->re_end = 0.75;
	image->im_start = 1.5;
	image->im_end = -1.5;
	image->width = 600;
	image->height = 600;
	image->zoom = 1;
	image->max_iterations = 80;
	image->set = 'm';
	image->mode = 0;
	image->re_e_minus_s0 = image->re_end - image->re_start;
	image->im_e_minus_s0 = image->im_end - image->im_start;
}

void	init_tricorn(t_draw *image)
{
	image->re_start = -2.5;
	image->re_end = 1.5;
	image->im_start = 2;
	image->im_end = -2;
	image->width = 600;
	image->height = 600;
	image->zoom = 1;
	image->max_iterations = 80;
	image->set = 't';
	image->mode = 0;
	image->re_e_minus_s0 = image->re_end - image->re_start;
	image->im_e_minus_s0 = image->im_end - image->im_start;
}
