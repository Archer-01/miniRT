/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamza <hhamza@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 19:11:45 by hhamza            #+#    #+#             */
/*   Updated: 2022/11/03 20:45:40 by hhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_H
# define LIGHT_H

# include "tuple.h"
# include "color.h"

typedef struct s_light
{
	t_tuple	position;
	t_color	intensity;
}				t_light;

t_light	light(t_tuple position, t_color color, float ratio);

#endif
