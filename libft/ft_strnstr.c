/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyu <wyu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 03:20:49 by wyu               #+#    #+#             */
/*   Updated: 2022/01/02 03:16:14 by wyu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t count)
{
	size_t	hs_len;
	size_t	need_len;
	size_t	i;

	if (!*needle)
		return ((char *) haystack);
	hs_len = ft_strlen(haystack);
	need_len = ft_strlen(needle);
	if (hs_len < need_len || count < need_len)
		return ((char *) NULL);
	i = 0;
	while (i < count - need_len + 1)
	{
		if (!ft_strncmp(haystack + i, needle, need_len))
			return ((char *)(haystack + i));
		i++;
	}
	return ((char *) NULL);
}
