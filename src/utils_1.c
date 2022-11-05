/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamza <hhamza@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 17:17:58 by hhamza            #+#    #+#             */
/*   Updated: 2022/11/05 17:19:34 by hhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

bool	float_eq(float a, float b)
{
	return (fabs(a - b) < EPSILON);
}

void	float_swap(float *a, float *b)
{
	float	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

float	deg_to_rad(float deg)
{
	return (deg * M_PI / 180);
}

uint32_t	get_rgba(uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
	return ((r << 24) | (g << 16) | (b << 8) | a);
}

bool	check_float(char const *str)
{
	size_t	i;

	i = 0;
	if (str[i] == '-')
		++i;
	while (str[i] != '\0' && ft_isdigit(str[i]))
		++i;
	if (str[i] == '.')
		++i;
	while (str[i] != '\0' && ft_isdigit(str[i]))
		++i;
	if (str[i] == '\0')
		return (true);
	return (false);
}
