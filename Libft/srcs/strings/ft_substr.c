/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 15:15:24 by virgile           #+#    #+#             */
/*   Updated: 2022/11/24 12:41:04 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	mloc_size(unsigned int start, size_t len, size_t s_len)
{
	if (start > s_len)
		return (0);
	if ((s_len - (size_t)start) >= len)
		return (len);
	return ((s_len - (size_t)start));
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new_str;
	size_t	i;
	size_t	j;
	size_t	k;

	k = ft_strlen(s);
	new_str = (char *)malloc(mloc_size(start, len, k) + 1);
	if (!s || !(new_str))
		return (NULL);
	i = start;
	j = 0;
	while (i < k && j < len)
		new_str[j++] = s[i++];
	new_str[j] = '\0';
	return (new_str);
}
