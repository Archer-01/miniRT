/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uv_at.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaizab <oaizab@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 20:33:41 by hhamza            #+#    #+#             */
/*   Updated: 2022/11/07 17:28:52 by oaizab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pattern.h"

t_uv	uv_at_sphere(t_tuple point)
{
	t_uv	uv;
	float	theta;
	float	phi;
	float	radius;

	theta = atan2(point.x, point.z);
	radius = sqrt(point.x * point.x + point.y * point.y + point.z * point.z);
	phi = acos(point.y / radius);
	uv.u = -(theta / (2 * M_PI)) + 0.5f;
	uv.v = 1 - phi / M_PI;
	return (uv);
}

t_uv	uv_at_plane_tx(t_tuple point)
{
	t_uv	uv;

	uv.u = fabs(point.x) - (int)(fabs(point.x));
	uv.v = fabs(point.z) - (int)(fabs(point.z));
	return (uv);
}

t_uv	uv_at_plane_ch(t_tuple point)
{
	t_uv	uv;

	uv.u = point.x - (int)(point.x);
	uv.v = point.z - (int)(point.z);
	return (uv);
}

t_uv	uv_at_cylinder_tx(t_tuple point)
{
	t_uv	uv;
	float	theta;

	theta = atan2(point.x, point.z);
	uv.u = -(theta / (2 * M_PI)) + 0.5f;
	uv.v = fabs(point.y) - (int)(fabs(point.y));
	return (uv);
}

t_uv	uv_at_cylinder_ch(t_tuple point)
{
	t_uv	uv;
	float	theta;

	theta = atan2(point.x, point.z);
	uv.u = -(theta / (2 * M_PI)) + 0.5f;
	uv.v = point.y - (int)(point.y);
	return (uv);
}
