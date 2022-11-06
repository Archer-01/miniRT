/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_light.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamza <hhamza@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 10:39:36 by hhamza            #+#    #+#             */
/*   Updated: 2022/11/06 10:44:55 by hhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

t_light	parse_light(char const *line)
{
	char		**split;
	t_light		l;
	t_tuple		position;
	t_color		intensity;
	float		ratio;

	split = ft_split(line, ' ');
	if (split == NULL)
		(perror("parse_light"), exit(EXIT_FAILURE));
	if (args_len(split) != 4)
		(ft_fprintf(2, "Parsing error: invalid light data"), exit(1));
	if (ft_strcmp(split[0], "L") != 0)
		(ft_fprintf(2, "Parsing error: invalid light line"), exit(1));
	position = parse_tuple(split[1]);
	ratio = parse_ratio(split[2]);
	intensity = parse_color(split[3], 1);
	l = light(position, intensity, ratio);
	return (l);
}
