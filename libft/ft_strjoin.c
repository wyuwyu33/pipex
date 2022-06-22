/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyu <wyu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 02:22:13 by wyu               #+#    #+#             */
/*   Updated: 2022/01/03 16:14:05 by wyu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_s;
	size_t	s1_len;
	size_t	s2_len;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	new_s = (char *)malloc((s1_len + s2_len + 1) * sizeof(char));
	if (!new_s)
		return (NULL);
	ft_strlcpy(new_s, s1, s1_len + 1);
	ft_strlcpy(new_s + s1_len, s2, s2_len + 1);
	return (new_s);
}
