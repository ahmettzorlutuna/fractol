/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_render.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azorlutu <azorlutu@student.42istanbul      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 22:16:50 by azorlutu          #+#    #+#             */
/*   Updated: 2025/03/12 22:16:51 by azorlutu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static	int	check_fractal_set(t_complex *z, t_complex *c, t_fractal *fractal)
{
	int	i;

	i = 0;
	if (!ft_strncmp(fractal->name, "mandelbrot", 10))
	{
		rescale_and_set(c, c, fractal);
		i = mandelbrot(*z, *c, fractal->iteration_count,
				fractal->escape_value);
	}
	else if (!ft_strncmp(fractal->name, "julia", 5))
	{
		rescale_and_set(z, c, fractal);
		c->x = fractal->julia_x;
		c->y = fractal->julia_y;
		i = julia(*z, *c, fractal->iteration_count, fractal->escape_value);
	}
	return (i);
}

static	void	handle_pixel(int x, int y, t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;
	int			i;

	i = 0;
	c.x = x;
	c.y = y;
	i = check_fractal_set(&z, &c, fractal);
	if (i < fractal->iteration_count)
		paint_pixel(x, y, &fractal->img,
			rescale(i, fractal->theme_color.outside_min_color,
				fractal->theme_color.outside_max_color,
				fractal->iteration_count));
	else
		paint_pixel(x, y, &fractal->img, fractal->theme_color.inside_color);
}

void	fractal_render(t_fractal *fractal)
{
	int	x;
	int	y;

	if (fractal->img.img_ptr)
		mlx_destroy_image(fractal->mlx_connection, fractal->img.img_ptr);
	fractal->img.img_ptr = mlx_new_image(fractal->mlx_connection,
			WIDTH, HEIGHT);
	fractal->img.pixels_ptr = mlx_get_data_addr(fractal->img.img_ptr,
			&fractal->img.bpp, &fractal->img.line_len, &fractal->img.endian);
	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
			handle_pixel(x, y, fractal);
	}
	mlx_put_image_to_window(fractal->mlx_connection, fractal->mlx_window,
		fractal->img.img_ptr, 0, 0);
}
