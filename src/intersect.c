/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamza <hhamza@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 20:36:59 by oaizab            #+#    #+#             */
/*   Updated: 2022/11/07 23:22:20 by hhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shape.h"

t_intersections	intersect_sphere(t_shape *self, t_ray ray)
{
	t_intersections	xs;
	t_ray			ray_object_space;
	t_tuple			sphere_to_ray;
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
	xs = intersections();
	intersections_add(&xs, intersection((-abc[1] - dlta) / (2 * abc[0]), self));
	intersections_add(&xs, intersection((-abc[1] + dlta) / (2 * abc[0]), self));
	return (xs);
}

t_intersections	intersect_plane(t_shape *self, t_ray r)
{
	t_intersections	xs;
	t_ray			ray_object_space;
	float			t;

	ray_object_space = ray_transform(r, shape_inverse_transform(self));
	if (float_eq(ray_object_space.direction.y, 0))
		return (intersections());
	t = -ray_object_space.origin.y / ray_object_space.direction.y;
	xs = intersections();
	intersections_add(&xs, intersection(t, self));
	return (xs);
}

static bool	check_cap(t_ray r, float t)
{
	float	x;
	float	z;

	x = r.origin.x + t * r.direction.x;
	z = r.origin.z + t * r.direction.z;
	return (x * x + z * z <= 1);
}

static t_intersections	*intersect_caps(t_shape *s, t_ray r, \
	t_intersections *xs)
{
	float	t;

	if (float_eq(r.direction.y, 0))
		return (xs);
	t = (s->min - r.origin.y) / r.direction.y;
	if (check_cap(r, t))
		intersections_add(xs, intersection(t, s));
	t = (s->max - r.origin.y) / r.direction.y;
	if (check_cap(r, t))
		intersections_add(xs, intersection(t, s));
	return (xs);
}

t_intersections	intersect_cylinder(t_shape *self, t_ray r)
{
	t_intersections	xs;
	float			abc[3];
	float			dlta;
	float			ty[2];

	r = ray_transform(r, shape_inverse_transform(self));
	abc[0] = r.direction.x * r.direction.x + r.direction.z * r.direction.z;
	xs = intersections();
	if (float_eq(abc[0], 0))
		return (*intersect_caps(self, r, &xs));
	abc[1] = 2 * r.origin.x * r.direction.x + 2 * r.origin.z * r.direction.z;
	abc[2] = r.origin.x * r.origin.x + r.origin.z * r.origin.z - 1;
	dlta = abc[1] * abc[1] - 4 * abc[0] * abc[2];
	if (dlta < 0)
		return (free(xs.xs), intersections());
	dlta = sqrt(dlta);
	ty[0] = (-abc[1] - dlta) / (2 * abc[0]);
	ty[1] = r.origin.y + ty[0] * r.direction.y;
	if (ty[1] >= self->min && ty[1] <= self->max)
		intersections_add(&xs, intersection(ty[0], self));
	ty[0] = (-abc[1] + dlta) / (2 * abc[0]);
	ty[1] = r.origin.y + ty[0] * r.direction.y;
	if (ty[1] >= self->min && ty[1] <= self->max)
		intersections_add(&xs, intersection(ty[0], self));
	return (intersect_caps(self, r, &xs), xs);
}
