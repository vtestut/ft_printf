/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hexa_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 17:18:59 by vtestut           #+#    #+#             */
/*   Updated: 2022/12/06 18:43:52 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"


size_t	ft_hexalen(unsigned int n)
{
	int	len;

	if (n == 0)
		return (1);
	len = 0;
	while (n >= 16)
	{
		n /= 16;
		len++;
	}
	if (n != 0)
		len++;
	return (len);
}

void	ft_hexa_convertor(unsigned int x, size_t size)
{
	if (size > 0)
	{
		ft_hexa_convertor(x, size - 1);
		write(1, &HEXAMIN[x % 16], 1);
	}
}


/********************************************************************/

int	ft_puthexa(unsigned long nb)
{
	const char	tab[] = "0123456789abcdef";
	int			len;

	len = 0;
	if (nb >= 16)
	{
		len += ft_puthexa(nb / 16);
	}
	ft_putchar(tab[(nb % 16)]);
	len++;
	return (len);
}

// void	ft_hexa_convertor(va_list args, t_struc *struc)
// {
// 	unsigned long	x;

// 	x = va_arg(args, size_t);
// 	if (x == LONG_MAX || x == ULONG_MAX)
// 	{
// 		write(1, "ffffffff", 8);
// 		struc->len += 8;
// 		return ;
// 	}
// 	else if ((long)x == LONG_MIN || x == 0)
// 	{
// 		write(1, "0", 1);
// 		struc->len += 1;
// 		return ;
// 	}
// 	struc->len += ft_puthexa(x);
// }

int	ft_puthexamaj(unsigned long nb)
{
	const char	tab[] = "0123456789ABCDEF";
	int			len;

	len = 0;
	if (nb >= 16)
	{
		len += ft_puthexamaj(nb / 16);
	}
	ft_putchar(tab[(nb % 16)]);
	len++;
	return (len);
}

void	ft_hexamaj_convertor(va_list args, t_struc *struc)
{
	unsigned long	x;

	x = va_arg(args, size_t);
	if (x == LONG_MAX || x == ULONG_MAX)
	{
		write(1, "FFFFFFFF", 8);
		struc->len += 8;
		return ;
	}
	else if ((long)x == LONG_MIN || x == 0)
	{
		write(1, "0", 1);
		struc->len += 1;
		return ;
	}
	struc->len += ft_puthexamaj(x);
}
