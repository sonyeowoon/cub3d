/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addft2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechoi <jechoi@student.42gyongsan.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 12:23:24 by jechoi            #+#    #+#             */
/*   Updated: 2025/04/04 12:23:26 by jechoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_check_len(int n)
{
	int	len;

	len = 1;
	if (n < 0)
	{
		n = -n;
		len++;
	}
	while (n > 9)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = ft_check_len(n);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (n == 0)
		str[0] = '0';
	if (n < 0)
	{
		str[0] = '-';
		n *= -1;
	}
	while (n > 0)
	{
		str[--len] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	char			*dest;
	size_t			len;
	unsigned int	i;

	if (!s || !f)
		return (0);
	len = ft_strlen(s);
	dest = malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (NULL);
	i = 0;
	while (i < len)
	{
		dest[i] = f(i, s[i]);
		i++;
	}
	dest[len] = '\0';
	return (dest);
}

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i] != '\0')
	{
		f(i, &s[i]);
		i++;
	}
}
