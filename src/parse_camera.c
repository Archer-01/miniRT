/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaizab <oaizab@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 19:01:11 by hhamza            #+#    #+#             */
/*   Updated: 2022/11/08 20:23:37 by oaizab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static float	parse_fov(char *fov_str)
{
	float	fov;

	if (check_float(fov_str) == false)
	{
		ft_fprintf(STDERR_FILENO, "Error\ninvalid fov\n");
		exit(EXIT_FAILURE);
	}
	fov = ft_atof(fov_str);
	if (fov < 0 || fov > 180)
	{
		ft_fprintf(2, "Error\nFov must be between 0 and 180\n");
		exit(EXIT_FAILURE);
	}
	return (deg_to_rad(fov));
}

static void	check_camera(char **split)
{
	if (split == NULL)
		(perror("parse_camera"), exit(EXIT_FAILURE));
	if (args_len(split) != 4)
		(ft_fprintf(2, "Error\nInvalid camera data"), exit(1));
	if (ft_strcmp(split[0], "C") != 0)
		(ft_fprintf(2, "Error\nInvalid camera line"), exit(1));
}

/**
 * @note: vec is 'orientation' and 'up' vectors
 */
t_camera	parse_camera(char const *line)
{
	char		**split;
	t_camera	cam;
	t_tuple		from;
	t_tuple		vec[2];
	t_matrix	vt;

	split = ft_split(line, ' ');
	check_camera(split);
	from = parse_tuple(split[1]);
	vec[0] = parse_tuple(split[2]);
	vec[0].w = 0.0f;
	if (tuple_magnitude(vec[0]) != 1.0f)
		vec[0] = tuple_normalize(vec[0]);
	cam = camera(WIN_WIDTH, WIN_HEIGHT, parse_fov(split[3]));
	vec[1] = vector(0, 1, 0);
	if (float_eq(vec[0].x, 0) && float_eq(vec[0].z, 0))
		vec[1] = vector(0, 0, 1);
	vt = view_transform(from, tuple_add(from, vec[0]), vec[1]);
	return (free_args(split), cam_set_transform(&cam, &vt), cam);
}
