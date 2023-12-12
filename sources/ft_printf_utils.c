/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 17:05:31 by vtestut           #+#    #+#             */
/*   Updated: 2023/12/12 19:00:38 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_int_convertor(va_list args, t_struc *struc)
{
	int	d;

	d = va_arg(args, int);
	ft_putnbr(d);
	if (d == 0)
	{
		struc->len += 1;
		return ;
	}
	struc->len += ft_intlen(d);
}

void	ft_str_convertor(va_list args, t_struc *struc)
{
	char	*s;

	s = va_arg(args, char *);
	if (s == NULL)
	{	
		write(1, "(null)", 6);
		struc->len += 6;
		return ;
	}
	else
	{
		ft_putstr(s);
		struc->len += (int)ft_strlen(s);
	}
}

void	ft_char_convertor(va_list args, t_struc *struc)
{
	char	c;

	c = va_arg(args, int);
	ft_putchar(c);
	struc->len += 1;
}

void	ft_unsigned_convertor(va_list args, t_struc *struc)
{
	unsigned int	u;

	u = va_arg(args, unsigned int);
	if (u == 0)
	{
		write(1, "0", 1);
		struc->len += 1;
		return ;
	}
	ft_putlong(u);
	struc->len += (int)ft_longlen(u);
}

void	ft_ptr_convertor(va_list args, t_struc *struc)
{
	unsigned long	*p;

	p = va_arg(args, unsigned long *);
	if (p == NULL)
	{
		write(1, "(nil)", 5);
		struc->len += 5;
		return ;
	}
	else if (p != NULL)
		write(1, "0x", 2);
	struc->len += ft_put_ptr((unsigned long)p) + 2;
}
 