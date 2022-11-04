/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaizab <oaizab@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 10:44:58 by oaizab            #+#    #+#             */
/*   Updated: 2022/11/04 11:11:47 by oaizab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"

t_camera	camera(uint16_t hsize, uint16_t vsize, float fov)
{
	t_camera	cam;
	float		half_view;
	float		aspect;

	cam.hsize = hsize;
	cam.vsize = vsize;
	cam.fov = fov;
	cam.transform = matrix();
	cam.inv_transform = cam.transform;
	cam.inversed = true;
	half_view = tan(fov / 2);
	aspect = (float)hsize / (float)vsize;
	if (aspect >= 1)
	{
		cam.half_width = half_view;
		cam.half_height = half_view / aspect;
	}
	else
	{
		cam.half_width = half_view * aspect;
		cam.half_height = half_view;
	}
	cam.pixel_size = (cam.half_width * 2) / hsize;
	return (cam);
}

t_matrix	cam_get_inverse(t_camera cam)
{
	if (!cam.inversed)
	{
		cam.inv_transform = matrix_inverse(cam.transform);
		cam.inversed = true;
	}
	return (cam.inv_transform);
}

void	cam_set_transform(t_camera *cam, t_matrix transform)
{
	cam->transform = transform;
	cam->inversed = false;
}

/**
 * @note: offsets contain x and y respectively
 */
t_ray	ray_for_pixel(t_camera cam, uint16_t px, uint16_t py)
{
	float		offsets[2];
	t_tuple		world_point;
	t_tuple		pixel;
	t_tuple		origin;
	t_tuple		direction;

	offsets[0] = (px + 0.5) * cam.pixel_size;
	offsets[1] = (py + 0.5) * cam.pixel_size;
	world_point = \
		point(cam.half_width - offsets[0], cam.half_height - offsets[1], -1);
	pixel = matrix_mult_tuple(cam_get_inverse(cam), world_point);
	origin = matrix_mult_tuple(cam_get_inverse(cam), point(0, 0, 0));
	direction = tuple_sub(pixel, origin);
	direction = tuple_normalize(direction);
	return (ray(origin, direction));
}
