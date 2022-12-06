/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 15:16:04 by vtestut           #+#    #+#             */
/*   Updated: 2022/11/24 12:05:43 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	calcul(int nb, int fd)
{
	if (nb >= 10)
	{
		calcul((nb / 10), fd);
	}
	ft_putchar_fd(((nb % 10) + '0'), fd);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
	}
	else if (n < 0)
	{
		ft_putchar_fd('-', fd);
		calcul((n * -1), fd);
	}
	else
	{
		calcul(n, fd);
	}
}
