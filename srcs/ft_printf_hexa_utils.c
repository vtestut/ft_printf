/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hexa_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 17:18:59 by vtestut           #+#    #+#             */
/*   Updated: 2023/12/12 19:00:44 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
 
int	ft_put_hexa(unsigned int nb)
{
	const char	tab[] = "0123456789abcdef";
	int			len;

	len = 0;
	if (nb >= 16)
	{
		len += ft_put_hexa(nb / 16);
	}
	ft_putchar(tab[(nb % 16)]);
	len++;
	return (len);
}

void	ft_hexa_convertor(va_list args, t_struc *struc)
{
	unsigned int	x;

	x = va_arg(args, unsigned int);
	if (x == 0)
	{
		write(1, "0", 1);
		struc->len += 1;
		return ;
	}
	struc->len += ft_put_hexa(x);
}

int	ft_put_upperhexa(unsigned int nb)
{
	const char	tab[] = "0123456789ABCDEF";
	int			len;

	len = 0;
	if (nb >= 16)
	{
		len += ft_put_upperhexa(nb / 16);
	}
	ft_putchar(tab[(nb % 16)]);
	len++;
	return (len);
}

void	ft_upperhexa_convertor(va_list args, t_struc *struc)
{
	unsigned int	x;

	x = va_arg(args, unsigned int);
	if (x == 0)
	{
		write(1, "0", 1);
		struc->len += 1;
		return ;
	}
	struc->len += ft_put_upperhexa(x);
}

int	ft_put_ptr(unsigned long nb)
{
	const char	tab[] = "0123456789abcdef";
	int			len;

	len = 0;
	if (nb >= 16)
	{
		len += ft_put_ptr(nb / 16);
	}
	ft_putchar(tab[(nb % 16)]);
	len++;
	return (len);
}
