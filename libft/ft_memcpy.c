/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyu <wyu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 17:06:10 by wyu               #+#    #+#             */
/*   Updated: 2022/01/03 14:54:58 by wyu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t count)
{
	unsigned char	*dst_uc;
	unsigned char	*src_uc;
	size_t			i;

	dst_uc = (unsigned char *)dst;
	src_uc = (unsigned char *)src;
	if (dst < src)
	{
		i = 0;
		while (i < count)
		{
			dst_uc[i] = src_uc[i];
			i++;
		}
	}
	else if (dst > src)
		while (count--)
			dst_uc[count] = src_uc[count];
	return (dst);
}
