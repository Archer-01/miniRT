/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaizab <oaizab@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 16:59:16 by hhamza            #+#    #+#             */
/*   Updated: 2022/11/02 20:08:15 by oaizab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

# include "tuple.h"
# include "matrix.h"

typedef struct s_ray
{
	t_tuple	origin;
	t_tuple	direction;
}				t_ray;

t_ray	ray(t_tuple orig, t_tuple dir);
t_tuple	ray_position(t_ray ray, float t);
t_ray	ray_transform(t_ray ray, t_matrix m);

#endif