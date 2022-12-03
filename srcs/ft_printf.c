/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 11:57:16 by vtestut           #+#    #+#             */
/*   Updated: 2022/12/03 16:49:55 by vtestut          ###   ########.fr       */
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

// int ft_putstrhex(char *str)
// {
// 	int len = 0;
// 	while (*str)
// 	{
// 		ft_putchar(*str);
// 		str++;
// 		len++;
// 	}
// 	return (len);
// }

static void ft_puthexa(size_t nb)
{
	char tab[] = "0123456789abcdef";

	if (nb >= 16)
	{
		ft_puthexa(nb / 16);
	}
	ft_putchar(tab[(nb % 16)]);
}

static void ft_hexa_convertor(va_list args, t_struc *struc)
{
	size_t x;

	x = va_arg(args, size_t);
	ft_puthexa(x);
	struc->len += x;
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

	s = va_arg(args, char *);
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

static const char *read_and_write_text(t_struc *struc, const char *str)
{
	char 	*next;
	
	next = ft_strchr(str, '%');
	if (next != NULL)
		struc->size = next - str;
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
	if (*str == 's')
		ft_str_convertor(args, struc);
	// if (*str == 'p')
	if (*str == 'd' || *str == 'i')
		ft_int_convertor(args, struc);
	if (*str == 'u')
		ft_unsigned_convertor(args, struc);
	if (*str == 'x')
		ft_hexa_convertor(args, struc);
	// if (*str == 'X')
	// 	ft_hexamaj_convertor(args, struc);	
	if (*str == '%')
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

	/**********************************************************************/
	int test1 = printf("LEPRINTF = print %x\n", 3123354456);
	int test2 = ft_printf("MYPRINTF = print %x\n", 3123354456);
	printf("\nLEPRINTF = %d\nMYPRINTF = %d\n", test1, test2);
	/**********************************************************************/
	//int i;
	// printf("Nombre d'arguments passes au programme : %d\n", argc);
	// for (i = 0; i < argc; i++)
	// {
	// 	printf(" argv[%d] --->  %s\n", i, argv[i]);
	// 	//ft_printf(" argv[%d] --->  %s\n", i, argv[i]);
	// }
	return (0);
}
