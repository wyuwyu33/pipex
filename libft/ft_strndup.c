/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyu <wyu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 14:21:49 by wyu               #+#    #+#             */
/*   Updated: 2022/06/24 17:20:08 by wyu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s, int n)
{
	int		i;
	int		len;
	char	*new_s;

	if (n <= 0)
		return (NULL);
	len = ft_strlen(s);
	if (len < n)
		n = len;
	new_s = (char *)malloc(sizeof(n + 1) * sizeof(char));
	if (!new_s)
		return (NULL);
	i = -1;
	while (++i < n)
		new_s[i] = s[i];
	new_s[n] = '\0';
	return (new_s);
}
