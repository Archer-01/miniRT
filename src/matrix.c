/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamza <hhamza@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 21:15:27 by hhamza            #+#    #+#             */
/*   Updated: 2022/11/01 21:17:44 by hhamza           ###   ########.fr       */
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

t_matrix	matrix_mult(t_matrix const *m1, t_matrix const *m2)
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
				result.data[i][j] += m1->data[i][k] * m2->data[k][j];
				k++;
			}
			j++;
		}
		i++;
	}
	return (result);
}

t_matrix	matrix_transpose(t_matrix const *m)
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
			result.data[i][j] = m->data[j][i];
			++j;
		}
		++i;
	}
	return (result);
}
