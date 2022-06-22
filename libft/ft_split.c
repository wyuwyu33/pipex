/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyu <wyu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 12:41:37 by wyu               #+#    #+#             */
/*   Updated: 2021/12/30 18:32:45 by wyu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static char	*ft_lstirp(char const *s, char c)
{
	size_t	i;
	char	*s_instable;

	s_instable = (char *)s;
	i = 0;
	while (s_instable[i] && s_instable[i] == c)
		i++;
	return (s_instable + i);
}

static size_t	ft_word_count(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	if (!*s)
		return (0);
	while (s[i])
	{
		while (s[i] && s[i] != c)
			i++;
		while (s[i] && s[i] == c)
			i++;
		count++;
	}
	return (count);
}

static char	*ft_word_dup(char const *s, size_t *i, char c)
{
	size_t	edge;

	edge = 0;
	while (s[edge] && s[edge] != c)
		edge++;
	*i += edge;
	return (ft_substr(s, 0, edge));
}

static char	**ft_word_write(char const *s, char c, char **voca, size_t count)
{
	size_t	i;
	size_t	count_cur;

	i = 0;
	count_cur = 0;
	while (s[i] && count_cur < count)
	{
		voca[count_cur] = ft_word_dup(s + i, &i, c);
		if (!voca[count_cur])
			break ;
		count_cur++;
		while (s[i] && s[i] == c)
			i++;
	}
	return (voca);
}

char	**ft_split(char const *s, char c)
{
	char	**voca;
	char	*s_lstrip;
	size_t	count;

	if (!s)
		return (NULL);
	s_lstrip = ft_lstirp(s, c);
	count = ft_word_count((char const *)s_lstrip, c);
	voca = (char **)ft_calloc(count + 1, sizeof(char *));
	if (!voca)
		return (NULL);
	voca = ft_word_write(s_lstrip, c, voca, count);
	return (voca);
}
