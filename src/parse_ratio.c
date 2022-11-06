/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ratio.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamza <hhamza@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 09:11:40 by hhamza            #+#    #+#             */
/*   Updated: 2022/11/06 09:11:54 by hhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

float	parse_ratio(char *ratio_str)
{
	float	ratio;

	if (check_float(ratio_str) == false)
	{
		ft_fprintf(STDERR_FILENO, "Parsing error: invalid ambient intensity\n");
		exit(EXIT_FAILURE);
	}
	ratio = ft_atof(ratio_str);
	if (ratio < 0 || ratio > 1)
	{
		ft_fprintf(STDERR_FILENO, "Parsing error: invalid ambient ratio\n");
		exit(EXIT_FAILURE);
	}
	return (ratio);
}
