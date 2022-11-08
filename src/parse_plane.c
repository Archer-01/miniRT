/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_plane.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaizab <oaizab@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 11:41:26 by hhamza            #+#    #+#             */
/*   Updated: 2022/11/08 20:24:15 by oaizab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static void	add_pattern(char **split, t_shape *pl, t_color primary)
{
	pl->intersect = intersect_plane;
	pl->normal_at = normal_at_plane;
	pl->material.color = primary;
	if (args_len(split) == 6)
	{
		if (ft_strncmp(split[5], "ch:", 3) == 0)
			parse_pattern(split[5], pl, primary, uv_at_plane_ch);
		else if (ft_strncmp(split[5], "tx:", 3) == 0)
			parse_pattern(split[5], pl, primary, uv_at_plane_tx);
	}
}

t_shape	parse_plane(char const *line)
{
	t_shape	pl;
	char	**split;
	t_tuple	origin;
	t_tuple	orient;
	t_color	primary;

	pl = shape();
	split = ft_split(line, ' ');
	if (split == NULL)
		(perror("parse_plane"), exit(EXIT_FAILURE));
	if (args_len(split) != 5 && args_len(split) != 6)
		(ft_fprintf(2, "Error\nInvalid plane data\n"), exit(1));
	if (ft_strcmp(split[0], "pl") != 0)
		(ft_fprintf(2, "Error\nInvalid plane line\n"), exit(1));
	origin = parse_tuple(split[1]);
	orient = parse_tuple(split[2]);
	orient.w = 0;
	primary = parse_color(split[3], 1);
	parse_phong(split[4], &pl);
	add_transformation(&pl, orientation(orient));
	add_transformation(&pl, translation(origin.x, origin.y, origin.z));
	add_pattern(split, &pl, primary);
	return (free_args(split), pl);
}
