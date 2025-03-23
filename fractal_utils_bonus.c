/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azorlutu <azorlutu@student.42istanbul      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 20:56:24 by azorlutu          #+#    #+#             */
/*   Updated: 2025/03/19 20:56:24 by azorlutu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	paint_pixel_bonus(int x, int y, t_img_bonus *img, int color)
{
	int	offset;

	offset = (y * img->line_len) + (x * (img->bpp / 8));
	*(unsigned int *)(img->pixels_ptr + offset) = color;
}

double	rescale_bonus(double unscaled_num, double new_min, double new_max,
			double old_max)
{
	return ((new_max - new_min) * (unscaled_num - 0)
		/ (old_max - 0) + new_min);
}

void	rescale_and_set_bonus(t_complex_bonus *complex1,
		t_complex_bonus *complex2, t_fractal_bonus *fractal)
{
	complex1->x = (rescale_bonus(complex2->x, -2, 2, WIDTH_BONUS)
			* fractal->zoom) + fractal->offset_x;
	complex1->y = (rescale_bonus(complex2->y, 2, -2, HEIGHT_BONUS)
			* fractal->zoom) + fractal->offset_y;
}
