/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 11:57:16 by vtestut           #+#    #+#             */
/*   Updated: 2022/12/07 17:57:35 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static const char	*read_and_write_text(t_struc *struc, const char *str)
{
	char	*ptr;

	ptr = ft_strchr(str, '%');
	if (ptr != NULL)
		struc->size = ptr - str;
	else
		struc->size = (int)ft_strlen(str);
	write(1, str, struc->size);
	struc->len += struc->size;
	while (*str && *str != '%')
		str++;
	return (str);
}

static const char	*search_conv(va_list args, const char *str, t_struc *struc)
{
	if (*str == 'c')
		ft_char_convertor(args, struc);
	else if (*str == 's')
		ft_str_convertor(args, struc);
	else if (*str == 'p')
		ft_ptr_convertor(args, struc);
	else if (*str == 'd' || *str == 'i')
		ft_int_convertor(args, struc);
	else if (*str == 'u')
		ft_unsigned_convertor(args, struc);
	else if (*str == 'x')
		ft_hexa_convertor(args, struc);
	else if (*str == 'X')
		ft_upperhexa_convertor(args, struc);
	else if (*str == '%')
	{
		write(1, "%", 1);
		struc->len += 1;
	}
	return (str + 1);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	t_struc	struc;

	va_start(args, str);
	struc.len = 0;
	struc.size = 0;
	if (str == NULL)
	{
		write(1, "(null)", 6);
		va_end(args);
		return (struc.len);
	}
	while (*str)
	{
		if (*str == '%')
			str = search_conv(args, str + 1, &struc);
		else
			str = read_and_write_text(&struc, str);
	}
	va_end(args);
	return (struc.len);
}
