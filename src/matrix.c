/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaizab <oaizab@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 21:15:27 by hhamza            #+#    #+#             */
/*   Updated: 2022/11/02 20:06:58 by oaizab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

t_matrix	matrix(void)
{
	t_matrix	matrix;

	matrix.data[0][0] = 1;
	matrix.data[0][1] = 0;
	matrix.data[0][2] = 0;
	matrix.data[0][3] = 0;
	matrix.data[1][0] = 0;
	matrix.data[1][1] = 1;
	matrix.data[1][2] = 0;
	matrix.data[1][3] = 0;
	matrix.data[2][0] = 0;
	matrix.data[2][1] = 0;
	matrix.data[2][2] = 1;
	matrix.data[2][3] = 0;
	matrix.data[3][0] = 0;
	matrix.data[3][1] = 0;
	matrix.data[3][2] = 0;
	matrix.data[3][3] = 1;
	return (matrix);
}

t_matrix	matrix_mult(t_matrix m1, t_matrix m2)
{
	t_matrix	result;
	uint8_t		i;
	uint8_t		j;
	uint8_t		k;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			result.data[i][j] = 0;
			k = 0;
			while (k < 4)
			{
				result.data[i][j] += m1.data[i][k] * m2.data[k][j];
				k++;
			}
			j++;
		}
		i++;
	}
	return (result);
}

t_tuple	matrix_mult_tuple(t_matrix m, t_tuple t)
{
	t_tuple	res;

	res.x = m.data[0][0] * t.x \
		+ m.data[0][1] * t.y \
		+ m.data[0][2] * t.z \
		+ m.data[0][3] * t.w;
	res.y = m.data[1][0] * t.x \
		+ m.data[1][1] * t.y \
		+ m.data[1][2] * t.z \
		+ m.data[1][3] * t.w;
	res.z = m.data[2][0] * t.x \
		+ m.data[2][1] * t.y \
		+ m.data[2][2] * t.z \
		+ m.data[2][3] * t.w;
	res.w = m.data[3][0] * t.x \
		+ m.data[3][1] * t.y \
		+ m.data[3][2] * t.z \
		+ m.data[3][3] * t.w;
	return (res);
}

t_matrix	matrix_transpose(t_matrix m)
{
	t_matrix	result;
	uint8_t		i;
	uint8_t		j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			result.data[i][j] = m.data[j][i];
			++j;
		}
		++i;
	}
	return (result);
}
