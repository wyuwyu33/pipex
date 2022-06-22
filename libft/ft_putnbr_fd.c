/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyu <wyu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 11:17:47 by wyu               #+#    #+#             */
/*   Updated: 2022/01/03 18:12:23 by wyu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	nbr;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		nbr = 0xffffffff - (unsigned int)n + 1;
	}
	else
		nbr = (unsigned int)n;
	if (nbr > 9)
		ft_putnbr_fd((int)(nbr / 10), fd);
	ft_putchar_fd((char)('0' + (int)(nbr % 10)), fd);
}
