/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamza <hhamza@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 18:44:26 by hhamza            #+#    #+#             */
/*   Updated: 2022/11/01 21:12:22 by hhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_H
# define MATRIX_H

# include "utils.h"

typedef struct s_matrix
{
	float	data[4][4];
}				t_matrix;

t_matrix	matrix(void);

t_matrix	matrix_mult(t_matrix const *m1, t_matrix const *m2);
t_matrix	matrix_transpose(t_matrix const *m);
t_matrix	matrix_inverse(t_matrix const *mat);

#endif
