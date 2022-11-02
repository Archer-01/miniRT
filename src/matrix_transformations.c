/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_transformations.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamza <hhamza@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 16:49:36 by hhamza            #+#    #+#             */
/*   Updated: 2022/11/02 16:55:02 by hhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

t_matrix	translation(float x, float y, float z)
{
	t_matrix	translation;

	translation = matrix();
	translation.data[0][3] = x;
	translation.data[1][3] = y;
	translation.data[2][3] = z;
	return (translation);
}

t_matrix	scaling(float x, float y, float z)
{
	t_matrix	scaling;

	scaling = matrix();
	scaling.data[0][0] = x;
	scaling.data[1][1] = y;
	scaling.data[2][2] = z;
	return (scaling);
}

t_matrix	rotation_x(float angle)
{
	t_matrix	rotation;
	float		_cos;
	float		_sin;

	_cos = cos(angle);
	_sin = sin(angle);
	rotation = matrix();
	rotation.data[1][1] = _cos;
	rotation.data[1][2] = -_sin;
	rotation.data[2][1] = _sin;
	rotation.data[2][2] = _cos;
	return (rotation);
}

t_matrix	rotation_y(float angle)
{
	t_matrix	rotation;
	float		_cos;
	float		_sin;

	_cos = cos(angle);
	_sin = sin(angle);
	rotation = matrix();
	rotation.data[0][0] = _cos;
	rotation.data[0][2] = _sin;
	rotation.data[2][0] = -_sin;
	rotation.data[2][2] = _cos;
	return (rotation);
}

t_matrix	rotation_z(float angle)
{
	t_matrix	rotation;
	float		_cos;
	float		_sin;

	_cos = cos(angle);
	_sin = sin(angle);
	rotation = matrix();
	rotation.data[0][0] = _cos;
	rotation.data[0][1] = -_sin;
	rotation.data[1][0] = _sin;
	rotation.data[1][1] = _cos;
	return (rotation);
}
