/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamza <hhamza@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 17:58:24 by hhamza            #+#    #+#             */
/*   Updated: 2022/11/02 18:11:16 by hhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intersections.h"

t_intersections	intersections(void)
{
	t_intersections	intersections;

	intersections.count = 0;
	intersections.capacity = 42;
	intersections.xs = malloc(intersections.capacity * sizeof(t_intersection));
	if (intersections.xs == NULL)
	{
		perror("intersections");
		exit(EXIT_FAILURE);
	}
	return (intersections);
}

t_intersection	*hit(t_intersections *intersections)
{
	t_intersection	*res;
	uint32_t		i;
	float			min;

	res = NULL;
	i = 0;
	min = -1;
	while (i < intersections->count)
	{
		if (intersections->xs[i].t > 0 \
			&& (min < 0 || intersections->xs[i].t < min))
		{
			min = intersections->xs[i].t;
			res = &intersections->xs[i];
		}
		i++;
	}
	return (res);
}

void	intersections_add(t_intersections *xs, t_intersection i)
{
	if (xs->count == xs->capacity)
	{
		xs->capacity *= 2;
		xs->xs = realloc(xs->xs, xs->capacity * sizeof(t_intersection));
		if (xs == NULL)
		{
			perror("intersections_add");
			exit(EXIT_FAILURE);
		}
	}
	xs->xs[xs->count] = i;
	++xs->count;
}
