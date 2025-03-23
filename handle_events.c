/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azorlutu <azorlutu@student.42istanbul      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 22:30:22 by azorlutu          #+#    #+#             */
/*   Updated: 2025/03/12 22:30:23 by azorlutu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "theme_colors.h"

int	close_handler(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx_connection, fractal->img.img_ptr);
	mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
	mlx_destroy_display(fractal->mlx_connection);
	free(fractal->mlx_connection);
	exit(EXIT_SUCCESS);
}

static	void	change_color_scheme(int keycode, t_fractal *fractal)
{
	if (keycode == KEY_ONE)
	{
		fractal->theme_color.outside_min_color = COLOR_THEME_BLACK;
		fractal->theme_color.outside_max_color = COLOR_THEME_WHITE;
		fractal->theme_color.inside_color = COLOR_THEME_GOLD;
	}
	else if (keycode == KEY_TWO)
	{
		fractal->theme_color.outside_min_color = COLOR_THEME_BLUE;
		fractal->theme_color.outside_max_color = COLOR_THEME_YELLOW;
		fractal->theme_color.inside_color = COLOR_THEME_RED;
	}
	else if (keycode == KEY_THREE)
	{
		fractal->theme_color.outside_min_color = COLOR_THEME_PURPLE;
		fractal->theme_color.outside_max_color = COLOR_THEME_ORANGE;
		fractal->theme_color.inside_color = COLOR_THEME_LIME;
	}
	else if (keycode == KEY_FOUR)
	{
		fractal->theme_color.outside_min_color = COLOR_THEME_CYAN;
		fractal->theme_color.outside_max_color = COLOR_THEME_PINK;
		fractal->theme_color.inside_color = COLOR_THEME_MAGENTA;
	}
}

int	key_handler(int keycode, t_fractal *fractal)
{
	if (keycode == KEY_ESC)
		close_handler(fractal);
	if (keycode == KEY_LEFT)
		fractal->offset_x -= (0.5 * fractal->zoom);
	else if (keycode == KEY_RIGHT)
		fractal->offset_x += (0.5 * fractal->zoom);
	else if (keycode == KEY_UP)
		fractal->offset_y += (0.5 * fractal->zoom);
	else if (keycode == KEY_DOWN)
		fractal->offset_y -= (0.5 * fractal->zoom);
	else if (keycode == KEY_ASTERISK)
		fractal->iteration_count += 10;
	else if (keycode == KEY_MINUS)
		fractal->iteration_count -= 10;
	else
		change_color_scheme(keycode, fractal);
	fractal_render(fractal);
	return (0);
}

int	mouse_handler(int button, int x, int y, t_fractal *fractal)
{
	(void)x;
	(void)y;
	if (button == 5)
	{
		fractal->zoom *= 0.7;
	}
	else if (button == 4)
	{
		fractal->zoom *= 1.3;
	}
	fractal_render(fractal);
	return (0);
}
