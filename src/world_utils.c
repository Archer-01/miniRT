/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaizab <oaizab@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 09:42:04 by oaizab            #+#    #+#             */
/*   Updated: 2022/11/04 12:23:17 by oaizab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "world.h"

t_intersections	world_intersect(t_world w, t_ray r)
{
	t_intersections	xs;
	t_intersections	x;
	u_int16_t		i;
	u_int16_t		j;

	i = 0;
	xs = intersections();
	while (i < w.shape_count)
	{
		x = w.shapes[i].intersect(&w.shapes[i], r);
		j = 0;
		while (j < x.count)
		{
			intersections_add(&xs, x.xs[j]);
			j++;
		}
		free(x.xs);
		i++;
	}
	return (xs);
}

t_color	shade_hit(t_world w, t_computations comps)
{
	uint16_t	i;
	t_color		c;
	bool		shadowed;

	c = color(0, 0, 0);
	i = 0;
	while (i < w.light_count)
	{
		shadowed = is_shadowed(w, comps.over_point, w.lights[i]);
		c = color_add(c, lighting(w.lights[i], comps, shadowed, w.ambient));
		++i;
	}
	return (c);
}

t_color	color_at(t_world w, t_ray r)
{
	t_intersections	xs;
	t_intersection	*h;
	t_computations	comps;

	xs = world_intersect(w, r);
	h = hit(&xs);
	if (h == NULL)
	{
		return (color(0, 0, 0));
	}
	else
	{
		comps = prepare_computations(*h, r);
	}
	return (shade_hit(w, comps));
}

bool	is_shadowed(t_world w, t_tuple p, t_light l)
{
	t_tuple			v;
	float			distance;
	t_ray			r;
	t_intersections	xs;
	t_intersection	*h;

	v = tuple_sub(l.position, p);
	distance = tuple_magnitude(v);
	r = ray(p, tuple_normalize(v));
	xs = world_intersect(w, r);
	h = hit(&xs);
	free(xs.xs);
	if (h != NULL && h->t < distance)
	{
		return (true);
	}
	else
	{
		return (false);
	}
}
