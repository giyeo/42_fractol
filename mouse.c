/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaulino <rpaulino@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 14:23:54 by rpaulino          #+#    #+#             */
/*   Updated: 2021/09/20 11:52:21 by rpaulino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom_mouse(t_direction *w, long double smartmov, t_draw *image)
{
	if (w->right)
	{
		image->re_start += (1 * w->pctnx) / smartmov;
		image->re_end += (1 * w->pctnx) / smartmov;
	}
	if (w->left)
	{
		image->re_start -= 1 * w->pctnx / smartmov;
		image->re_end -= 1 * w->pctnx / smartmov;
	}
	if (w->up)
	{
		image->im_start += (1 * w->pctny) / smartmov;
		image->im_end += (1 * w->pctny) / smartmov;
	}
	if (w->down)
	{
		image->im_start -= 1 * w->pctny / smartmov;
		image->im_end -= 1 * w->pctny / smartmov;
	}
}

void	set_mouse_way(t_draw *image, t_direction *w)
{
	long double	centerx;
	long double	centery;

	centerx = image->width / 2;
	centery = image->height / 2;
	if (image->m3.x < centerx)
	{
		w->pctnx = my_fabs(1 - image->m3.x / centerx);
		w->left = 1;
	}
	if (image->m3.x > centerx)
	{
		w->pctnx = my_fabs(1 - image->m3.x / centerx);
		w->right = 1;
	}
	if (image->m3.y > centery)
	{
		w->pctny = my_fabs(1 - image->m3.y / centery);
		w->down = 1;
	}
	if (image->m3.y < centery)
	{
		w->pctny = my_fabs(1 - image->m3.y / centery);
		w->up = 1;
	}
}

void	zoom_mouse_track(t_draw *image)
{
	long double	smartmov;
	t_direction	w;

	w.down = 0;
	w.left = 0;
	w.right = 0;
	w.up = 0;
	w.pctnx = 0;
	w.pctny = 0;
	if (image->zoom > 0)
		smartmov = pow(2, image->zoom - 1);
	else
		smartmov = 1;
	set_mouse_way(image, &w);
	zoom_mouse(&w, smartmov, image);
}

int	mouse_control(int button, int x, int y, t_draw *image)
{
	image->m3.x = x;
	image->m3.y = y;
	if (button == 4)
	{
		zoom_mouse_track(image);
		zoom_in(image);
	}
	if (button == 5)
		zoom_out(image);
	draw_fractal(image);
	return (0);
}
