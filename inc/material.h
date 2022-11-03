/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamza <hhamza@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 17:18:03 by hhamza            #+#    #+#             */
/*   Updated: 2022/11/03 21:33:00 by hhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIAL_H
# define MATERIAL_H

# include "utils.h"
# include "color.h"
# include "pattern.h"
# include "light.h"

typedef struct s_computations	t_computations;

typedef struct s_material
{
	t_color		color;
	float		diffuse;
	float		specular;
	float		shininess;
	t_pattern	pattern;
	bool		has_pattern;
}				t_material;

t_material		material(void);
t_color			lighting(t_light light, t_computations comps, bool shadowed, \
	t_color ambient);

#endif