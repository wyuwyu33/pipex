/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyu <wyu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 02:40:36 by wyu               #+#    #+#             */
/*   Updated: 2022/01/03 18:12:10 by wyu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char			*p_s;
	unsigned char	c_unc;

	p_s = (char *)s + ft_strlen(s);
	c_unc = (unsigned char)c;
	while (s <= p_s)
	{
		if (*p_s == c_unc)
			return (p_s);
		p_s--;
	}
	return ((char *) NULL);
}
