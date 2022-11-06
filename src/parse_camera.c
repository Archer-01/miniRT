/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamza <hhamza@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 19:01:11 by hhamza            #+#    #+#             */
/*   Updated: 2022/11/06 09:30:14 by hhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static float	parse_fov(char *fov_str)
{
	float	fov;

	if (check_float(fov_str) == false)
	{
		ft_fprintf(STDERR_FILENO, "Parsing error: invalid fov\n");
		exit(EXIT_FAILURE);
	}
	fov = ft_atof(fov_str);
	if (fov < 0 || fov > 180)
	{
		ft_fprintf(2, "Parsing error: fov must be between 0 and 180\n");
		exit(EXIT_FAILURE);
	}
	return (fov);
}

t_camera	parse_camera(char const *line)
{
	char		**split;
	t_camera	cam;
	t_tuple		from;
	t_tuple		orientation;
	t_matrix	vt;

	split = ft_split(line, ' ');
	if (split == NULL)
		(perror("parse_camera"), exit(EXIT_FAILURE));
	if (args_len(split) != 4)
		(ft_fprintf(2, "Parsing error: invalid camera data"), exit(1));
	if (ft_strcmp(split[0], "C") != 0)
		(ft_fprintf(2, "Parsing error: invalid camera line"), exit(1));
	from = parse_tuple(split[1]);
	from.w = 1.0f;
	orientation = parse_tuple(split[2]);
	cam = camera(WIN_WIDTH, WIN_HEIGHT, parse_fov(split[3]));
	vt = view_transform(from, tuple_add(from, orientation), vector(0, 1, 0));
	cam_set_transform(&cam, &vt);
	return (cam);
}
