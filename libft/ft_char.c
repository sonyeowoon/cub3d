/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechoi <jechoi@student.42gyongsan.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 12:50:09 by jechoi            #+#    #+#             */
/*   Updated: 2025/04/01 13:13:21 by jechoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((unsigned char)c >= 65 && (unsigned char)c <= 90)
		return (1);
	else if ((unsigned char)c >= 97 && (unsigned char)c <= 122)
		return (2);
	else
		return (0);
}

int	ft_isdigit(int c)
{
	unsigned char	temp;

	temp = (unsigned char)c;
	if ((unsigned char)c >= 48 && (unsigned char)c <= 57)
		return (temp);
	else
		return (0);
}

int	ft_isalnum(int c)
{
	unsigned char	temp;

	temp = (unsigned char)c;
	if ((temp >= 65 && temp <= 90) || (temp >= 97 && temp <= 122))
		return (temp);
	else if (c >= 48 && c <= 57)
		return (temp);
	else
		return (0);
}

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}

int	ft_isprint(int c)
{
	if ((unsigned char)c >= 32 && (unsigned char)c <= 126)
		return (1);
	return (0);
}
