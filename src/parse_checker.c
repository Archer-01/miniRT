/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamza <hhamza@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 11:20:04 by hhamza            #+#    #+#             */
/*   Updated: 2022/11/08 02:42:55 by hhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

t_pattern	parse_checker(char const *checker_str, t_color primary)
{
	char		**split;
	t_pattern	c;
	uint16_t	w;
	uint16_t	h;
	t_color		secondary;

	split = ft_split(checker_str, ',');
	if (split == NULL)
		(perror("parse_checker"), exit(EXIT_FAILURE));
	if (args_len(split) != 5)
	{
		ft_fprintf(STDERR_FILENO, "Error\ninvalid checker data\n");
		exit(EXIT_FAILURE);
	}
	w = parse_int(split[0]);
	h = parse_int(split[1]);
	if (w < 1 || h < 1)
		(ft_fprintf(2, "Error\ninvalid checker size\n"), exit(1));
	secondary.red = parse_color_component(split[2], 1);
	secondary.green = parse_color_component(split[3], 1);
	secondary.blue = parse_color_component(split[4], 1);
	c = checker(w, h, &primary, &secondary);
	free_args(split);
	return (c);
}
