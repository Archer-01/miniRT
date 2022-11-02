/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamza <hhamza@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 17:18:03 by hhamza            #+#    #+#             */
/*   Updated: 2022/11/02 17:23:35 by hhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIAL_H
# define MATERIAL_H

# include "utils.h"
# include "color.h"

typedef struct s_material
{
	t_color		color;
	float		diffuse;
	float		specular;
	float		shininess;
	// TODO: Add pattern
}				t_material;

t_material		material(void);
// TODO: Add lighting

#endif