/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaizab <oaizab@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 17:14:15 by hhamza            #+#    #+#             */
/*   Updated: 2022/11/02 20:29:47 by oaizab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHAPE_H
# define SHAPE_H

# include "matrix.h"
# include "material.h"
# include "ray.h"
# include "tuple.h"
# include "intersections.h"

typedef struct s_intersections	t_intersections;

typedef struct s_shape
{
	t_matrix		transformation;
	t_matrix		inverse_transformation;
	bool			is_inversed;
	t_material		material;
	t_intersections	(*intersect)(struct s_shape *self, t_ray ray);
	t_tuple			(*normal_at)(struct s_shape *self, t_tuple point);
	float			min;
	float			max;
}				t_shape;

t_shape			shape(void);
t_matrix		shape_inverse_transform(t_shape *shape);
void			add_transformation(t_shape *shape, t_matrix transformation);

t_intersections	intersect_sphere(t_shape *self, t_ray ray);
t_intersections	intersect_cylinder(t_shape *self, t_ray ray);
t_intersections	intersect_plane(t_shape *self, t_ray ray);
t_intersections	interesect_cone(t_shape *self, t_ray ray);

t_tuple			normal_at_sphere(t_shape *self, t_tuple point);
t_tuple			normal_at_cylinder(t_shape *self, t_tuple point);
t_tuple			normal_at_plane(t_shape *self, t_tuple point);
t_tuple			normal_at_cone(t_shape *self, t_tuple point);

#endif