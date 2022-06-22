/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyu <wyu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 22:34:45 by wyu               #+#    #+#             */
/*   Updated: 2022/01/03 14:05:58 by wyu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*alloc_addr;

	alloc_addr = malloc(count * size);
	if (!alloc_addr)
		return ((void *) NULL);
	ft_bzero(alloc_addr, count * size);
	return (alloc_addr);
}
