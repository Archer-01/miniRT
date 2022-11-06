/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamza <hhamza@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 21:08:15 by hhamza            #+#    #+#             */
/*   Updated: 2022/11/06 21:13:00 by hhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

t_pattern	parse_texture(char const *line)
{
	t_pattern	tx;
	t_canvas	c;

	c = canvas_import_png(line);
	tx = texture(&c);
	return (tx);
}
