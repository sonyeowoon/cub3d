/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechoi <jechoi@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 20:54:13 by jechoi            #+#    #+#             */
/*   Updated: 2025/11/13 14:37:41 by jechoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	is_cub_file(char *file)
{
	size_t	len;
	char	*file_ex;
	char	*extension;

	extension = ".cub";
	len = ft_strlen(file);
	if (len < 4)
		return (1);
	file_ex = ft_substr(file, len - 4, 4);
	if (ft_strncmp(file_ex, extension, 4) != 0)
		return (free(file_ex), 1);
	return (free(file_ex), 0);
}

static int	is_xpm_file(char *file)
{
	size_t	len;
	char	*file_ex;
	char	*extension;

	extension = ".xpm";
	len = ft_strlen(file);
	if (len < 4)
		return (1);
	file_ex = ft_substr(file, len - 4, 4);
	if (ft_strncmp(file_ex, extension, 4) != 0)
		return (free(file_ex), 1);
	return (free(file_ex), 0);
}

int	check_file(char *file, int cub)
{
	int	fd;

	if (cub == 1 && is_cub_file(file) != 0)
		return (treat_err("Not cub file"), 1);
	if (cub == 0 && is_xpm_file(file) != 0)
		return (treat_err("Not xpm file"), 1);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (treat_err(strerror(errno)), 1);
	close(fd);
	return (0);
}
