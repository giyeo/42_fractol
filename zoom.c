/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaulino <rpaulino@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 14:10:33 by rpaulino          #+#    #+#             */
/*   Updated: 2021/09/20 10:53:58 by rpaulino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom_in(t_draw *image)
{
	long double	absx;
	long double	absy;

	absx = my_fabs(image->re_end - image->re_start);
	absy = my_fabs(image->im_end - image->im_start);
	image->zoom++;
	image->max_iterations += 10;
	image->re_start += absx / 4;
	image->re_end -= absx / 4;
	image->im_start -= absy / 4;
	image->im_end += absy / 4;
	image->re_e_minus_s0 = image->re_end - image->re_start;
	image->im_e_minus_s0 = image->im_end - image->im_start;
}

void	zoom_out(t_draw *image)
{
	long double	absx;
	long double	absy;

	absx = my_fabs(image->re_end - image->re_start);
	absy = my_fabs(image->im_end - image->im_start);
	image->zoom--;
	if (image->max_iterations > 25)
		image->max_iterations -= 10;
	image->re_start -= absx * 0.5;
	image->re_end += absx * 0.5;
	image->im_start += absy * 0.5;
	image->im_end -= absy * 0.5;
	image->re_e_minus_s0 = image->re_end - image->re_start;
	image->im_e_minus_s0 = image->im_end - image->im_start;
}
