/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_pattern.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamza <hhamza@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 11:33:05 by hhamza            #+#    #+#             */
/*   Updated: 2022/11/08 02:44:58 by hhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	parse_pattern(char const *str, t_shape *shape, t_color primary, \
	t_uv_at_fun uv_at_f)
{
	shape->material.has_pattern = true;
	if (ft_strncmp(str, "ch:", 3) == 0)
		shape->material.pattern = parse_checker(&str[3], primary);
	else if (ft_strncmp(str, "tx:", 3) == 0)
		shape->material.pattern = parse_texture(&str[3]);
	else
		(ft_fprintf(2, "Error\nInvalid pattern\n"), exit(1));
	shape->material.pattern.uv_at = uv_at_f;
}
