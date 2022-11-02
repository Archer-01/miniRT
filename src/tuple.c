/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaizab <oaizab@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 17:00:34 by hhamza            #+#    #+#             */
/*   Updated: 2022/11/02 20:24:19 by oaizab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tuple.h"

t_tuple	point(float x, float y, float z)
{
	t_tuple	p;

	p.x = x;
	p.y = y;
	p.z = z;
	p.w = 1.0;
	return (p);
}

t_tuple	vector(float x, float y, float z)
{
	t_tuple	v;

	v.x = x;
	v.y = y;
	v.z = z;
	v.w = 0.0;
	return (v);
}

t_tuple	tuple_add(t_tuple a, t_tuple b)
{
	t_tuple	c;

	c.x = a.x + b.x;
	c.y = a.y + b.y;
	c.z = a.z + b.z;
	c.w = a.w + b.w;
	return (c);
}

t_tuple	tuple_sub(t_tuple a, t_tuple b)
{
	t_tuple	c;

	c.x = a.x - b.x;
	c.y = a.y - b.y;
	c.z = a.z - b.z;
	c.w = a.w - b.w;
	return (c);
}

t_tuple	tuple_neg(t_tuple a)
{
	t_tuple	b;

	b.x = -a.x;
	b.y = -a.y;
	b.z = -a.z;
	b.w = -a.w;
	return (b);
}
