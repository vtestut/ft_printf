/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 12:00:35 by vtestut           #+#    #+#             */
/*   Updated: 2022/12/07 18:11:33 by vtestut          ###   ########.fr       */
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
void	ft_hexa_convertor(va_list args, t_struc *struc);
void	ft_upperhexa_convertor(va_list args, t_struc *struc);
int		ft_put_hexa(unsigned int nb);
int		ft_put_upperhexa(unsigned int nb);
int		ft_put_ptr(unsigned long nb);

#endif