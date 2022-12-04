/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 11:57:16 by vtestut           #+#    #+#             */
/*   Updated: 2022/12/04 16:21:37 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int ft_intlen(int n)
{
	int len;
	int sign;

	if (!n)
		return (0);
	sign = 0;
	if (n < 0)
		sign = 1;
	len = 0;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len + sign);
}

static size_t ft_longlen(size_t n)
{
	int len;

	if (!n)
		return (0);
	len = 0;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static void	ft_putlong(size_t nb)
{
	if (nb >= 10)
	{
		ft_putlong(nb / 10);
	}
	ft_putchar((nb % 10) + '0');
}

static size_t ft_puthexamaj(size_t nb)
{
    char tab[] = "0123456789ABCDEF";
    size_t len = 0;

    if (nb >= 16)
    {
        len += ft_puthexamaj(nb / 16);
    }
    ft_putchar(tab[(nb % 16)]);
    len++;
    return (len);
}

static void ft_hexamaj_convertor(va_list args, t_struc *struc)
{
    size_t x;

    x = va_arg(args, size_t);
    struc->len += ft_puthexamaj(x);
}

static size_t ft_puthexa(size_t nb)
{
    char tab[] = "0123456789abcdef";
    size_t len = 0;

    if (nb >= 16)
    {
        len += ft_puthexa(nb / 16);
    }
    ft_putchar(tab[(nb % 16)]);
    len++;
    return (len);
}

static void ft_hexa_convertor(va_list args, t_struc *struc)
{
    size_t x;

    x = va_arg(args, size_t);
    struc->len += ft_puthexa(x);
}

static void ft_int_convertor(va_list args, t_struc *struc)
{
	int d;

	d = va_arg(args, int);
	ft_putnbr(d);
	struc->len += ft_intlen(d);
}

static void ft_str_convertor(va_list args, t_struc *struc)
{
	char *s;

	s = va_arg(args, char *); // protect against NULL ptr
	ft_putstr(s);
	struc->len += (int)ft_strlen(s);
}

static void ft_char_convertor(va_list args, t_struc *struc)
{
	char c;

	c = va_arg(args, int);
	ft_putchar(c);
	struc->len += 1;
}

static void ft_unsigned_convertor(va_list args, t_struc *struc)
{
	size_t u;

	u = va_arg(args, size_t);
	ft_putlong(u);
	struc->len += (int)ft_longlen(u);
}

static void ft_ptr_convertor(va_list args, t_struc *struc)
{
	unsigned long p;

	p = va_arg(args, unsigned long);
	write(1, "0x", 2);
    struc->len += ft_puthexa(p) + 2;
}

static const char *read_and_write_text(t_struc *struc, const char *str)
{
	char 	*ptr;
	
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

static const char *search_convertor(va_list args, const char *str, t_struc *struc)
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
		ft_hexamaj_convertor(args, struc);	
	else if (*str == '%')
	{
		write(1, "%", 1);
		struc->len += 1;
	}
	// else
	// {
	// 	write(1, "%", 1);
	// 	write(1, &(*str), 1);
	// }
	else
	{	printf("FT_SEARCH_CONV / STR == %s", str);
		//check_other(str);
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
	if (str ==  NULL) 
	{
		write(1, "(null)", 6);
		va_end(args);
		return (struc.len);
	}
	while (*str) 
	{
		if (*str == '%') 
		{
			str = search_convertor(args, str + 1, &struc);
		}
		else
			str = read_and_write_text(&struc, str);
	}
	va_end(args);
	return (struc.len);
}

int	main(void)
{
	char tab[] = "lol";
	char *ptr = tab;

	int test1 = printf("LEPRINTF = print %k   %p\n", ptr);
	int test2 = ft_printf("MYPRINTF = print %k   %p\n", ptr);
	printf("\nLEPRINTF = %d\nMYPRINTF = %d\n", test1, test2);
	return (0);
}
