/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamza <hhamza@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 17:15:41 by hhamza            #+#    #+#             */
/*   Updated: 2022/11/03 21:36:42 by hhamza           ###   ########.fr       */
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
// TODO: Add export MLX

#endif