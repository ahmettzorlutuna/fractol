/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azorlutu <azorlutu@student.42istanbul      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 21:25:04 by azorlutu          #+#    #+#             */
/*   Updated: 2025/03/12 21:25:04 by azorlutu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strncmp(const char *s1, const char *s2, char byte)
{
	unsigned char	*uns1;
	unsigned char	*uns2;
	int				i;

	uns1 = (unsigned char *)s1;
	uns2 = (unsigned char *)s2;
	i = 0;
	if (byte == 0)
		return (0);
	while (uns1[i] != '\0' && uns2[i] != '\0'
		&& uns1[i] == uns2[i] && i <= byte - 1)
		i++;
	return (uns1[i] - uns2[i]);
}

void	ft_putstr_fd(char *str, int fd)
{
	if (str == NULL || fd < 0)
		return ;
	if (*str != '\0')
	{
		write(fd, str, 1);
		ft_putstr_fd(str + 1, fd);
	}
}

static void	check_overflow(long digit, long result, long sign)
{
	if (sign == -1 && result > (2147483648 - digit) / 10)
		exit(EXIT_FAILURE);
	else if (sign == 1 && result > (2147483647 - digit) / 10)
		exit(EXIT_FAILURE);
}

static int	parse_sign_and_skip_spaces(char **s)
{
	int	sign;

	sign = 1;
	while ((**s >= 9 && **s <= 13) || **s == 32)
		(*s)++;
	if (**s == '+' || **s == '-')
		if (*((*s)++) == '-')
			sign = -1;
	return (sign);
}

double	ft_atodbl(char *s)
{
	long	integer_part;
	double	fractional_part;
	double	pow;
	int		sign;

	integer_part = 0;
	fractional_part = 0;
	pow = 1;
	sign = parse_sign_and_skip_spaces(&s);
	while (*s != '.' && *s)
	{
		check_overflow(*s - 48, integer_part, sign);
		integer_part = (integer_part * 10) + (*s++ - 48);
	}
	if ('.' == *s)
		++s;
	while (*s && (*s >= '0' && *s <= '9'))
	{
		pow /= 10;
		fractional_part = fractional_part + (*s++ - 48) * pow;
	}
	return ((integer_part + fractional_part) * sign);
}
