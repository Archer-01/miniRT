/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_phong.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamza <hhamza@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 11:01:59 by hhamza            #+#    #+#             */
/*   Updated: 2022/11/08 02:48:47 by hhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static t_tuple	local_parse_phong(char const *line)
{
	char	**split;
	t_tuple	phong;

	split = ft_split(line, ',');
	if (split == NULL)
		(perror("parse_phong"), exit(EXIT_FAILURE));
	if (args_len(split) != 3)
	{
		ft_fprintf(STDERR_FILENO, "Error\nInvalid phong data\n");
		exit(EXIT_FAILURE);
	}
	phong.x = parse_int(split[0]);
	if (phong.x < 10 || phong.x > 200)
	{
		ft_fprintf(STDERR_FILENO, "Error\nInvalid shininess\n");
		exit(EXIT_FAILURE);
	}
	phong.y = parse_ratio(split[1]);
	phong.z = parse_ratio(split[2]);
	free_args(split);
	return (phong);
}

void	parse_phong(char *str, t_shape *shape)
{
	t_tuple	phong;

	phong = local_parse_phong(str);
	shape->material.shininess = phong.x;
	shape->material.diffuse = phong.y;
	shape->material.specular = phong.z;
}
