/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_sets_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azorlutu <azorlutu@student.42istanbul      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 21:27:35 by azorlutu          #+#    #+#             */
/*   Updated: 2025/03/12 21:27:35 by azorlutu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

int	mandelbrot_bonus(t_complex_bonus z, t_complex_bonus c,
			int max_iterations, double escape_value)
{
	int		i;
	double	zx2;
	double	zy2;
	double	temp_x;

	i = 0;
	while (i < max_iterations)
	{
		zx2 = z.x * z.x;
		zy2 = z.y * z.y;
		if (zx2 + zy2 > escape_value)
			return (i);
		temp_x = (zx2 - zy2);
		z.y = 2 * z.x * z.y;
		z.x = temp_x;
		z.x += c.x;
		z.y += c.y;
		++i;
	}
	return (max_iterations);
}

int	julia_bonus(t_complex_bonus z, t_complex_bonus c,
		int max_iterations, double escape_value)
{
	int		i;
	double	zx2;
	double	zy2;
	double	temp_x;

	i = 0;
	while (i < max_iterations)
	{
		zx2 = z.x * z.x;
		zy2 = z.y * z.y;
		if (zx2 + zy2 > escape_value)
			return (i);
		temp_x = (zx2 - zy2);
		z.y = 2 * z.x * z.y;
		z.x = temp_x;
		z.x += c.x;
		z.y += c.y;
		++i;
	}
	return (max_iterations);
}

int	tricorn_bonus(t_complex_bonus z, t_complex_bonus c,
		int max_iterations, double escape_value)
{
	int		i;
	double	zx2;
	double	zy2;
	double	temp_x;

	i = 0;
	while (i < max_iterations)
	{
		zx2 = z.x * z.x;
		zy2 = z.y * z.y;
		if (zx2 + zy2 > escape_value + 12.0)
			return (i);
		temp_x = (zx2 - zy2);
		z.y = -2 * z.x * z.y;
		z.x = temp_x;
		z.x += c.x;
		z.y += c.y;
		++i;
	}
	return (max_iterations);
}
