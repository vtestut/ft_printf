/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 18:50:56 by vtestut           #+#    #+#             */
/*   Updated: 2022/11/23 13:55:56 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_clear(char **strings)
{
	size_t	i;

	i = 0;
	while (strings[i])
	{
		free(strings[i]);
		i++;
	}
	free(strings);
}

static size_t	skip_sep(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] == c && c != '\0')
		i++;
	return (i);
}

static size_t	ft_count_word(char const *s, char c)
{
	size_t	nb_of_word;

	if (s == NULL)
		return (0);
	nb_of_word = 0;
	s += skip_sep(s, c);
	while (*s != '\0')
	{
		if (*s != c)
		{
			nb_of_word++;
			while (*s != c && *s != '\0')
				s++;
		}
		else
			s++;
	}
	return (nb_of_word);
}

static char	*get_word(char const **s, char c)
{
	size_t	len;
	char	*word;

	*s += skip_sep(*s, c);
	len = 0;
	while ((*s)[len] != '\0' && (*s)[len] != c)
		len++;
	word = ft_substr(*s, 0, len);
	*s += len;
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char			**strings;
	const size_t	word_count = ft_count_word(s, c);
	size_t			i;

	strings = malloc((word_count + 1) * sizeof(char *));
	if (strings == NULL)
		return (NULL);
	strings[word_count] = NULL;
	i = 0;
	while (i < word_count)
	{
		strings[i] = get_word(&s, c);
		if (strings[i] == NULL)
		{
			ft_clear(strings);
			break ;
		}
		i++;
	}
	return (strings);
}
