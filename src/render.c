/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaizab <oaizab@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 11:12:06 by oaizab            #+#    #+#             */
/*   Updated: 2022/11/04 11:26:18 by oaizab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"

static void	*pthread_render(void *arg)
{
	t_thread_data	*data;
	uint16_t		x;
	uint16_t		y;
	t_ray			ray;
	t_color			c;

	data = (t_thread_data *)arg;
	y = data->id * (data->cam.vsize / THREAD_COUNT);
	while (y < (data->id + 1) * (data->cam.vsize / THREAD_COUNT))
	{
		x = 0;
		while (x < data->cam.hsize)
		{
			ray = ray_for_pixel(data->cam, x, y);
			c = color_at(data->w, ray);
			data->image->data[x][y] = c;
			x++;
		}
		y++;
	}
	return (NULL);
}

t_canvas	render(t_camera cam, t_world w)
{
	t_canvas		image;
	pthread_t		threads[THREAD_COUNT];
	t_thread_data	data[THREAD_COUNT];
	uint8_t			i;

	image = canvas(cam.hsize, cam.vsize);
	i = 0;
	while (i < THREAD_COUNT)
	{
		data[i].cam = cam;
		data[i].w = w;
		data[i].image = &image;
		data[i].id = i;
		pthread_create(&threads[i], NULL, pthread_render, &data[i]);
		++i;
	}
	return (image);
}
