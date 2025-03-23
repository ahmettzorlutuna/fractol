/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   theme_colors.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azorlutu <azorlutu@student.42istanbul      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 00:57:15 by azorlutu          #+#    #+#             */
/*   Updated: 2025/03/13 00:57:15 by azorlutu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef THEME_COLORS_H
# define THEME_COLORS_H

# define COLOR_THEME_BLACK 0x000000
# define COLOR_THEME_WHITE 0xFFFFFF
# define COLOR_THEME_BLUE 0x1E90FF
# define COLOR_THEME_YELLOW 0xFFD700
# define COLOR_THEME_RED 0xFF4500
# define COLOR_THEME_GREEN 0x32CD32
# define COLOR_THEME_PURPLE 0x8A2BE2
# define COLOR_THEME_ORANGE 0xFFA500
# define COLOR_THEME_CYAN 0x00FFFF
# define COLOR_THEME_PINK 0xFF69B4
# define COLOR_THEME_GOLD 0xDAA520
# define COLOR_THEME_AQUA 0x00CED1
# define COLOR_THEME_LIME 0xADFF2F
# define COLOR_THEME_MAGENTA 0xFF00FF
# define COLOR_THEME_DEEP_BLUE 0x00008B

typedef struct s_theme
{
	int		outside_min_color;
	int		outside_max_color;
	int		inside_color;
}	t_theme;

#endif
