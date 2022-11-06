/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamza <hhamza@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 11:04:31 by hhamza            #+#    #+#             */
/*   Updated: 2022/11/06 11:12:31 by hhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	parse_int(char const *int_str)
{
	if (check_int(int_str) == false)
	{
		ft_fprintf(STDERR_FILENO, "Parsing error: invalid integer\n");
		exit(EXIT_FAILURE);
	}
	return (ft_atoi(int_str));
}
