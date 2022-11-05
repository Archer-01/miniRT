/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaizab <oaizab@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 16:57:45 by hhamza            #+#    #+#             */
/*   Updated: 2022/11/05 09:55:42 by oaizab           ###   ########.fr       */
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
# define THREAD_COUNT 4
# define WIN_WIDTH 1920
# define WIN_HEIGHT 1080

bool		float_eq(float a, float b);
void		float_swap(float *a, float *b);

float		deg_to_rad(float deg);

uint32_t	get_rgba(uint8_t r, uint8_t g, uint8_t b, uint8_t a);

#endif