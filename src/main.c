/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaizab <oaizab@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 12:02:59 by oaizab            #+#    #+#             */
/*   Updated: 2022/11/05 10:08:41 by oaizab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int main(void)
{
	t_world		w;
	t_shape		sphere;
	t_shape		fl;
	t_shape		wall;
	t_shape		cyl;
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
	sphere.material.color = color(1, 0.9, 1);

	cyl = shape();
	cyl.intersect = &intersect_cylinder;
	cyl.normal_at = &normal_at_cylinder;
	cyl.material.pattern.width = 40;
	cyl.material.pattern.height = 10;
	cyl.material.pattern.uv_at = uv_at_cylinder;
	cyl.material.pattern.color_at = color_at_checker;
	cyl.material.pattern.primary = color(1, 1, 1);
	cyl.material.pattern.secondary = color(0, 0, 0);
	cyl.material.has_pattern = true;

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
	world_add_shape(&w, cyl);
	world_add_light(&w, l);
	world_add_light(&w, l2);

	cam = camera(WIN_WIDTH, WIN_HEIGHT, M_PI / 3);
	t_matrix	vt = view_transform(point(0, 1, -5), point(0, 1, 0), vector(0, 1, 0));
	cam_set_transform(&cam, &vt);
	img = render(&cam, &w);
	// canvas_export_ppm(img, "scene.ppm");

	mlx_t 		*mlx;
	mlx_image_t	*mlximg;

	mlx = mlx_init(WIN_WIDTH, WIN_HEIGHT, "miniRT", false);
	mlximg = canvas_export_mlx(mlx, img);
	mlx_image_to_window(mlx, mlximg, 0, 0);
	mlx_loop(mlx);

	return 0;
}
