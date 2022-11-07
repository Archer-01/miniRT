/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaizab <oaizab@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 21:33:20 by hhamza            #+#    #+#             */
/*   Updated: 2022/11/07 22:25:44 by oaizab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static void	error_camera(int status)
{
	static bool	error = false;

	if (status == 1)
	{
		if (!error)
		{
			error = true;
		}
		else
		{
			ft_fprintf(2, "Parsing error: multiple camera\n");
			exit(1);
		}
	}
	else
	{
		if (!error)
		{
			ft_fprintf(2, "Parsing error: no camera\n");
			exit(1);
		}
	}
}

void	parse_scene(char const *filename, t_world *w, t_camera *cam)
{
	int		fd;
	char	*line;

	*w = world();
	parse_world(filename, w);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		(perror("parse_scene"), exit(EXIT_FAILURE));
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (line[0] != '\n' && line[0] != '#')
		{
			remove_newline(line);
			if (line[0] == 'C')
			{
				error_camera(1);
				*cam = parse_camera(line);
			}
		}
		free(line);
		line = get_next_line(fd);
	}
	error_camera(0);
	close(fd);
}
