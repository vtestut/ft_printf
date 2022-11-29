/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 11:57:16 by vtestut           #+#    #+#             */
/*   Updated: 2022/11/29 21:59:22 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #include "../includes/ft_printf.h"

int ft_printf(const char *str, ...)
{
	va_list	args;
	t_list	struc;

	if(str == NULL)
		return (0);
	va_start(args, str);
	struc.len = 0;
	struc.size = 0;
	while(*str)
	{
		if (*str == '%')
		{
			str = search_convertor(args, str+1 , &struc)
		}
		else
	}

	// parcourrir et print les char de ma string jusqu'a tomber sur " % "
	// si % -> identifier le convertor qui suit
	// emvoyer l'argument vers le bon converteur et le print

	check_format(args, str);

	return (0);
}

// typedef struct s_list
// {
// 		int len;
// 		int size;
// }	t_list;

int main ( int argc , char *argv[] ) 
{

/*******************************************************************/
int i;

printf("Nombre d'arguments passes au programme : %d\n", argc);

for(i = 0 ; i < argc ; i++) 
{
	printf(" argv[%d] --->  %s\n", i, argv[i]);
	//ft_printf(" argv[%d] --->  %s\n", i, argv[i]);
}
/*******************************************************************/
return (0);
}