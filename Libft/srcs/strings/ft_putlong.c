/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlong.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 17:33:26 by vtestut           #+#    #+#             */
/*   Updated: 2022/12/05 19:32:23 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putlong(unsigned long nb)
{
	if (nb >= 10)
	{
		ft_putlong(nb / 10);
	}
	ft_putchar((nb % 10) + '0');
}