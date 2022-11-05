/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamza <hhamza@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 17:45:35 by hhamza            #+#    #+#             */
/*   Updated: 2022/11/05 12:20:13 by hhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "canvas.h"

t_canvas	canvas(uint16_t width, uint16_t height)
{
	t_canvas	canvas;
	uint16_t	i;

	canvas.width = width;
	canvas.height = height;
	canvas.data = malloc(sizeof(t_color *) * height);
	if (canvas.data == NULL)
	{
		perror("canvas");
		exit(EXIT_FAILURE);
	}
	i = 0;
	while (i < height)
	{
		canvas.data[i] = malloc(sizeof(t_color) * width);
		if (canvas.data[i] == NULL)
		{
			perror("canvas");
			exit(EXIT_FAILURE);
		}
		++i;
	}
	return (canvas);
}

void	canvas_destroy(t_canvas *canvas)
{
	uint16_t	i;

	i = 0;
	while (i < canvas->height)
	{
		free(canvas->data[i]);
		++i;
	}
	free(canvas->data);
	canvas->width = 0;
	canvas->height = 0;
	canvas->data = NULL;
}

/**
 * @brief Convert color component from [0-1] to [0-255]
 */
static uint8_t	c255(float color_component)
{
	if (color_component <= 0)
	{
		return (0);
	}
	if (color_component >= 1)
	{
		return (255);
	}
	else
	{
		return (color_component * 255);
	}
}

void	canvas_export_ppm(t_canvas canvas, char const *filename)
{
	int			fd;
	uint16_t	i;
	uint16_t	j;

	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0600);
	if (fd == -1)
	{
		perror("canvas_export_ppm");
		return ;
	}
	ft_fprintf(fd, "P3\n%d %d\n255\n", canvas.width, canvas.height);
	i = -1;
	while (++i < canvas.height)
	{
		j = -1;
		while (++j < canvas.width)
		{
			dprintf(fd, "%d %d %d ", \
				c255(canvas.data[i][j].red), \
				c255(canvas.data[i][j].green), \
				c255(canvas.data[i][j].blue));
		}
		dprintf(fd, "\n");
	}
	close(fd);
}

mlx_image_t	*canvas_export_mlx(mlx_t *mlx, t_canvas canvas)
{
	mlx_image_t	*img;
	uint16_t	i;
	uint16_t	j;

	img = mlx_new_image(mlx, canvas.width, canvas.height);
	if (img == NULL)
	{
		perror("canvas_export_mlx");
		exit(EXIT_FAILURE);
	}
	i = 0;
	while (i < canvas.height)
	{
		j = 0;
		while (j < canvas.width)
		{
			mlx_put_pixel(img, j, i, get_rgba(\
				c255(canvas.data[i][j].red), \
				c255(canvas.data[i][j].green), \
				c255(canvas.data[i][j].blue), \
				255));
			++j;
		}
		++i;
	}
	return (img);
}
