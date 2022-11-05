/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas_import_png.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamza <hhamza@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 13:01:22 by hhamza            #+#    #+#             */
/*   Updated: 2022/11/05 15:43:18 by hhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "canvas.h"

t_canvas	canvas_import_png(char const *filename)
{
	t_canvas		c;
	mlx_texture_t	*texture;
	uint32_t		xy[2];

	texture = mlx_load_png(filename);
	if (texture == NULL)
	{
		c = canvas(1, 1);
		c.data[0][0] = color(1, 1, 1);
		return (c);
	}
	c = canvas(texture->width, texture->height);
	xy[1] = -1;
	while (++xy[1] < c.height)
	{
		xy[0] = -1;
		while (++xy[0] < c.width)
		{
			c.data[xy[1]][xy[0]] = color(\
			texture->pixels[xy[1] * c.width * 4 + (xy[0] * 4)] / 255.0, \
			texture->pixels[xy[1] * c.width * 4 + (xy[0] * 4) + 1] / 255.0, \
			texture->pixels[xy[1] * c.width * 4 + (xy[0] * 4) + 2] / 255.0);
		}
	}
	return (mlx_delete_texture(texture), c);
}
