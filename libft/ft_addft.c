/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addft.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechoi <jechoi@student.42gyongsan.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 12:23:49 by jechoi            #+#    #+#             */
/*   Updated: 2025/04/04 12:23:51 by jechoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *str, unsigned int start, size_t len)
{
	char	*substr;
	char	*result;
	size_t	str_len;

	str_len = ft_strlen(str);
	if (start >= (unsigned int)ft_strlen(str))
		return (ft_strdup(""));
	else if (len + start > str_len)
		substr = (char *)malloc(sizeof(char) * (str_len - start + 1));
	else
		substr = (char *)malloc(sizeof(char) * (len + 1));
	if (!substr)
		return (NULL);
	result = substr;
	while (*(str + start) && len-- > 0)
		*substr++ = *(str + start++);
	*substr = '\0';
	return (result);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*dup;
	int		p1_len;
	int		p2_len;
	int		i;

	p1_len = ft_strlen(s1);
	p2_len = ft_strlen(s2);
	dup = malloc(sizeof(char) * (p1_len + p2_len + 1));
	if (!dup)
		return (NULL);
	i = 0;
	while (i < p1_len)
		dup[i++] = *s1++;
	while (i < p2_len + p1_len)
		dup[i++] = *s2++;
	dup[i] = '\0';
	return (dup);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	size_t	start;
	size_t	end;
	char	*res;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	end = ft_strlen(s1);
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	while (end > start && s1[end - 1] && ft_strchr(set, s1[end - 1]))
		end--;
	res = (char *)malloc(sizeof(char) * (end - start + 1));
	if (!res)
		return (NULL);
	ft_strlcpy(res, &s1[start], end - start + 1);
	return (res);
}
