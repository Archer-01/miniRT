/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamza <hhamza@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 17:03:41 by hhamza            #+#    #+#             */
/*   Updated: 2022/11/06 21:33:57 by hhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "main.h"

void		parse_scene(char const *filename, t_world *w, t_camera *cam);
t_world		parse_world(char const *filename);

float		parse_ratio(char *ratio_str);
float		parse_color_component(char *color_str, float ratio);
t_color		parse_color(char *color_str, float ratio);
int			parse_int(char const *int_str);
float		parse_float(char const *str);
t_tuple		parse_tuple(char const *line);
t_color		parse_ambient(char const *line);
t_camera	parse_camera(char const *line);
t_light		parse_light(char const *line);
t_shape		parse_sphere(char const *line);
t_tuple		parse_phong(char const *line);
t_pattern	parse_checker(char const *line, t_color primary);
t_pattern	parse_texture(char const *line);

#endif