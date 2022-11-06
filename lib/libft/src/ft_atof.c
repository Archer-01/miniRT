/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamza <hhamza@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 11:30:23 by hhamza            #+#    #+#             */
/*   Updated: 2022/11/06 19:11:45 by hhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned long	ft_ten_power(unsigned long exp)
{
	unsigned long	i;
	unsigned long	result;

	i = 0;
	result = 1;
	while (i < exp)
	{
		result *= 10;
		++i;
	}
	return (result);
}

static unsigned long	ft_abs(long num)
{
	if (num < 0)
	{
		return (-num);
	}
	else
	{
		return (num);
	}
}

double	ft_atof(char const *str)
{
	char			*dot;
	long			int_part;
	unsigned long	frac_part;
	short			sign;
	double			result;

	sign = 1;
	if (str[0] == '-')
		sign = -1;
	dot = ft_strchr(str, '.');
	if (dot == NULL)
	{
		return (ft_atoi(str));
	}
	*dot = '\0';
	int_part = ft_atoi(str);
	frac_part = ft_atoi(dot + 1);
	result = ft_abs(int_part);
	result += (double) frac_part / ft_ten_power(ft_strlen(dot + 1));
	return (sign * result);
}
