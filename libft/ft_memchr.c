/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyu <wyu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 05:17:51 by wyu               #+#    #+#             */
/*   Updated: 2022/01/03 18:11:34 by wyu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t count)
{
	unsigned char	c_unc;

	c_unc = (unsigned char)c;
	while (count--)
	{
		if (*(unsigned char *)s == c_unc)
			return ((void *)s);
		s++;
	}
	return (NULL);
}
