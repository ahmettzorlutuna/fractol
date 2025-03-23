/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azorlutu <azorlutu@student.42istanbul      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 21:27:26 by azorlutu          #+#    #+#             */
/*   Updated: 2025/03/12 21:27:27 by azorlutu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "minilibx-linux/mlx.h"
# include "theme_colors.h"
# include "keys.h"

# define WIDTH 800
# define HEIGHT 800

typedef struct s_complex
{
	double	x;
	double	y;
}	t_complex;

typedef struct s_img
{
	void	*img_ptr;
	char	*pixels_ptr;
	int		bpp;
	int		endian;
	int		line_len;
}	t_img;

typedef struct s_fractal
{
	char	*name;
	void	*mlx_connection;
	void	*mlx_window;
	t_img	img;
	double	escape_value;
	int		iteration_count;
	double	offset_x;
	double	offset_y;
	double	zoom;
	double	julia_x;
	double	julia_y;
	int		theme_index;
	t_theme	theme_color;
}	t_fractal;

int			ft_strncmp(const char *s1, const char *s2, char byte);
int			key_handler(int keycode, t_fractal *fractal);
int			close_handler(t_fractal *fractal);
int			mouse_handler(int button, int x, int y, t_fractal *fractal);
int			mandelbrot(t_complex z, t_complex c,
				int max_iterations, double escape_value);
int			julia(t_complex z, t_complex c,
				int max_iterations, double escape_value);
int			tricorn(t_complex z, t_complex c,
				int max_iterations, double escape_value);

void		ft_putstr_fd(char *str, int fd);
void		malloc_error(void);
void		fractal_init(t_fractal *fractal);
void		fractal_render(t_fractal *fractal);
void		events_init(t_fractal *fractal);
void		print_error_message(int fd);
void		print_controls_message(int fd);
void		paint_pixel(int x, int y, t_img *img, int color);
void		rescale_and_set(t_complex *complex1,
				t_complex *complex2, t_fractal *fractal);

double		ft_atodbl(char *s);
double		rescale(double unscaled_num,
				double new_min, double new_max, double old_max);

#endif
