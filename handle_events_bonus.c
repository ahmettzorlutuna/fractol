/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_events_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azorlutu <azorlutu@student.42istanbul      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 22:30:22 by azorlutu          #+#    #+#             */
/*   Updated: 2025/03/12 22:30:23 by azorlutu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"
#include "theme_colors_bonus.h"

int	close_handler_bonus(t_fractal_bonus *fractal)
{
	mlx_destroy_image(fractal->mlx_connection, fractal->img.img_ptr);
	mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
	mlx_destroy_display(fractal->mlx_connection);
	free(fractal->mlx_connection);
	exit(EXIT_SUCCESS);
}

static	void	change_color_scheme_bonus(int keycode, t_fractal_bonus *fractal)
{
	if (keycode == KEY_ONE_BONUS)
	{
		fractal->theme_color.outside_min_color = COLOR_THEME_BLACK_BONUS;
		fractal->theme_color.outside_max_color = COLOR_THEME_WHITE_BONUS;
		fractal->theme_color.inside_color = COLOR_THEME_GOLD_BONUS;
	}
	else if (keycode == KEY_TWO_BONUS)
	{
		fractal->theme_color.outside_min_color = COLOR_THEME_BLUE_BONUS;
		fractal->theme_color.outside_max_color = COLOR_THEME_YELLOW_BONUS;
		fractal->theme_color.inside_color = COLOR_THEME_RED_BONUS;
	}
	else if (keycode == KEY_THREE_BONUS)
	{
		fractal->theme_color.outside_min_color = COLOR_THEME_PURPLE_BONUS;
		fractal->theme_color.outside_max_color = COLOR_THEME_ORANGE_BONUS;
		fractal->theme_color.inside_color = COLOR_THEME_LIME_BONUS;
	}
	else if (keycode == KEY_FOUR_BONUS)
	{
		fractal->theme_color.outside_min_color = COLOR_THEME_CYAN_BONUS;
		fractal->theme_color.outside_max_color = COLOR_THEME_PINK_BONUS;
		fractal->theme_color.inside_color = COLOR_THEME_MAGENTA_BONUS;
	}
}

int	key_handler_bonus(int keycode, t_fractal_bonus *fractal)
{
	if (keycode == KEY_ESC_BONUS)
		close_handler_bonus(fractal);
	if (keycode == KEY_LEFT_BONUS)
		fractal->offset_x -= (0.5 * fractal->zoom);
	else if (keycode == KEY_RIGHT_BONUS)
		fractal->offset_x += (0.5 * fractal->zoom);
	else if (keycode == KEY_UP_BONUS)
		fractal->offset_y += (0.5 * fractal->zoom);
	else if (keycode == KEY_DOWN_BONUS)
		fractal->offset_y -= (0.5 * fractal->zoom);
	else if (keycode == KEY_ASTERISK_BONUS)
		fractal->iteration_count += 10;
	else if (keycode == KEY_MINUS_BONUS)
		fractal->iteration_count -= 10;
	else
		change_color_scheme_bonus(keycode, fractal);
	fractal_render_bonus(fractal);
	return (0);
}

int	mouse_handler_bonus(int button, int x, int y, t_fractal_bonus *fractal)
{
	double	rescaled_x;
	double	rescaled_y;
	double	zoom_factor;

	zoom_factor = 1.0;
	rescaled_x = rescale_bonus(x, -2, 2, WIDTH_BONUS)
		* fractal->zoom + fractal->offset_x;
	rescaled_y = rescale_bonus(y, 2, -2, HEIGHT_BONUS)
		* fractal->zoom + fractal->offset_y;
	if (button == 5)
	{
		zoom_factor = 0.7;
		fractal->zoom *= zoom_factor;
	}
	else if (button == 4)
	{
		zoom_factor = 1.3;
		fractal->zoom *= zoom_factor;
	}
	fractal->offset_x = rescaled_x
		- (rescaled_x - fractal->offset_x) * zoom_factor;
	fractal->offset_y = rescaled_y
		- (rescaled_y - fractal->offset_y) * zoom_factor;
	fractal_render_bonus(fractal);
	return (0);
}
