/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamza <hhamza@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 17:17:45 by hhamza            #+#    #+#             */
/*   Updated: 2022/11/05 18:56:18 by hhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

bool	check_int(char const *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0' && ft_isdigit(str[i]))
		i++;
	if (str[i] != '\0')
		return (false);
	return (true);
}

size_t	args_len(char **args)
{
	size_t	i;

	i = 0;
	while (args[i] != NULL)
		i++;
	return (i);
}

void	free_args(char **args)
{
	size_t	i;

	i = 0;
	while (args[i] != NULL)
	{
		free(args[i]);
		i++;
	}
	free(args);
}

void	remove_newline(char *str)
{
	char	*newline;

	newline = ft_strrchr(str, '\n');
	if (newline != NULL)
	{
		*newline = '\0';
	}
}
