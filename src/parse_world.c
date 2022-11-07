/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_world.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamza <hhamza@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 11:34:32 by hhamza            #+#    #+#             */
/*   Updated: 2022/11/07 11:54:17 by hhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	parse_world(char const *filename, t_world *w)
{
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		(perror("parse_world"), exit(EXIT_FAILURE));
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (line[0] != '\n' && line[0] != '#')
		{
			remove_newline(line);
			if (line[0] == 'L')
				world_add_light(w, parse_light(line));
			else if (line[0] == 's' && line[1] == 'p')
				world_add_shape(w, parse_sphere(line));
			else if (line[0] == 'A')
				w->ambient = parse_ambient(line);
			else if (line[0] == 'p' && line[1] == 'l')
				world_add_shape(w, parse_plane(line));
			else if (line[0] != 'C')
				(ft_fprintf(2, "Parsing error: invalid object\n"), exit(1));
		}
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}
