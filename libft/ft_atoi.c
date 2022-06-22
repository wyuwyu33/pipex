/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyu <wyu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 03:57:59 by wyu               #+#    #+#             */
/*   Updated: 2022/01/02 15:57:21 by wyu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(int c)
{
	if (c == ' ' || c == '\t' || \
	c == '\n' || c == '\v' || \
	c == '\f' || c == '\r')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	long long	nbr;
	long long	sign;
	size_t		i;

	i = 0;
	while (str[i] && ft_isspace(str[i]))
		i++;
	sign = 1;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	nbr = 0;
	while (str[i] && ft_isdigit(str[i]))
	{
		nbr = (nbr * 10) + (str[i] - '0');
		if (sign * nbr > INT_MAX)
			return (-1);
		if (sign * nbr < INT_MIN)
			return (0);
		i++;
	}
	return ((int)(sign * nbr));
}
