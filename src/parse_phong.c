/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_phong.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamza <hhamza@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 11:01:59 by hhamza            #+#    #+#             */
/*   Updated: 2022/11/06 11:29:49 by hhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

t_tuple	parse_phong(char const *line)
{
	char	**split;
	t_tuple	phong;

	split = ft_split(line, ',');
	if (split == NULL)
		(perror("parse_phong"), exit(EXIT_FAILURE));
	if (args_len(split) != 3)
	{
		ft_fprintf(STDERR_FILENO, "Parsing error: invalid phong data\n");
		exit(EXIT_FAILURE);
	}
	phong.x = parse_int(split[0]);
	if (phong.x < 10 || phong.x > 200)
	{
		ft_fprintf(STDERR_FILENO, "Parsing error: invalid shininess\n");
		exit(EXIT_FAILURE);
	}
	phong.y = parse_ratio(split[1]);
	phong.z = parse_ratio(split[2]);
	free(split);
	return (phong);
}
