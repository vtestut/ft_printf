/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 12:00:35 by vtestut           #+#    #+#             */
/*   Updated: 2022/12/06 19:13:09 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../Libft/includes/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <limits.h>

# define HEXAMIN "0123456798abcdef"

typedef struct s_struc
{
	int	len;
	int	size;
}				t_struc;

int		ft_printf(const char *str, ...);
void	ft_int_convertor(va_list args, t_struc *struc);
void	ft_str_convertor(va_list args, t_struc *struc);
void	ft_char_convertor(va_list args, t_struc *struc);
void	ft_unsigned_convertor(va_list args, t_struc *struc);
void	ft_ptr_convertor(va_list args, t_struc *struc);
void	ft_hexa_convertor(unsigned int x, size_t size);
void	ft_hexamaj_convertor(va_list args, t_struc *struc);
int		ft_puthexa(unsigned long nb);
int		ft_puthexamaj(unsigned long nb);
size_t	ft_hexalen(unsigned int n);


#endif