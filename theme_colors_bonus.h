/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   theme_colors_bonus.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azorlutu <azorlutu@student.42istanbul      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 00:57:15 by azorlutu          #+#    #+#             */
/*   Updated: 2025/03/13 00:57:15 by azorlutu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef THEME_COLORS_BONUS_H
# define THEME_COLORS_BONUS_H

# define COLOR_THEME_BLACK_BONUS 0x000000
# define COLOR_THEME_WHITE_BONUS 0xFFFFFF
# define COLOR_THEME_BLUE_BONUS 0x1E90FF
# define COLOR_THEME_YELLOW_BONUS 0xFFD700
# define COLOR_THEME_RED_BONUS 0xFF4500
# define COLOR_THEME_GREEN_BONUS 0x32CD32
# define COLOR_THEME_PURPLE_BONUS 0x8A2BE2
# define COLOR_THEME_ORANGE_BONUS 0xFFA500
# define COLOR_THEME_CYAN_BONUS 0x00FFFF
# define COLOR_THEME_PINK_BONUS 0xFF69B4
# define COLOR_THEME_GOLD_BONUS 0xDAA520
# define COLOR_THEME_AQUA_BONUS 0x00CED1
# define COLOR_THEME_LIME_BONUS 0xADFF2F
# define COLOR_THEME_MAGENTA_BONUS 0xFF00FF
# define COLOR_THEME_DEEP_BLUE_BONUS 0x00008B

typedef struct s_theme_bonus
{
	int		outside_min_color;
	int		outside_max_color;
	int		inside_color;
}	t_theme_bonus;

#endif
