/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaizab <oaizab@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 17:15:41 by hhamza            #+#    #+#             */
/*   Updated: 2022/11/05 09:52:26 by oaizab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CANVAS_H
# define CANVAS_H

# include "utils.h"
# include "color.h"

typedef struct s_canvas
{
	uint16_t	width;
	uint16_t	height;
	t_color		**data;
}				t_canvas;

t_canvas	canvas(uint16_t width, uint16_t height);
void		canvas_destroy(t_canvas *canvas);

void		canvas_export_ppm(t_canvas canvas, char const *filename);
// TODO: Add import PPM
mlx_image_t	*canvas_export_mlx(mlx_t *mlx, t_canvas canvas);

#endif