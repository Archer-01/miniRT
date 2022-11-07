/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamza <hhamza@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 21:33:20 by hhamza            #+#    #+#             */
/*   Updated: 2022/11/07 11:37:59 by hhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	parse_scene(char const *filename, t_world *w, t_camera *cam)
{
	int		fd;
	char	*line;

	*w = world();
	parse_world(filename, w);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		perror("parse_scene");
		exit(EXIT_FAILURE);
	}
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (line[0] != '\n' && line[0] != '#')
		{
			remove_newline(line);
			if (line[0] == 'C')
				*cam = parse_camera(line);
		}
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}
