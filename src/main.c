/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamza <hhamza@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 12:02:59 by oaizab            #+#    #+#             */
/*   Updated: 2022/11/07 23:24:47 by hhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include "parsing.h"

int	main(void)
{
	t_world		w;
	t_camera	cam;
	t_canvas	img;
	mlx_t		*mlx;
	mlx_image_t	*mlximg;

	parse_scene("scenes/spheres.rt", &w, &cam);
	img = render(&cam, &w);
	world_destroy(w);
	mlx = mlx_init(WIN_WIDTH, WIN_HEIGHT, "miniRT", false);
	mlximg = canvas_export_mlx(mlx, img);
	canvas_destroy(&img);
	mlx_image_to_window(mlx, mlximg, 0, 0);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (0);
}
