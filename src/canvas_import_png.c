/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas_import_png.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamza <hhamza@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 13:01:22 by hhamza            #+#    #+#             */
/*   Updated: 2022/11/06 21:12:01 by hhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "canvas.h"

t_canvas	canvas_import_png(char const *filename)
{
	t_canvas		c;
	mlx_texture_t	*tx;
	uint32_t		xy[2];

	tx = mlx_load_png(filename);
	if (tx == NULL)
	{
		c = canvas(1, 1);
		c.data[0][0] = color(1, 1, 1);
		return (c);
	}
	c = canvas(tx->width, tx->height);
	xy[1] = -1;
	while (++xy[1] < c.height)
	{
		xy[0] = -1;
		while (++xy[0] < c.width)
		{
			c.data[xy[1]][xy[0]] = color(\
			tx->pixels[xy[1] * c.width * 4 + (xy[0] * 4)] / 255.0, \
			tx->pixels[xy[1] * c.width * 4 + (xy[0] * 4) + 1] / 255.0, \
			tx->pixels[xy[1] * c.width * 4 + (xy[0] * 4) + 2] / 255.0);
		}
	}
	return (mlx_delete_texture(tx), c);
}
