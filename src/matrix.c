/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamza <hhamza@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 18:50:28 by hhamza            #+#    #+#             */
/*   Updated: 2022/11/01 20:44:53by hhamza           ###   ########.fr       */
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

static void	matrix_swap_lines(t_matrix *m, t_matrix *result, uint8_t col)
{
	uint8_t	big;
	uint8_t	row;
	uint8_t	j;

	if (float_eq(m->data[col][col], 0))
	{
		big = col;
		row = -1;
		while (++row < 4)
		{
			if (fabs(m->data[row][col]) > fabs(m->data[big][col]))
				big = row;
		}
		if (big == col)
			(ft_fprintf(2, "Matrix is singular\n"), exit(EXIT_FAILURE));
		else
		{
			j = -1;
			while (++j < 4)
			{
				float_swap(&m->data[col][j], &m->data[big][j]);
				float_swap(&result->data[col][j], &result->data[big][j]);
			}
		}
	}
}

static void	matrix_nullify_non_pivot(t_matrix *m, t_matrix *result, uint8_t col)
{
	uint8_t	row;
	uint8_t	j;
	float	coeff;

	row = 0;
	while (row < 4)
	{
		if (row == col)
			continue ;
		coeff = m->data[row][col] / m->data[col][col];
		if (!float_eq(coeff, 0))
		{
			j = 0;
			while (j < 4)
			{
				m->data[row][j] -= coeff * m->data[col][j];
				result->data[row][j] -= coeff * result->data[col][j];
				++j;
			}
			m->data[row][col] = 0;
		}
		++row;
	}
}

t_matrix	matrix_inverse(t_matrix const *mat)
{
	t_matrix	m;
	t_matrix	result;
	uint8_t		col;
	uint8_t		row;

	m = *mat;
	result = matrix();
	col = -1;
	while (++col < 4)
	{
		matrix_swap_lines(&m, &result, col);
		matrix_nullify_non_pivot(&m, &result, col);
	}
	row = 0;
	while (row < 4)
	{
		col = 0;
		while (col < 4)
		{
			result.data[row][col] /= m.data[row][row];
			++col;
		}
		++row;
	}
	return (result);
}
