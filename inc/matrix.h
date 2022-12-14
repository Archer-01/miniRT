/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaizab <oaizab@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 18:44:26 by hhamza            #+#    #+#             */
/*   Updated: 2022/11/06 19:55:02 by oaizab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_H
# define MATRIX_H

# include "utils.h"
# include "tuple.h"

typedef struct s_matrix
{
	float	data[4][4];
}				t_matrix;

t_matrix	matrix(void);

t_matrix	matrix_mult(t_matrix *m1, t_matrix *m2);
t_tuple		matrix_mult_tuple(t_matrix *m, t_tuple t);
t_matrix	matrix_transpose(t_matrix *m);
t_matrix	matrix_inverse(t_matrix mat);

t_matrix	translation(float x, float y, float z);
t_matrix	scaling(float x, float y, float z);
t_matrix	rotation_x(float angle);
t_matrix	rotation_y(float angle);
t_matrix	rotation_z(float angle);

t_matrix	orientation(t_tuple orient);

#endif
