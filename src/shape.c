/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaizab <oaizab@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 19:57:24 by oaizab            #+#    #+#             */
/*   Updated: 2022/11/05 09:28:35 by oaizab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shape.h"

t_shape	shape(void)
{
	t_shape	s;

	s.transformation = matrix();
	s.inverse_transformation = matrix();
	s.is_inversed = true;
	s.material = material();
	s.intersect = NULL;
	s.normal_at = NULL;
	s.min = -0.5f;
	s.max = 0.5f;
	return (s);
}

t_matrix	shape_inverse_transform(t_shape *object)
{
	if (!object->is_inversed)
	{
		object->inverse_transformation = matrix_inverse(object->transformation);
		object->is_inversed = true;
	}
	return (object->inverse_transformation);
}

void	add_transformation(t_shape *object, t_matrix transformation)
{
	object->transformation \
		= matrix_mult(&transformation, &object->transformation);
	object->is_inversed = false;
}
