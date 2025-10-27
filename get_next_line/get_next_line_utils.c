/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechoi <jechoi@student.42gyongsan.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 10:41:11 by jechoi            #+#    #+#             */
/*   Updated: 2025/04/18 16:53:14 by jechoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	gft_strlen(const char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*gft_strdup(const char *s1)
{
	char	*dup;
	int		i;

	if (!s1)
		return (NULL);
	dup = (char *)malloc(sizeof(char) * (gft_strlen(s1) + 1));
	if (!dup)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		dup[i] = s1[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	*gft_substr(const char *str, unsigned int start, size_t len)
{
	char		*substr;
	char		*result;
	size_t		str_len;

	str_len = gft_strlen(str);
	if (start >= (unsigned int)gft_strlen(str))
		return (gft_strdup(""));
	else if (len + start > str_len)
		substr = malloc(sizeof(char) * (str_len - start + 1));
	else
		substr = malloc(sizeof(char) * (len + 1));
	if (!substr)
		return (NULL);
	result = substr;
	while (*(str + start) && len-- > 0)
		*(substr++) = *(str + start++);
	*substr = '\0';
	return (result);
}

char	*gft_strjoin(const char *s1, const char *s2)
{
	char	*dup;
	int		s1_len;
	int		s2_len;
	int		i;
	int		k;

	s1_len = gft_strlen(s1);
	s2_len = gft_strlen(s2);
	dup = malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!dup)
		return (NULL);
	i = -1;
	while (++i < s1_len)
		dup[i] = s1[i];
	k = -1;
	while (++k < s2_len)
		dup[i + k] = s2[k];
	dup[i + k] = '\0';
	return (dup);
}

char	*gft_strchr(const char *str, int c)
{
	while (*str)
	{
		if (*str == c)
			return ((char *)str);
		str++;
	}
	return (NULL);
}
