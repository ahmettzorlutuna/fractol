/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azorlutu <azorlutu@student.42istanbul      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 21:27:26 by azorlutu          #+#    #+#             */
/*   Updated: 2025/03/12 21:27:27 by azorlutu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_BONUS_H
# define FRACTOL_BONUS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "minilibx-linux/mlx.h"
# include "theme_colors_bonus.h"
# include "keys_bonus.h"

# define WIDTH_BONUS 800
# define HEIGHT_BONUS 800

typedef struct s_complex_bonus
{
	double	x;
	double	y;
}	t_complex_bonus;

typedef struct s_img_bonus
{
	void	*img_ptr;
	char	*pixels_ptr;
	int		bpp;
	int		endian;
	int		line_len;
}	t_img_bonus;

typedef struct s_fractal_bonus
{
	char			*name;
	void			*mlx_connection;
	void			*mlx_window;
	double			escape_value;
	int				iteration_count;
	double			offset_x;
	double			offset_y;
	double			zoom;
	double			julia_x;
	double			julia_y;
	int				theme_index;
	t_img_bonus		img;
	t_theme_bonus	theme_color;
}	t_fractal_bonus;

int			ft_strncmp_bonus(const char *s1, const char *s2, char byte);
int			key_handler_bonus(int keycode, t_fractal_bonus *fractal);
int			close_handler_bonus(t_fractal_bonus *fractal);
int			mouse_handler_bonus(int button, int x, int y,
				t_fractal_bonus *fractal);
int			mandelbrot_bonus(t_complex_bonus z, t_complex_bonus c,
				int max_iterations, double escape_value);
int			julia_bonus(t_complex_bonus z, t_complex_bonus c,
				int max_iterations, double escape_value);
int			tricorn_bonus(t_complex_bonus z, t_complex_bonus c,
				int max_iterations, double escape_value);

void		ft_putstr_fd_bonus(char *str, int fd);
void		malloc_error_bonus(void);
void		fractal_init_bonus(t_fractal_bonus *fractal);
void		fractal_render_bonus(t_fractal_bonus *fractal);
void		events_init_bonus(t_fractal_bonus *fractal);
void		print_error_message_bonus(int fd);
void		print_controls_message_bonus(int fd);
void		paint_pixel_bonus(int x, int y, t_img_bonus *img, int color);
void		rescale_and_set_bonus(t_complex_bonus *complex1,
				t_complex_bonus *complex2, t_fractal_bonus *fractal);

double		ft_atodbl_bonus(char *s);
double		rescale_bonus(double unscaled_num,
				double new_min, double new_max, double old_max);

#endif
