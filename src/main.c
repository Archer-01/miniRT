/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamza <hhamza@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 12:02:59 by oaizab            #+#    #+#             */
/*   Updated: 2022/11/06 22:08:41 by hhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include "parsing.h"

int main(void)
{
	t_world		w;
	t_camera	cam;
	t_canvas	img;
	mlx_t 		*mlx;
	mlx_image_t	*mlximg;

	parse_scene("scenes/test.rt", &w, &cam);
	img = render(&cam, &w);
	mlx = mlx_init(WIN_WIDTH, WIN_HEIGHT, "miniRT", false);
	mlximg = canvas_export_mlx(mlx, img);
	mlx_image_to_window(mlx, mlximg, 0, 0);
	world_destroy(w);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return 0;
}
