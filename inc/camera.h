/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaizab <oaizab@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 10:38:41 by oaizab            #+#    #+#             */
/*   Updated: 2022/11/05 09:05:12 by oaizab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

# include "matrix.h"
# include "ray.h"
# include "canvas.h"
# include "world.h"

typedef struct s_camera
{
	uint16_t	hsize;
	uint16_t	vsize;
	float		fov;
	t_matrix	transform;
	t_matrix	inv_transform;
	bool		inversed;
	float		pixel_size;
	float		half_width;
	float		half_height;
}				t_camera;

typedef struct s_thread_data
{
	t_camera	*cam;
	t_world		*w;
	t_canvas	*image;
	uint8_t		id;
}				t_thread_data;

t_camera	camera(uint16_t hsize, uint16_t vsize, float fov);
t_matrix	cam_get_inverse(t_camera *cam);
void		cam_set_transform(t_camera *cam, t_matrix *transform);

t_ray		ray_for_pixel(t_camera *cam, uint16_t px, uint16_t py);
t_canvas	render(t_camera *cam, t_world *world);
t_matrix	view_transform(t_tuple from, t_tuple to, t_tuple up);

#endif