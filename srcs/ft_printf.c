/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 11:57:16 by vtestut           #+#    #+#             */
/*   Updated: 2022/11/29 19:37:04 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #include "../includes/ft_printf.h"
 

// int ft_printf(const char *str, ...)
// {
// 	va_list	ap;
// 	size_t	i;
// 	va_start(ap, str);
// 	return (0);
// }

int main ( int argc , char *argv[] ) 
{

/******************************************************************/
int i;
printf("Nombre d’arguments passes au programme : %d\n", argc);
for(i = 0 ; i < argc ; i++) 
	printf(" argv[%d] --->  %s\n", i, argv[i]);
/*******************************************************************/

char tab[] = "gateau";
ft_putstr(tab);

return (0);
}