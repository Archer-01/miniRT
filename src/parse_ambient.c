/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ambient.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamza <hhamza@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 17:06:09 by hhamza            #+#    #+#             */
/*   Updated: 2022/11/06 09:11:53 by hhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

t_color	parse_ambient(char const *line)
{
	t_color	ambient;
	char	**split;
	float	ratio;

	split = ft_split(line, ' ');
	if (split == NULL)
		(perror("parse_ambient"), exit(EXIT_FAILURE));
	if (args_len(split) != 3)
		(ft_fprintf(2, "Parsing error: Invalid ambient data\n"), exit(1));
	if (ft_strcmp(split[0], "A") != 0)
		(ft_fprintf(2, "Parsing error: invalid ambient line\n"), exit(1));
	ratio = parse_ratio(split[1]);
	ambient = parse_color(split[2], ratio);
	return (free_args(split), ambient);
}
