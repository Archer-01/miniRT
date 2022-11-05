/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_at.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaizab <oaizab@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 19:52:24 by oaizab            #+#    #+#             */
/*   Updated: 2022/11/05 09:28:14 by oaizab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shape.h"

t_tuple	normal_at_sphere(t_shape *sphere, t_tuple world_point)
{
	t_tuple		object_point;
	t_tuple		object_normal;
	t_tuple		world_normal;
	t_matrix	inverse;
	t_matrix	trans;

	inverse = shape_inverse_transform(sphere);
	object_point = matrix_mult_tuple(&inverse, world_point);
	object_normal = tuple_sub(object_point, point(0, 0, 0));
	trans = matrix_transpose(&inverse);
	world_normal = matrix_mult_tuple(&trans, object_normal);
	world_normal.w = 0;
	return (tuple_normalize(world_normal));
}

t_tuple	normal_at_plane(t_shape *plane, t_tuple world_point)
{
	t_tuple		world_n;
	t_matrix	inverse;
	t_matrix	trans;

	(void) world_point;
	inverse = shape_inverse_transform(plane);
	trans = matrix_transpose(&inverse);
	world_n = matrix_mult_tuple(&trans, vector(0, 1, 0));
	world_n.w = 0;
	return (world_n);
}

t_tuple	normal_at_cylinder(t_shape *cylinder, t_tuple world_point)
{
	t_tuple		object_point;
	t_tuple		object_normal;
	t_tuple		world_normal;
	t_matrix	inverse;
	float		dist;

	inverse = shape_inverse_transform(cylinder);
	object_point = matrix_mult_tuple(&inverse, world_point);
	dist = object_point.x * object_point.x + object_point.z * object_point.z;
	if (dist < 1 && object_point.y >= cylinder->max - EPSILON)
	{
		object_normal = vector(0, 1, 0);
	}
	else if (dist < 1 && object_point.y <= cylinder->min - EPSILON)
	{
		object_normal = vector(0, -1, 0);
	}
	else
	{
		object_normal = vector(object_point.x, 0, object_point.z);
	}
	inverse = matrix_transpose(&inverse);
	world_normal = matrix_mult_tuple(&inverse, object_normal);
	world_normal.w = 0;
	return (tuple_normalize(world_normal));
}

t_tuple	normal_at_cone(t_shape *cone, t_tuple world_point)
{
	t_tuple		object_point;
	t_tuple		object_normal;
	t_tuple		w_normal;
	t_matrix	inverse;
	float		dist;

	inverse = shape_inverse_transform(cone);
	object_point = matrix_mult_tuple(&inverse, world_point);
	dist = object_point.x * object_point.x + object_point.z * object_point.z;
	if (dist < object_point.y * object_point.y \
		&& object_point.y >= cone->max - EPSILON)
		object_normal = vector(0, 1, 0);
	else if (dist < object_point.y * object_point.y \
		&& object_point.y <= cone->min - EPSILON)
		object_normal = vector(0, -1, 0);
	else
	{
		if (object_point.y > 0)
			object_normal = vector(object_point.x, -sqrt(dist), object_point.z);
		else
			object_normal = vector(object_point.x, sqrt(dist), object_point.z);
	}
	inverse = matrix_transpose(&inverse);
	w_normal = matrix_mult_tuple(&inverse, object_normal);
	return (tuple_normalize(vector(w_normal.x, w_normal.y, w_normal.z)));
}
