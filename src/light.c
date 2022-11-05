/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaizab <oaizab@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 20:47:46 by hhamza            #+#    #+#             */
/*   Updated: 2022/11/05 09:21:44 by oaizab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "light.h"

t_light	light(t_tuple position, t_color color, float ratio)
{
	t_light	light;

	light.position = position;
	light.intensity = color_mult(&color, ratio);
	return (light);
}
