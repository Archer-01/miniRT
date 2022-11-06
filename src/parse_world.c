/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_world.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamza <hhamza@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 21:22:19 by hhamza            #+#    #+#             */
/*   Updated: 2022/11/06 21:29:58by hhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

t_world	parse_world(char const *filename)
{
	int		fd;
	char	*line;
	t_world	w;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		(perror("parse_world"), exit(EXIT_FAILURE));
	w = world();
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (line[0] != '\n')
		{
			remove_newline(line);
			if (line[0] == 'L')
				world_add_light(&w, parse_light(line));
			else if (line[0] == 's' && line[1] == 'p')
				world_add_shape(&w, parse_sphere(line));
			else if (line[0] == 'A')
				w.ambient = parse_ambient(line);
			else if (line[0] != 'C')
				(ft_fprintf(2, "Parsing error: invalid object type\n"), exit(1));
		}
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (w);
}
