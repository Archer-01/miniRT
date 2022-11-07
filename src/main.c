/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamza <hhamza@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 12:02:59 by oaizab            #+#    #+#             */
/*   Updated: 2022/11/07 23:33:29 by hhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include "parsing.h"

static void	check_args(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_fprintf(STDERR_FILENO, "Usage: %s <scene_file>\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	if (ft_strncmp(argv[1] + ft_strlen(argv[1]) - 3, ".rt", 3) != 0)
	{
		ft_fprintf(STDERR_FILENO, "Error: invalid file extension\n");
		exit(EXIT_FAILURE);
	}
}

static void	hook(void *param)
{
	mlx_t	*mlx;

	mlx = param;
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
	{
		mlx_close_window(mlx);
	}
}

int	main(int argc, char **argv)
{
	t_world		w;
	t_camera	cam;
	t_canvas	img;
	mlx_t		*mlx;
	mlx_image_t	*mlximg;

	check_args(argc, argv);
	parse_scene(argv[1], &w, &cam);
	img = render(&cam, &w);
	world_destroy(w);
	mlx = mlx_init(WIN_WIDTH, WIN_HEIGHT, "miniRT", false);
	mlximg = canvas_export_mlx(mlx, img);
	canvas_destroy(&img);
	mlx_image_to_window(mlx, mlximg, 0, 0);
	mlx_loop_hook(mlx, hook, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (0);
}
