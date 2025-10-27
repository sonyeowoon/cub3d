/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechoi <jechoi@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 12:23:58 by jechoi            #+#    #+#             */
/*   Updated: 2025/10/23 03:56:13 by jechoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_word_count(const char *s, char c)
{
	int	count;
	int	new_word;

	count = 0;
	new_word = 0;
	if (!s)
		return (0);
	while (*s)
	{
		if (*s != c && !new_word)
		{
			new_word = 1;
			count++;
		}
		else if (*s == c)
			new_word = 0;
		s++;
	}
	return (count);
}

char	*split_strcpy(const char *start, const char *end)
{
	char	*dest;
	char	*or;
	size_t	len;

	len = end - start;
	dest = (char *)malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (NULL);
	or = dest;
	while (start != end && *start != ' ' && *start != '\t')
	{
		*dest = *start;
		start++;
		dest++;
	}
	*dest = '\0';
	return (or);
}

void	free_split(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		free(array[i++]);
	free(array);
}

char	**ft_separation(const char *s, char **array, char c)
{
	const char	*start;
	char		**or;

	or = array;
	while (*s)
	{
		if (*s != c)
		{
			start = s;
			while (*s && *s != c)
				s++;
			*array = split_strcpy(start, s);
			if (!array)
				return (free_split(or), NULL);
			array++;
		}
		else
			s++;
	}
	*array = NULL;
	return (or);
}

char	**ft_split(const char *s, char c)
{
	char		**array;
	char		**or;
	size_t		word_count;

	if (!s)
		return (NULL);
	word_count = ft_word_count(s, c);
	array = (char **)malloc(sizeof(char *) * (word_count + 1));
	if (!array)
		return (NULL);
	if (word_count == 0)
	{
		array[0] = NULL;
		return (array);
	}
	or = ft_separation(s, array, c);
	return (or);
}
