/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyu <wyu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 22:34:42 by wyu               #+#    #+#             */
/*   Updated: 2022/01/03 15:25:26 by wyu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*s2;
	size_t	s1_len;

	s1_len = ft_strlen(s1);
	s2 = ft_calloc(s1_len + 1, 1);
	if (!s2)
		return (NULL);
	ft_strlcpy(s2, s1, s1_len + 1);
	return (s2);
}
