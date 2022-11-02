/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaizab <oaizab@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 20:36:59 by oaizab            #+#    #+#             */
/*   Updated: 2022/11/02 20:56:59 by oaizab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shape.h"

t_intersections	intersect_sphere(t_shape *self, t_ray ray)
{
	t_intersections	xs;
	t_ray			ray_object_space;
	t_tuple		sphere_to_ray;
	float			abc[3];
	float			dlta;

	ray_object_space = ray_transform(ray, shape_inverse_transform(self));
	sphere_to_ray = tuple_sub(ray_object_space.origin, point(0, 0, 0));
	abc[0] = tuple_dot(ray_object_space.direction, ray_object_space.direction);
	abc[1] = 2 * tuple_dot(ray_object_space.direction, sphere_to_ray);
	abc[2] = tuple_dot(sphere_to_ray, sphere_to_ray) - 1;
	dlta = abc[1] * abc[1] - 4 * abc[0] * abc[2];
	if (dlta < 0)
		return (intersections());
	dlta = sqrt(dlta);
	intersections_add(&xs, intersection((-abc[1] - dlta) / (2 * abc[0]), self));
	intersections_add(&xs, intersection((-abc[1] + dlta) / (2 * abc[0]), self));
	return (xs);
}

t_intersections	intersect_plane(t_shape *self, t_ray ray)
{
	t_intersections	xs;
	t_ray			ray_object_space;
	float			t;

	ray_object_space = ray_transform(ray, shape_inverse_transform(self));
	if (float_eq(ray_object_space.direction.y, 0))
		return (intersections());
	t = -ray_object_space.origin.y / ray_object_space.direction.y;
	intersections_add(&xs, intersection(t, self));
	return (xs);
}

t_intersections	intersect_cylinder(t_shape *self, t_ray ray)
{
	t_intersections	xs;
	t_ray			ray_object_space;
	float			abc[3];
	float			dlta;
	float			ty[2];
	
	ray_object_space = ray_transform(ray, shape_inverse_transform(self));
	abc[0] = ray_object_space.direction.x * ray_object_space.direction.x \
		+ ray_object_space.direction.z * ray_object_space.direction.z;
	if (float_eq(abc[0], 0))
		return (intersections());
	abc[1] = 2 * ray_object_space.origin.x * ray_object_space.direction.x \
		+ 2 * ray_object_space.origin.z * ray_object_space.direction.z;
	abc[2] = ray_object_space.origin.x * ray_object_space.origin.x \
		+ ray_object_space.origin.z * ray_object_space.origin.z - 1;
	dlta = abc[1] * abc[1] - 4 * abc[0] * abc[2];
	if (dlta < 0)
		return (intersections());
	dlta = sqrt(dlta);
	ty[0] = (-abc[1] - dlta) / (2 * abc[0]);
	ty[1] = ray_object_space.origin.y + ty[0] * ray_object_space.direction.y;
	if (ty[1] >= self->min && ty[1] <= self->max)
		intersections_add(&xs, intersection(ty[0], self));
	ty[0] = (-abc[1] + dlta) / (2 * abc[0]);
	ty[1] = ray_object_space.origin.y + ty[0] * ray_object_space.direction.y;
	if (ty[1] >= self->min && ty[1] <= self->max)
		intersections_add(&xs, intersection(ty[0], self));
	return (xs);
}
