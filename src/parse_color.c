/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamza <hhamza@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 09:07:42 by hhamza            #+#    #+#             */
/*   Updated: 2022/11/06 09:22:37 by hhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

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

t_color	parse_color(char *color_str, float ratio)
{
	t_color	res;
	char	**split;

	split = ft_split(color_str, ',');
	if (split == NULL)
	{
		perror("parse_color");
		exit(EXIT_FAILURE);
	}
	if (args_len(split) != 3)
	{
		ft_fprintf(STDERR_FILENO, "Parsing error: invalid ambient color\n");
		exit(EXIT_FAILURE);
	}
	res.red = parse_color_component(split[1], ratio);
	res.green = parse_color_component(split[2], ratio);
	res.blue = parse_color_component(split[3], ratio);
	free_args(split);
	return (res);
}
