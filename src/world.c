/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamza <hhamza@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 08:49:28 by oaizab            #+#    #+#             */
/*   Updated: 2022/11/07 23:14:14 by hhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "world.h"

t_world	world(void)
{
	t_world	world;

	world.shapes = malloc(sizeof(t_shape) * 42);
	if (!world.shapes)
	{
		perror("world");
		exit(EXIT_FAILURE);
	}
	world.lights = malloc(sizeof(t_light) * 42);
	if (!world.lights)
	{
		perror("world");
		exit(EXIT_FAILURE);
	}
	world.shape_capacity = 42;
	world.light_capacity = 42;
	world.shape_count = 0;
	world.light_count = 0;
	return (world);
}

void	world_destroy(t_world w)
{
	uint16_t	i;

	free(w.lights);
	i = 0;
	while (i < w.shape_count)
	{
		if (w.shapes[i].material.has_pattern \
			&& w.shapes[i].material.pattern.color_at == color_at_texture)
			canvas_destroy(&w.shapes[i].material.pattern.canvas);
		++i;
	}
	free(w.shapes);
}

void	world_add_shape(t_world *w, t_shape s)
{
	if (w->shape_count == w->shape_capacity)
	{
		w->shape_capacity *= 2;
		w->shapes = realloc(w->shapes, w->shape_capacity * sizeof(t_shape));
		if (w->shapes == NULL)
		{
			perror("world_add_shape");
			exit(EXIT_FAILURE);
		}
	}
	w->shapes[w->shape_count] = s;
	++(w->shape_count);
}

void	world_add_light(t_world *w, t_light l)
{
	if (w->light_count == w->light_capacity)
	{
		w->light_capacity *= 2;
		w->lights = realloc(w->lights, w->light_capacity * sizeof(t_light));
		if (w->lights == NULL)
		{
			perror("world_add_light");
			exit(EXIT_FAILURE);
		}
	}
	w->lights[w->light_count] = l;
	++(w->light_count);
}
