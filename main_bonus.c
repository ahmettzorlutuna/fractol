/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azorlutu <azorlutu@student.42istanbul      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 21:25:37 by azorlutu          #+#    #+#             */
/*   Updated: 2025/03/12 21:25:38 by azorlutu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

int	main(int argc, char **argv)
{
	t_fractal_bonus	fractal;

	if ((argc == 2 && (!ft_strncmp_bonus(argv[1], "mandelbrot", 10)
				|| !ft_strncmp_bonus(argv[1], "burning_ship", 12)
				|| !ft_strncmp_bonus(argv[1], "tricorn", 7)))
		|| (argc == 4 && !ft_strncmp_bonus(argv[1], "julia", 5)))
	{
		print_controls_message_bonus(STDOUT_FILENO);
		fractal.name = argv[1];
		if (!ft_strncmp_bonus(argv[1], "julia", 5))
		{
			fractal.julia_x = ft_atodbl_bonus(argv[2]);
			fractal.julia_y = ft_atodbl_bonus(argv[3]);
		}
		fractal_init_bonus(&fractal);
		fractal_render_bonus(&fractal);
		mlx_loop(fractal.mlx_connection);
	}
	else
	{
		print_error_message_bonus(STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	return (0);
}
