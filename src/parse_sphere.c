/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sphere.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamza <hhamza@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 10:45:57 by hhamza            #+#    #+#             */
/*   Updated: 2022/11/08 02:46:25 by hhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static void	split_and_check(char ***split, char const *line)
{
	*split = ft_split(line, ' ');
	if (*split == NULL)
		(perror("parse_sphere"), exit(EXIT_FAILURE));
	if (args_len(*split) != 5 && args_len(*split) != 6)
		(ft_fprintf(2, "Error\nInvalid sphere data\n"), exit(1));
	if (ft_strcmp((*split)[0], "sp") != 0)
		(ft_fprintf(2, "Error\nInvalid sphere line\n"), exit(1));
}

static void	parse_radius(char **split, t_shape *sphere)
{
	float	radius;

	radius = parse_float(split[2]) / 2.0f;
	if (radius <= EPSILON)
		(ft_fprintf(2, "Error\nInvalid sphere radius\n"), exit(1));
	add_transformation(sphere, scaling(radius, radius, radius));
}

t_shape	parse_sphere(char const *line)
{
	t_shape	sphere;
	char	**split;
	t_tuple	center;
	t_color	primary;

	split_and_check(&split, (char *)line);
	sphere = shape();
	center = parse_tuple(split[1]);
	add_transformation(&sphere, rotation_y(M_PI));
	add_transformation(&sphere, translation(center.x, center.y, center.z));
	parse_radius(split, &sphere);
	primary = parse_color(split[3], 1);
	sphere.material.color = primary;
	sphere.normal_at = normal_at_sphere;
	sphere.intersect = intersect_sphere;
	parse_phong(split[4], &sphere);
	if (args_len(split) == 6)
		parse_pattern(split[5], &sphere, primary, uv_at_sphere);
	return (free_args(split), sphere);
}
