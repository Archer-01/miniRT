/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamza <hhamza@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 16:57:45 by hhamza            #+#    #+#             */
/*   Updated: 2022/11/02 16:48:52 by hhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <math.h>
# include <pthread.h>
# include <stdbool.h>
# include "MLX42/MLX42.h"
# include "libft.h"

# define EPSILON 0.00001f

bool	float_eq(float a, float b);
void	float_swap(float *a, float *b);

float	deg_to_rad(float deg);

#endif