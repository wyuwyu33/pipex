/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyu <wyu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 03:12:27 by wyu               #+#    #+#             */
/*   Updated: 2022/01/02 03:45:39 by wyu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t count)
{
	unsigned char	*s1_unc;
	unsigned char	*s2_unc;
	size_t			i;

	s1_unc = (unsigned char *)s1;
	s2_unc = (unsigned char *)s2;
	i = 0;
	while (i < count)
	{
		if (s1_unc[i] != s2_unc[i])
			return ((int)(s1_unc[i] - s2_unc[i]));
		i++;
	}
	return (0);
}
