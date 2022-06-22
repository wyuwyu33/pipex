/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyu <wyu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 02:22:16 by wyu               #+#    #+#             */
/*   Updated: 2022/01/03 17:23:08 by wyu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub_s;

	if (!s)
		return (NULL);
	else if (ft_strlen(s) <= start)
		return (ft_strdup(""));
	if (ft_strlen(s + start) < len)
		len = ft_strlen(s + start);
	sub_s = (char *)malloc((len + 1) * sizeof(char));
	if (!sub_s)
		return (NULL);
	ft_strlcpy(sub_s, s + start, len + 1);
	return (sub_s);
}
