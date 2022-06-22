/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyu <wyu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 02:25:25 by wyu               #+#    #+#             */
/*   Updated: 2022/01/02 06:10:01 by wyu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	front;
	size_t	rear;

	if (!s1 || !set)
		return (NULL);
	front = 0;
	rear = ft_strlen(s1);
	while (s1[front] && ft_strchr(set, s1[front]))
		front++;
	while (front < rear && ft_strchr(set, s1[rear]))
		rear--;
	return (ft_substr(s1, front, rear - front + 1));
}
