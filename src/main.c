/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaizab <oaizab@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 12:02:59 by oaizab            #+#    #+#             */
/*   Updated: 2022/11/04 14:51:22 by oaizab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int main(void)
{
	t_world		w;
	t_shape		sphere;
	t_shape		fl;
	t_shape		wall;
	t_camera	cam;
	t_light		l;
	t_light		l2;
	t_canvas	img;

	w = world();
	w.ambient = color(0.1, 0.1, 0.1);

	sphere = shape();
	add_transformation(&sphere, translation(0, 2, 0));
	add_transformation(&sphere, scaling(0.5, 0.5, 0.5));
	sphere.intersect = &intersect_sphere;
	sphere.normal_at = &normal_at_sphere;
	// sphere.material.pattern.width = 10;
	// sphere.material.pattern.height = 10;
	// sphere.material.pattern.uv_at = uv_at_sphere;
	// sphere.material.pattern.color_at = color_at_checker;
	// sphere.material.pattern.primary = color(1, 0, 0);
	// sphere.material.pattern.secondary = color(0, 1, 0);
	// sphere.material.has_pattern = true;
	sphere.material.color = color(1, 0.9, 0);

	fl = shape();
	fl.material.specular = 0;
	fl.intersect = &intersect_plane;
	fl.normal_at = &normal_at_plane;
	// add_transformation(&fl, rotation_x(M_PI / 2));
	// add_transformation(&fl, translation(0, 0, 5));

	wall = shape();
	wall.material.specular = 0;
	wall.material.pattern.width = 2;
	wall.material.pattern.height = 2;
	wall.material.pattern.uv_at = uv_at_plane;
	wall.material.pattern.color_at = color_at_checker;
	wall.material.pattern.primary = color(1, 0, 0);
	wall.material.pattern.secondary = color(0, 1, 0);
	wall.material.has_pattern = true;
	wall.material.color = color(1, 0.9, 0);
	wall.intersect = &intersect_plane;
	wall.normal_at = &normal_at_plane;
	add_transformation(&wall, rotation_x(M_PI / 2));
	add_transformation(&wall, rotation_y(M_PI / 4));
	add_transformation(&wall, translation(0, 0, 5));
	
	l = light(point(-10, 10, -10), color(1, 1, 1), 0.7);
	l2 = light(point(5, 2, -10), color(1, 1, 1), 0.3);

	world_add_shape(&w, sphere);
	world_add_shape(&w, fl);
	world_add_shape(&w, wall);
	world_add_light(&w, l);
	world_add_light(&w, l2);

	cam = camera(1000, 500, M_PI / 3);
	cam_set_transform(&cam, view_transform(point(0, 1, -5), point(0, 1, 0), vector(0, 1, 0)));
	img = render(cam, w);
	canvas_export_ppm(img, "scene.ppm");
	
	return 0;
}
