/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 17:38:30 by virgile           #+#    #+#             */
/*   Updated: 2022/11/14 18:55:38 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*temp;
	char	t;

	temp = NULL;
	t = (char) c;
	while (*s != '\0')
	{
		if (*s == t)
			temp = (char *)s;
		s++;
	}
	if (t == '\0')
		temp = (char *)s;
	return (temp);
}
