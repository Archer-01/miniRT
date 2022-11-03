/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_at.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamza <hhamza@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 19:36:45 by hhamza            #+#    #+#             */
/*   Updated: 2022/11/03 21:31:56 by hhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pattern.h"
#include "shape.h"

t_color	color_at_checker(t_pattern pattern, t_shape *shape, t_tuple point)
{
	t_tuple	object_point;
	t_uv	uv;
	int		x;
	int		y;

	object_point = matrix_mult_tuple(shape_inverse_transform(shape), point);
	uv = pattern.uv_at(object_point);
	x = (int)(uv.u * pattern.width);
	y = (int)(uv.v * pattern.height);
	if ((x + y) % 2 == 0)
	{
		return (pattern.primary);
	}
	else
	{
		return (pattern.secondary);
	}
}

t_color	color_at_texture(t_pattern pattern, t_shape *shape, t_tuple point)
{
	t_tuple		object_point;
	t_uv		uv;
	uint16_t	x;
	uint16_t	y;

	object_point = matrix_mult_tuple(shape_inverse_transform(shape), point);
	uv = pattern.uv_at(object_point);
	x = (uint16_t)(uv.u * (pattern.width - 1)) + 0.5f;
	y = (uint16_t)(uv.v * (pattern.height - 1)) + 0.5f;
	return (pattern.canvas.data[x][y]);
}
