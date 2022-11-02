/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamza <hhamza@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 17:20:57 by hhamza            #+#    #+#             */
/*   Updated: 2022/11/02 17:25:21 by hhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "material.h"

t_material	material(void)
{
	t_material	mat;

	mat.color = color(1, 1, 1);
	mat.diffuse = 0.9f;
	mat.specular = 0.9f;
	mat.shininess = 200.0f;
	return (mat);
}
