/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaulino <rpaulino@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 14:51:52 by rpaulino          #+#    #+#             */
/*   Updated: 2021/09/20 08:09:39 by rpaulino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	zoom_keys(int key, t_draw *image)
{
	int	draw;

	draw = 0;
	if (key == 'q' || key == 'Q')
	{
		zoom_out(image);
		draw = 1;
	}
	if (key == 'e' || key == 'E')
	{
		zoom_in(image);
		draw = 1;
	}
	return (draw);
}

int	arrow_keys(int key, long double smartmov, t_draw *image, int draw)
{
	if (key == 65363)
	{
		image->re_start += 1 / smartmov;
		image->re_end += 1 / smartmov;
		draw = 1;
	}
	if (key == 65361)
	{
		image->re_start -= 1 / smartmov;
		image->re_end -= 1 / smartmov;
		draw = 1;
	}
	if (key == 65362)
	{
		image->im_start += 1 / smartmov;
		image->im_end += 1 / smartmov;
		draw = 1;
	}
	if (key == 65364)
	{
		image->im_start -= 1 / smartmov;
		image->im_end -= 1 / smartmov;
		draw = 1;
	}
	return (draw);
}

int	set_mode(t_draw *image, int key)
{
	if (key == 'm' || key == 'M')
		if (image->mode < 3)
			image->mode += 1;
	if (key == 'n' || key == 'N')
		if (image->mode > 0)
			image->mode -= 1;
	return (1);
}

int	set_iterations(t_draw *image, int key)
{
	if (key == 'i' || key == 'I')
		image->max_iterations += 40;
	if (key == 'u' || key == 'U')
		if (image->max_iterations >= 50)
			image->max_iterations -= 40;
	if (key == 'r' || key == 'R')
	{
		if (image->set == 'j')
			init_julia(image);
		if (image->set == 'm')
			init_mandelbrot(image);
		if (image->set == 't')
			init_tricorn(image);
	}
	return (1);
}

int	key_control(int key, t_draw *image)
{
	long double	smartmov;
	int			draw;

	draw = 0;
	draw = zoom_keys(key, image);
	if (image->zoom > 0)
		smartmov = pow(2, image->zoom - 1);
	else
		smartmov = 1;
	if (key > 60000)
		draw = arrow_keys(key, smartmov, image, 0);
	if (key == 65307)
	{
		mlx_destroy_window(image->mlx_ptr, image->win_ptr);
		exit(0);
	}
	draw = set_iterations(image, key);
	draw = set_mode(image, key);
	if (draw)
		draw_fractal(image);
	return (0);
}
