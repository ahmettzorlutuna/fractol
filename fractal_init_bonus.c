/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_init_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azorlutu <azorlutu@student.42istanbul      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 21:28:02 by azorlutu          #+#    #+#             */
/*   Updated: 2025/03/12 21:28:02 by azorlutu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"
#include "theme_colors_bonus.h"

static	void	data_init_bonus(t_fractal_bonus *fractal)
{
	fractal->escape_value = 4;
	fractal->iteration_count = 42;
	fractal->offset_x = 0.0;
	fractal->offset_y = 0.0;
	fractal->zoom = 1.0;
	fractal->theme_index = 0;
	fractal->theme_color.outside_min_color = COLOR_THEME_BLACK_BONUS;
	fractal->theme_color.outside_max_color = COLOR_THEME_WHITE_BONUS;
	fractal->theme_color.inside_color = COLOR_THEME_GOLD_BONUS;
}

static	void	mlx_destroy_all_bonus(t_fractal_bonus *fractal)
{
	mlx_destroy_image(fractal->mlx_connection, fractal->img.img_ptr);
	mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
	mlx_destroy_display(fractal->mlx_connection);
	free(fractal->mlx_connection);
}

void	fractal_init_bonus(t_fractal_bonus *fractal)
{
	fractal->mlx_connection = mlx_init();
	if (fractal->mlx_connection == NULL)
	{
		mlx_destroy_all_bonus(fractal);
		malloc_error_bonus();
	}
	fractal->mlx_window = mlx_new_window(fractal->mlx_connection,
			WIDTH_BONUS, HEIGHT_BONUS,
			fractal->name);
	if (fractal->mlx_window == NULL)
	{
		mlx_destroy_all_bonus(fractal);
		malloc_error_bonus();
	}
	fractal->img.img_ptr = mlx_new_image(fractal->mlx_connection,
			WIDTH_BONUS, HEIGHT_BONUS);
	if (fractal->img.img_ptr == NULL)
	{
		mlx_destroy_all_bonus(fractal);
		malloc_error_bonus();
	}
	fractal->img.pixels_ptr = mlx_get_data_addr(fractal->img.img_ptr,
			&fractal->img.bpp, &fractal->img.line_len, &fractal->img.endian);
	events_init_bonus(fractal);
	data_init_bonus(fractal);
}
