/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azorlutu <azorlutu@student.42istanbul      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 01:19:21 by azorlutu          #+#    #+#             */
/*   Updated: 2025/03/13 01:19:22 by azorlutu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	print_error_message_bonus(int fd)
{
	ft_putstr_fd_bonus("\033[1;31mInvalid usage for bonus.\033[0m\n\n", fd);
	ft_putstr_fd_bonus("\033[1;36mUsage:\033[0m\n", fd);
	ft_putstr_fd_bonus("  ./fractol mandelbrot\n", fd);
	ft_putstr_fd_bonus("  ./fractol julia <real> <imaginary>\n", fd);
	ft_putstr_fd_bonus("  ./fractol tricorn\n\n", fd);
	ft_putstr_fd_bonus("\033[1;36mDescription:\033[0m\n", fd);
	ft_putstr_fd_bonus("  mandelbrot      - Displays the Mandelbrot set.\n", fd);
	ft_putstr_fd_bonus("  julia <r> <i>   - Displays the Julia \n", fd);
	ft_putstr_fd_bonus("set with parameters (real, imaginary).\n", fd);
	ft_putstr_fd_bonus("  tricorn         - Displays the Tricorn set.\n\n", fd);
	ft_putstr_fd_bonus("\033[1;36mExamples:\033[0m\n", fd);
	ft_putstr_fd_bonus("  ./fractol mandelbrot\n", fd);
	ft_putstr_fd_bonus("  ./fractol julia (-0.7) (0.27015) \n", fd);
	ft_putstr_fd_bonus("  ./fractol julia (0.285) (0) \n", fd);
	ft_putstr_fd_bonus("  ./fractol julia (-0.835) (-0.2321) \n", fd);
	ft_putstr_fd_bonus("  ./fractol julia (-0.4) (0.6) \n", fd);
	ft_putstr_fd_bonus("  ./fractol tricorn\n", fd);
}

void	print_controls_message_bonus(int fd)
{
	ft_putstr_fd_bonus("\033[1;34mControls:\033[0m\n\n", fd);
	ft_putstr_fd_bonus("\033[1;36mMovement:\033[0m\n", fd);
	ft_putstr_fd_bonus("  \033[1;32m← Left Arrow\033[0m   - Move left\n", fd);
	ft_putstr_fd_bonus("  \033[1;32m→ Right Arrow\033[0m  - Move right\n", fd);
	ft_putstr_fd_bonus("  \033[1;32m↑ Up Arrow\033[0m     - Move up\n", fd);
	ft_putstr_fd_bonus("  \033[1;32m↓ Down Arrow\033[0m   - Move down\n\n", fd);
	ft_putstr_fd_bonus("\033[1;36mZoom:\033[0m\n", fd);
	ft_putstr_fd_bonus("  \033[1;32mMouse Wheel Up\033[0m   - Zoom in\n", fd);
	ft_putstr_fd_bonus("  \033[1;32mMouse Wheel Down\033[0m - Zoom out\n\n", fd);
	ft_putstr_fd_bonus("\033[1;36mIterations:\033[0m\n", fd);
	ft_putstr_fd_bonus("  \033[1;32m*\033[0m - Increase iterations\n", fd);
	ft_putstr_fd_bonus("  \033[1;32m-\033[0m - Decrease iterations\n\n", fd);
	ft_putstr_fd_bonus("\033[1;36mThemes:\033[0m\n", fd);
	ft_putstr_fd_bonus("  \033[1;32m1\033[0m - Gold Adventure\n", fd);
	ft_putstr_fd_bonus("  \033[1;32m2\033[0m - High Contrast\n", fd);
	ft_putstr_fd_bonus("  \033[1;32m3\033[0m - Art\n", fd);
	ft_putstr_fd_bonus("  \033[1;32m4\033[0m - Retro\n", fd);
	ft_putstr_fd_bonus("\033[1;36mExit:\033[0m\n", fd);
	ft_putstr_fd_bonus("  \033[1;31mESC\033[0m - Close application\n", fd);
}
