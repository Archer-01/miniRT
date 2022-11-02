/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaizab <oaizab@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 17:52:18 by hhamza            #+#    #+#             */
/*   Updated: 2022/11/02 20:06:04 by oaizab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERSECTIONS_H
# define INTERSECTIONS_H

# include "utils.h"
# include "intersection.h"

typedef struct s_intersection	t_intersection;

typedef struct s_intersections
{
	t_intersection	*xs;
	uint32_t		count;
	uint32_t		capacity;
}				t_intersections;

t_intersections	intersections(void);
t_intersection	*hit(t_intersections *intersections);
void			intersections_add(t_intersections *intersections, \
	t_intersection i);

#endif