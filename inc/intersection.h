/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamza <hhamza@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 17:30:42 by hhamza            #+#    #+#             */
/*   Updated: 2022/11/02 17:50:04 by hhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERSECTION_H
# define INTERSECTION_H

# include "shape.h"
# include "tuple.h"

typedef struct s_computations
{
	double		t;
	t_shape		*object;
	t_tuple		point;
	t_tuple		eyev;
	t_tuple		normalv;
	bool		inside;
	t_tuple		over_point;
}				t_computations;

typedef struct s_intersection
{
	double		t;
	t_shape		*object;
}				t_intersection;

t_intersection	intersection(float t, t_shape *object);
t_computations	prepare_computations(t_intersection i, t_ray ray);

#endif