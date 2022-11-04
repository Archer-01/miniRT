/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple_reflect.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaizab <oaizab@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 09:44:07 by oaizab            #+#    #+#             */
/*   Updated: 2022/11/04 09:44:32 by oaizab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tuple.h"

t_tuple	tuple_reflect(t_tuple in, t_tuple normal)
{
	return (tuple_sub(in, tuple_mult(normal, 2 * tuple_dot(in, normal))));
}
