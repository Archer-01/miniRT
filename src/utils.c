/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamza <hhamza@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 17:09:26 by hhamza            #+#    #+#             */
/*   Updated: 2022/11/02 16:49:04 by hhamza           ###   ########.fr       */
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
