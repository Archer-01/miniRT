/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamza <hhamza@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 16:50:42 by hhamza            #+#    #+#             */
/*   Updated: 2022/11/01 17:08:43 by hhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TUPLE_H
# define TUPLE_H

# include "utils.h"

typedef struct s_tuple
{
	float	x;
	float	y;
	float	z;
	float	w;
}				t_tuple;

// * Constructors
t_tuple	point(float x, float y, float z);
t_tuple	vector(float x, float y, float z);

// * Operations
t_tuple	tuple_add(t_tuple a, t_tuple b);
t_tuple	tuple_sub(t_tuple a, t_tuple b);
t_tuple	tuple_neg(t_tuple a);
t_tuple	tuple_mult(t_tuple a, float b);
t_tuple	tuple_dot(t_tuple a, t_tuple b);
t_tuple	tuple_cross(t_tuple a, t_tuple b);
float	tuple_magnitude(t_tuple a);
t_tuple	tuple_normalize(t_tuple a);

#endif