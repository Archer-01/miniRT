/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaizab <oaizab@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 17:10:43 by hhamza            #+#    #+#             */
/*   Updated: 2022/11/05 09:22:38 by oaizab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

typedef struct s_color
{
	float	red;
	float	green;
	float	blue;
}				t_color;

t_color	color(float red, float green, float blue);
t_color	color_add(t_color c1, t_color c2);
t_color	color_mult(t_color *c, float f);
t_color	color_mult_color(t_color *c1, t_color *c2);

#endif