/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   orientation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaizab <oaizab@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 19:55:24 by oaizab            #+#    #+#             */
/*   Updated: 2022/11/06 20:06:36 by oaizab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

static t_matrix	matrix_from_vec(t_tuple x, t_tuple y, t_tuple z)
{
	t_matrix	m;

	m.data[0][0] = x.x;
	m.data[0][1] = x.y;
	m.data[0][2] = x.z;
	m.data[0][3] = 0;
	m.data[1][0] = y.x;
	m.data[1][1] = y.y;
	m.data[1][2] = y.z;
	m.data[1][3] = 0;
	m.data[2][0] = z.x;
	m.data[2][1] = z.y;
	m.data[2][2] = z.z;
	m.data[2][3] = 0;
	m.data[3][0] = 0;
	m.data[3][1] = 0;
	m.data[3][2] = 0;
	m.data[3][3] = 1;
	return (m);
}

t_matrix	orientation(t_tuple direction)
{
	t_tuple		up;
	t_tuple		right;
	t_tuple		forward;

	if (up.x == 0 && up.z == 0)
	{
		if (up.y < 0)
		{
			up = vector(0, -1, 0);
			right = vector(-1, 0, 0);
		}
		else
		{
			up = vector(0, 1, 0);
			right = vector(1, 0, 0);
		}
		forward = vector(0, 0, 1);
	}
	else
	{
		up = tuple_normalize(direction);
		right = tuple_cross(up, vector(0, 1, 0));
		forward = tuple_cross(right, up);
	}
	return (matrix_from_vec(right, up, forward));
}
