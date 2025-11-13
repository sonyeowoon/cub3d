/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechoi <jechoi@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 03:06:26 by jechoi            #+#    #+#             */
/*   Updated: 2025/11/13 14:45:10 by jechoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

int	is_space2(char c)
{
	return (c == ' ' || c == '\t' || c == '\n'
		|| c == '\r' || c == '\v' || c == '\f');
}

int	is_space_ex_newline(char c)
{
	return (c == ' ' || c == '\t' || c == '\r'
		|| c == '\v' || c == '\f');
}

int	ft_iscardinal(char c1, char c2)
{
	char	*str;

	str = malloc(sizeof(char) * 3);
	if (!str)
		return (perror("malloc"), 1);
	str[0] = c1;
	str[1] = c2;
	str[2] = '\0';
	if (ft_strncmp(str, "NO", 2) == 0)
		return (free(str), 0);
	else if (ft_strncmp(str, "SO", 2) == 0)
		return (free(str), 0);
	else if (ft_strncmp(str, "WE", 2) == 0)
		return (free(str), 0);
	else if (ft_strncmp(str, "EA", 2) == 0)
		return (free(str), 0);
	return (free(str), 1);
}

int	is_valid_char(char c)
{
	return (c == '0' || c == '1' || c == 'N' || c == 'S'
		|| c == 'E' || c == 'W' || is_space_ex_newline(c));
}
