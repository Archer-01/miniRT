/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaizab <oaizab@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 17:20:57 by hhamza            #+#    #+#             */
/*   Updated: 2022/11/05 09:59:28 by oaizab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "material.h"
#include "intersections.h"

t_material	material(void)
{
	t_material	mat;

	mat.color = color(1, 1, 1);
	mat.diffuse = 0.9f;
	mat.specular = 0.9f;
	mat.shininess = 200.0f;
	mat.has_pattern = false;
	return (mat);
}

/**
 * @note: phong colors are ambient, diffuse and specular in order
 * @note: vectors are light_v and reflect_v in order
 * @note: ldn means light dot normal
 * @note: rde means reflect dot eye
 */
t_color	lighting(t_light light, t_computations *comps, bool shadowed, \
	t_color ambient)
{
	t_color		eff_color;
	t_color		phong[3];
	t_tuple		vectors[2];
	float		ldnrde;

	eff_color = comps->object->material.color;
	if (comps->object->material.has_pattern)
		eff_color = comps->object->material.pattern.color_at(\
			&comps->object->material.pattern, comps->object, comps->over_point);
	eff_color = color_mult_color(&eff_color, &light.intensity);
	phong[0] = color_mult_color(&eff_color, &ambient);
	if (shadowed)
		return (phong[0]);
	vectors[0] = tuple_normalize(tuple_sub(light.position, comps->over_point));
	ldnrde = tuple_dot(vectors[0], comps->normalv);
	if (ldnrde < 0)
		return (phong[0]);
	phong[1] = color_mult(&eff_color, comps->object->material.diffuse * ldnrde);
	vectors[1] = tuple_reflect(tuple_neg(vectors[0]), comps->normalv);
	ldnrde = tuple_dot(vectors[1], comps->eyev);
	if (ldnrde <= 0)
		return (color_add(phong[0], phong[1]));
	phong[2] = color_mult(&light.intensity, pow(ldnrde, \
		comps->object->material.shininess) * comps->object->material.specular);
	return (color_add(color_add(phong[0], phong[1]), phong[2]));
}
