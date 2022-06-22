/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyu <wyu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 15:31:49 by wyu               #+#    #+#             */
/*   Updated: 2021/12/28 00:31:21 by wyu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_chcmp(unsigned char c1, unsigned char c2)
{
	return ((int)(c1 - c2));
}

int	ft_strncmp(const char *s1, const char *s2, size_t count)
{
	unsigned char	*s1_unc;
	unsigned char	*s2_unc;
	size_t			i;

	s1_unc = (unsigned char *)s1;
	s2_unc = (unsigned char *)s2;
	i = 0;
	while (i < count && s1_unc[i])
	{
		if (ft_chcmp(s1_unc[i], s2_unc[i]))
			return ((int)(s1_unc[i] - s2_unc[i]));
		i++;
	}
	if (i != count)
		return ((int)(s1_unc[i] - s2_unc[i]));
	return (0);
}
