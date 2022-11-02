/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamza <hhamza@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 17:22:48 by hhamza            #+#    #+#             */
/*   Updated: 2022/07/31 07:42:26 by hhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Puts string followed by a newline to file pointed by file descriptor
 *
 * @param s: string to put
 * @param fd: file descriptor
 * @return int: Number of characters written to fd
 */
int	ft_putendl_fd(char *s, int fd)
{
	if (!s)
		return (0);
	return (ft_putstr_fd(s, fd) + ft_putchar_fd('\n', fd));
}
