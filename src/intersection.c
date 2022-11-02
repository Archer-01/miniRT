/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamza <hhamza@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 17:34:25 by hhamza            #+#    #+#             */
/*   Updated: 2022/11/02 17:51:02 by hhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intersection.h"

t_intersection	intersection(float t, t_shape *object)
{
	t_intersection	intersection;

	intersection.t = t;
	intersection.object = object;
	return (intersection);
}

t_computations	prepare_computations(t_intersection i, t_ray ray)
{
	t_computations	comps;

	comps.t = i.t;
	comps.object = i.object;
	comps.point = ray_position(ray, i.t);
	comps.eyev = tuple_neg(ray.direction);
	comps.normalv = comps.object->normal_at(comps.object, comps.point);
	if (tuple_dot(comps.normalv, comps.eyev) < 0)
	{
		comps.inside = true;
		comps.normalv = tuple_neg(comps.normalv);
	}
	else
	{
		comps.inside = false;
	}
	comps.over_point = \
		tuple_add(comps.point, tuple_mult(comps.normalv, 0.005f));
	return (comps);
}
