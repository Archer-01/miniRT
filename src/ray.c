/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaizab <oaizab@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 17:02:06 by hhamza            #+#    #+#             */
/*   Updated: 2022/11/05 09:28:25 by oaizab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

t_ray	ray(t_tuple origin, t_tuple direction)
{
	t_ray	ray;

	ray.origin = origin;
	ray.direction = direction;
	return (ray);
}

t_tuple	ray_position(t_ray ray, float t)
{
	return (tuple_add(ray.origin, tuple_mult(ray.direction, t)));
}

t_ray	ray_transform(t_ray ray, t_matrix transform)
{
	t_ray	new_ray;

	new_ray.origin = matrix_mult_tuple(&transform, ray.origin);
	new_ray.direction = matrix_mult_tuple(&transform, ray.direction);
	return (new_ray);
}
