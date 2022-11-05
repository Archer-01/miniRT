/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ambient.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamza <hhamza@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 17:06:09 by hhamza            #+#    #+#             */
/*   Updated: 2022/11/05 19:14:25 by hhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static float	parse_ratio(char *ratio_str)
{
	float	ratio;

	if (check_float(ratio_str) == false)
	{
		ft_fprintf(STDERR_FILENO, "Parsing error: invalid ambient intensity\n");
		exit(EXIT_FAILURE);
	}
	ratio = ft_atof(ratio_str);
	if (ratio < 0 || ratio > 1)
	{
		ft_fprintf(STDERR_FILENO, "Parsing error: invalid ambient ratio\n");
		exit(EXIT_FAILURE);
	}
	return (ratio);
}

static float	parse_color_component(char *color_str, float ratio)
{
	float	component;

	if (check_int(color_str) == false)
	{
		ft_fprintf(STDERR_FILENO, "Parsing error: invalid ambient color\n");
		exit(EXIT_FAILURE);
	}
	component = ft_atoi(color_str);
	if (component < 0 || component > 255)
	{
		ft_fprintf(STDERR_FILENO, "Parsing error: invalid ambient color\n");
		exit(EXIT_FAILURE);
	}
	return ((component / 255.0f) * ratio);
}

t_color	parse_ambient(char const *line)
{
	t_color	ambient;
	char	**split;
	char	**rgb;
	float	ratio;

	split = ft_split(line, ' ');
	if (split == NULL)
		(perror("parse_ambient"), exit(EXIT_FAILURE));
	if (args_len(split) != 3)
		(ft_fprintf(2, "Parsing error: Invalid ambient data\n"), exit(1));
	if (ft_strcmp(split[0], "A") != 0)
		(ft_fprintf(2, "Parsing error: invalid ambient line\n"), exit(1));
	ratio = parse_ratio(split[1]);
	rgb = ft_split(split[2], ',');
	if (rgb == NULL)
		(perror("parse_ambient"), exit(EXIT_FAILURE));
	if (args_len(rgb) != 3)
		(ft_fprintf(2, "Invalid ambient color\n"), exit(EXIT_FAILURE));
	ambient.red = parse_color_component(rgb[0], ratio);
	ambient.green = parse_color_component(rgb[1], ratio);
	ambient.blue = parse_color_component(rgb[2], ratio);
	return (free_args(rgb), free_args(split), ambient);
}
