/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamza <hhamza@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 17:13:57 by hhamza            #+#    #+#             */
/*   Updated: 2022/11/03 21:09:34 by hhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"

t_color	color(float red, float green, float blue)
{
	t_color	c;

	c.red = red;
	c.green = green;
	c.blue = blue;
	return (c);
}

t_color	color_add(t_color c1, t_color c2)
{
	t_color	c;

	c.red = c1.red + c2.red;
	c.green = c1.green + c2.green;
	c.blue = c1.blue + c2.blue;
	return (c);
}

t_color	color_mult(t_color c, float f)
{
	t_color	res;

	res.red = c.red * f;
	res.green = c.green * f;
	res.blue = c.blue * f;
	return (res);
}

t_color	color_mult_color(t_color c1, t_color c2)
{
	t_color	res;

	res.red = c1.red * c2.red;
	res.green = c1.green * c2.green;
	res.blue = c1.blue * c2.blue;
	return (res);
}
