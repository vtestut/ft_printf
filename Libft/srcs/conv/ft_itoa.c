/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:40:34 by vtestut           #+#    #+#             */
/*   Updated: 2022/11/21 16:45:51 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*write_array(char *str, long nb, size_t len)
{
	while (nb > 0)
	{
		str[len--] = nb % 10 + '0';
		nb /= 10;
	}
	if (len == 0 && str[1] == '\0')
		str[0] = '0';
	else if (len == 0 && str[1] != '\0')
		str[0] = '-';
	return (str);
}

char	*ft_itoa(int n)
{
	long	nb;
	size_t	len;
	char	*str;

	nb = n;
	if (n > 0)
		len = 0;
	else
	{
		len = 1;
		nb *= -1;
	}
	while (n)
	{
		n /= 10;
		len++;
	}
	str = malloc((len + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	str[len--] = '\0';
	str = write_array(str, nb, len);
	return (str);
}
