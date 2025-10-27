/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addft3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechoi <jechoi@student.42gyongsan.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 12:23:44 by jechoi            #+#    #+#             */
/*   Updated: 2025/04/04 12:23:45 by jechoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	write(fd, s, ft_strlen(s));
}

void	ft_putendl_fd(char *s, int fd)
{
	ft_putstr_fd(s, fd);
	write(fd, "\n", 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	char	number[11];
	int		i;

	if (n < 0)
	{
		if (n == -2147483648)
			write(fd, "-2147483648", 11);
		else
		{
			write(fd, "-", 1);
			n = -n;
		}
	}
	i = 0;
	while (n > 0)
	{
		number[i] = (n % 10) + '0';
		n /= 10;
		i++;
	}
	number[i] = '\0';
	while (i-- >= 0)
		write(1, &number[i], 1);
}
