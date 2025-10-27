/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechoi <jechoi@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 13:13:03 by jechoi            #+#    #+#             */
/*   Updated: 2025/10/22 21:16:37 by jechoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

unsigned int	ft_strlcpy(char *dest, const char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	len_src;

	len_src = 0;
	i = 0;
	while (src[len_src])
		len_src++;
	if (size != 0)
	{
		while (i < (size - 1) && src[i])
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (len_src);
}

unsigned int	ft_strlcat(char *dest, const char *src, unsigned int size)
{
	unsigned int	p_dest;
	unsigned int	p_src;
	unsigned int	dest_len;
	unsigned int	src_len;

	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	p_dest = dest_len;
	p_src = 0;
	if (size <= dest_len)
		return (src_len + size);
	while (src[p_src] && (p_dest + 1) < size)
	{
		dest[p_dest] = src[p_src];
		p_dest++;
		p_src++;
	}
	dest[p_dest] = '\0';
	return (src_len + dest_len);
}

char	*ft_strchr(const char *str, int c)
{
	while (*str)
	{
		if (*str == (unsigned char)c)
			return ((char *)str);
		str++;
	}
	if (*str == (unsigned char)c)
		return ((char *)str);
	return (NULL);
}

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] == (unsigned char)c)
			return ((char *)(s + i));
		i--;
	}
	return (NULL);
}
