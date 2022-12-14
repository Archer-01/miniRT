/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_cone.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamza <hhamza@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 19:30:24 by oaizab            #+#    #+#             */
/*   Updated: 2022/11/07 23:23:17 by hhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shape.h"

static bool	check_cap(t_ray r, float t, float radius)
{
	float	x;
	float	z;

	x = r.origin.x + t * r.direction.x;
	z = r.origin.z + t * r.direction.z;
	return (x * x + z * z <= radius * radius);
}

static t_intersections	*intersect_caps(t_shape *s, t_ray r, \
	t_intersections *xs)
{
	float	t;

	if (float_eq(r.direction.y, 0))
		return (xs);
	t = (s->min - r.origin.y) / r.direction.y;
	if (check_cap(r, t, s->min))
		intersections_add(xs, intersection(t, s));
	t = (s->max - r.origin.y) / r.direction.y;
	if (check_cap(r, t, s->max))
		intersections_add(xs, intersection(t, s));
	return (xs);
}

t_intersections	intersect_side_cone(float *abc, t_ray r, t_shape *self, \
	t_intersections *xs)
{
	float	t;
	float	y;
	float	delta;

	delta = abc[1] * abc[1] - 4 * abc[0] * abc[2];
	if (delta < 0)
		return (free(xs->xs), intersections());
	delta = sqrt(delta);
	t = (-abc[1] - delta) / (2 * abc[0]);
	y = r.origin.y + t * r.direction.y;
	if (y >= self->min && y <= self->max)
		intersections_add(xs, intersection(t, self));
	t = (-abc[1] + delta) / (2 * abc[0]);
	y = r.origin.y + t * r.direction.y;
	if (y >= self->min && y <= self->max)
		intersections_add(xs, intersection(t, self));
	return (intersect_caps(self, r, xs), *xs);
}

t_intersections	intersect_cone(t_shape *self, t_ray r)
{
	t_intersections	xs;
	float			abc[3];

	xs = intersections();
	r = ray_transform(r, shape_inverse_transform(self));
	abc[0] = r.direction.x * r.direction.x + r.direction.z * r.direction.z \
		- r.direction.y * r.direction.y;
	abc[1] = 2 * r.origin.x * r.direction.x + 2 * r.origin.z * r.direction.z \
		- 2 * r.origin.y * r.direction.y;
	if (float_eq(abc[0], 0) && float_eq(abc[1], 0))
		return (*intersect_caps(self, r, &xs));
	abc[2] = r.origin.x * r.origin.x + r.origin.z * r.origin.z - r.origin.y \
		* r.origin.y;
	if (float_eq(abc[0], 0))
		intersections_add(&xs, intersection(-abc[2] / (2 * abc[1]), self));
	return (intersect_side_cone(abc, r, self, &xs));
}
