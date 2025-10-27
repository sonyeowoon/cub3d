/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memory2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechoi <jechoi@student.42gyongsan.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 17:12:57 by jechoi            #+#    #+#             */
/*   Updated: 2025/04/01 17:13:08 by jechoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*p;
	size_t				i;

	p = (const unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (p[i] == (unsigned char)c)
			return ((void *)(p + i));
		i++;
	}
	return (NULL);
}

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*p1;
	const unsigned char	*p2;

	if (n == 0)
		return (0);
	p1 = (const unsigned char *)s1;
	p2 = (const unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (*p1 != *p2)
			return (*p1 - *p2);
		p1++;
		p2++;
		i++;
	}
	return (0);
}

void	*ft_calloc(size_t num, size_t size)
{
	void	*tmp;

	if (num > SIZE_MAX / size)
		return (0);
	tmp = malloc(size * num);
	if (tmp == 0)
		return (0);
	ft_bzero(tmp, size * num);
	return (tmp);
}

char	*ft_strdup(const char *s1)
{
	char	*dup;
	int		i;

	if (!s1)
		return (NULL);
	i = 0;
	dup = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!dup)
		return (NULL);
	while (s1[i])
	{
		dup[i] = s1[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
