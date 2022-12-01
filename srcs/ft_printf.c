/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 11:57:16 by vtestut           #+#    #+#             */
/*   Updated: 2022/12/01 16:59:43 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

// parcourrir et print les char de ma string jusqu'a tomber sur " % "
// si % -> identifier le convertor qui suit
// emvoyer l'argument vers le bon converteur et le print

// typedef struct s_list
// {
// 		int len;				// valeur de retour
// 		int size;				// variable temporaire
// }				t_list;

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
	// if (*str == 'u')
	// if (*str == 'x' || *str == 'X')
	// if (*str == '%')
	return (str + 1);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	t_struc	struc; // structure pour stocker les tailles et les valeurs de retour

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
			str = search_convertor(args, str + 1, &struc); // on envoie le carac d'apres le %
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
	// int test1 = printf("\nLEPRINTF = Salut | %d | ca va?\n", -123);
	// int test2 = ft_printf("\nMYPRINTF = Salut | %d | ca va?\n", -123);
	// printf("\nLEPRINTF = %d\nMYPRINTF = %d\n", test1, test2);
	/**********************************************************************/
	int test1 = printf("LEPRINTF = Salut %s tu as %d ans %c\n", "Virgile", 30, '!');
	int test2 = ft_printf("MYPRINTF = Salut %s tu as %d ans %c\n", "Virgile", 30, '!');
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
