/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyu <wyu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 18:32:04 by wyu               #+#    #+#             */
/*   Updated: 2022/01/03 16:17:20 by wyu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_str_size(int n, int sign, int base)
{
	int	size;
	int	div;

	size = 0;
	if (sign == -1)
		size++;
	div = (n / base) * sign;
	size++;
	while (div)
	{
		div /= base;
		size++;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	int		sign;
	int		base;
	int		size;
	char	*str;

	sign = 1;
	base = 10;
	if (n < 0)
		sign *= -1;
	size = ft_str_size(n, sign, base);
	str = (char *)malloc((size + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[size--] = '\0';
	str[size--] = (n % base) * sign + '0';
	n = (n / 10) * sign;
	while (n)
	{
		str[size--] = (n % base) + '0';
		n /= 10;
	}
	if (sign == -1)
		str[0] = '-';
	return (str);
}
