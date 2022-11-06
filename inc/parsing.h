/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamza <hhamza@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 17:03:41 by hhamza            #+#    #+#             */
/*   Updated: 2022/11/06 10:40:17 by hhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "main.h"

t_world		parse_world(char const *filename);

float		parse_ratio(char *ratio_str);
t_color		parse_color(char *color_str, float ratio);
t_tuple		parse_tuple(char const *line);
t_color		parse_ambient(char const *line);
t_camera	parse_camera(char const *line);
t_light		parse_light(char const *line);

#endif