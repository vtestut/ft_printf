/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 16:35:20 by virgile           #+#    #+#             */
/*   Updated: 2022/11/24 12:51:48 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	size;
	char	*ptr;

	if (!s1)
		return (NULL);
	size = ft_strlen(s1) + 1;
	ptr = (char *)malloc(size);
	if (!(ptr))
		return (NULL);
	ft_strlcpy(ptr, s1, size);
	return (ptr);
}
