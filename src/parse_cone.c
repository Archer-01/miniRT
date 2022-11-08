/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cone.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamza <hhamza@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 19:42:34 by oaizab            #+#    #+#             */
/*   Updated: 2022/11/08 02:43:33 by hhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static void	split_and_check(char ***split, char const *line)
{
	*split = ft_split(line, ' ');
	if (*split == NULL)
		(perror("parse_cylinder"), exit(EXIT_FAILURE));
	if (args_len(*split) != 7 && args_len(*split) != 8)
		(ft_fprintf(2, "Error\nInvalid cone data\n"), exit(1));
	if (ft_strcmp((*split)[0], "cn") != 0 && ft_strcmp((*split)[0], "cnh") != 0)
		(ft_fprintf(2, "Error\nInvalid cone line\n"), exit(1));
}

static void	parse_radius(char **split, t_shape *cyl)
{
	float	radius;

	radius = parse_float(split[3]) / 2.0f;
	if (radius <= EPSILON)
		(ft_fprintf(2, "Error\nInvalid cone radius\n"), exit(1));
	add_transformation(cyl, scaling(radius, 1, radius));
}

static void	parse_height(char **split, t_shape *cn)
{
	float	height;

	height = parse_float(split[4]);
	if (height <= EPSILON)
		(ft_fprintf(2, "Error\nInvalid cone radius\n"), exit(1));
	cn->max = 1;
	cn->min = 0;
	if (ft_strcmp(split[0], "cn") == 0)
	{
		cn->min = -1;
		height = height / 2;
	}
	add_transformation(cn, scaling(1, height, 1));
}

static void	add_pattern(char **split, t_shape *cone, t_color primary)
{
	if (args_len(split) == 8)
	{
		if (ft_strncmp(split[7], "ch:", 3) == 0)
			parse_pattern(split[7], cone, primary, uv_at_cylinder_ch);
		else if (ft_strncmp(split[7], "tx:", 3) == 0)
			parse_pattern(split[7], cone, primary, uv_at_cylinder_tx);
	}
}

t_shape	parse_cone(char const *line)
{
	t_shape	cone;
	char	**split;
	t_tuple	center;
	t_tuple	orient;
	t_color	primary;

	split_and_check(&split, (char *)line);
	cone = shape();
	center = parse_tuple(split[1]);
	orient = parse_tuple(split[2]);
	orient.w = 0;
	parse_radius(split, &cone);
	parse_height(split, &cone);
	primary = parse_color(split[5], 1);
	cone.material.color = primary;
	cone.normal_at = normal_at_cone;
	cone.intersect = intersect_cone;
	parse_phong(split[6], &cone);
	if (tuple_magnitude(orient) != 1)
		ft_fprintf(2, "Warning: invalid orientation, normalizing...\n");
	add_transformation(&cone, orientation(orient));
	add_transformation(&cone, rotation_y(M_PI));
	add_transformation(&cone, translation(center.x, center.y, center.z));
	add_pattern(split, &cone, primary);
	return (free_args(split), cone);
}
