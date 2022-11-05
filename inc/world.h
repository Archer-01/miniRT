/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaizab <oaizab@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 21:37:36 by hhamza            #+#    #+#             */
/*   Updated: 2022/11/05 09:30:31 by oaizab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WORLD_H
# define WORLD_H

# include "shape.h"
# include "light.h"
# include "color.h"

typedef struct s_world
{
	t_shape		*shapes;
	t_light		*lights;
	uint16_t	shape_count;
	uint16_t	light_count;
	uint16_t	light_capacity;
	uint16_t	shape_capacity;
	t_color		ambient;
}				t_world;

t_world			world(void);
void			world_destroy(t_world world);
void			world_add_shape(t_world *world, t_shape shape);
void			world_add_light(t_world *world, t_light light);

t_intersections	world_intersect(t_world *world, t_ray ray);
t_color			shade_hit(t_world *w, t_computations *comps);
t_color			color_at(t_world *world, t_ray ray);
bool			is_shadowed(t_world *world, t_tuple point, t_light light);

#endif
