/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_events_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azorlutu <azorlutu@student.42istanbul      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 21:28:24 by azorlutu          #+#    #+#             */
/*   Updated: 2025/03/12 21:28:25 by azorlutu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	events_init_bonus(t_fractal_bonus *fractal)
{
	mlx_key_hook(fractal->mlx_window, key_handler_bonus, fractal);
	mlx_mouse_hook(fractal->mlx_window, mouse_handler_bonus, fractal);
	mlx_hook(fractal->mlx_window, EVENT_CLOSE_BTN_BONUS,
		0, close_handler_bonus, fractal);
}
