/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pattern.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaizab <oaizab@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 08:51:46 by oaizab            #+#    #+#             */
/*   Updated: 2022/11/05 08:58:58 by oaizab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pattern.h"

t_pattern	checker(uint16_t width, uint16_t height, t_color *primary,
				t_color *secondary)
{
	t_pattern	pattern;

	pattern.color_at = color_at_checker;
	pattern.uv_at = NULL;
	pattern.width = width;
	pattern.height = height;
	pattern.primary = *primary;
	pattern.secondary = *secondary;
	return (pattern);
}

t_pattern	texture(t_canvas *canvas)
{
	t_pattern	pattern;

	pattern.color_at = color_at_texture;
	pattern.uv_at = NULL;
	pattern.canvas = *canvas;
	return (pattern);
}
