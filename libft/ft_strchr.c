/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyu <wyu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 02:14:58 by wyu               #+#    #+#             */
/*   Updated: 2022/01/03 18:11:53 by wyu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t			i;
	size_t			s_len;
	unsigned char	c_unc;

	i = 0;
	s_len = ft_strlen(s);
	c_unc = (unsigned char)c;
	while (i <= s_len)
	{
		if (s[i] == c_unc)
			return ((char *)(s + i));
		i++;
	}
	return ((char *) NULL);
}
