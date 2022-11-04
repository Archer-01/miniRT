/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_inverse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaizab <oaizab@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 21:17:28 by hhamza            #+#    #+#             */
/*   Updated: 2022/11/04 12:37:14 by oaizab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

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

	row = -1;
	while (++row < 4)
	{
		if (row == col)
			continue ;
		coeff = m->data[row][col] / m->data[col][col];
		if (!float_eq(coeff, 0))
		{
			j = -1;
			while (++j < 4)
			{
				m->data[row][j] -= coeff * m->data[col][j];
				result->data[row][j] -= coeff * result->data[col][j];
			}
			m->data[row][col] = 0;
		}
	}
}

t_matrix	matrix_inverse(t_matrix m)
{
	t_matrix	result;
	uint8_t		col;
	uint8_t		row;

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
