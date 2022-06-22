/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyu <wyu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 01:20:14 by wyu               #+#    #+#             */
/*   Updated: 2021/12/23 11:24:47 by wyu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dest, int c, size_t count)
{
	unsigned char	*dest_uc;
	size_t			i;

	dest_uc = (unsigned char *)dest;
	i = 0;
	while (i < count)
	{
		*(dest_uc + i) = (unsigned char)c;
		i++;
	}
	return (dest);
}
