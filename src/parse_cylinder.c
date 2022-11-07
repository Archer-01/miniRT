/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cylinder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaizab <oaizab@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 16:40:51 by oaizab            #+#    #+#             */
/*   Updated: 2022/11/07 17:32:03 by oaizab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static void	split_and_check(char ***split, char const *line)
{
	*split = ft_split(line, ' ');
	if (*split == NULL)
		(perror("parse_cylinder"), exit(EXIT_FAILURE));
	if (args_len(*split) != 7 && args_len(*split) != 8)
		(ft_fprintf(2, "Parsing error: invalid cylinder data\n"), exit(1));
	if (ft_strcmp((*split)[0], "cy") != 0)
		(ft_fprintf(2, "Parsing error: invalid cylinder line\n"), exit(1));
}

static void	parse_radius(char **split, t_shape *cyl)
{
	float	radius;

	radius = parse_float(split[3]) / 2.0f;
	if (radius <= EPSILON)
		(ft_fprintf(2, "Parsing error: invalid cylinder radius\n"), exit(1));
	add_transformation(cyl, scaling(radius, 1, radius));
}

static void	parse_height(char **split, t_shape *cyl)
{
	float	height;

	height = parse_float(split[4]);
	if (height <= EPSILON)
		(ft_fprintf(2, "Parsing error: invalid cylinder radius\n"), exit(1));
	add_transformation(cyl, scaling(1, height, 1));
}

t_shape	parse_cylinder(char const *line)
{
	t_shape	cyl;
	char	**split;
	t_tuple	center;
	t_tuple orient;
	t_color	primary;

	split_and_check(&split, (char *)line);
	cyl = shape();
	center = parse_tuple(split[1]);
	orient = parse_tuple(split[2]);
	orient.w = 0;
	parse_radius(split, &cyl);
	parse_height(split, &cyl);
	primary = parse_color(split[5], 1);
	cyl.material.color = primary;
	cyl.normal_at = normal_at_cylinder;
	cyl.intersect = intersect_cylinder;
	parse_phong(split[6], &cyl);
	if (tuple_magnitude(orient) != 1)
		ft_fprintf(2, "Warning: invalid orientation, normalizing...\n");
	add_transformation(&cyl, orientation(orient));
	add_transformation(&cyl, rotation_y(M_PI));
	add_transformation(&cyl, translation(center.x, center.y, center.z));
	if (args_len(split) == 8)
	{
		if (ft_strncmp(split[7], "ch:", 3) == 0)
			parse_pattern(split[7], &cyl, primary, uv_at_cylinder_ch);
		else if (ft_strncmp(split[7], "tx:", 3) == 0)
			parse_pattern(split[7], &cyl, primary, uv_at_cylinder_tx);
	}
	return (free_args(split), cyl);
}
