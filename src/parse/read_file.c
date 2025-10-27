
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechoi <jechoi@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 22:39:29 by jechoi            #+#    #+#             */
/*   Updated: 2025/10/23 00:06:12 by jechoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	free_file_lines(char **lines, int count)
{
	int	i;

	if (!lines)
		return ;
	i = 0;
	while (i < count)
	{
		free(lines[i]);
		lines[i] = NULL;
		i++;
	}
	free(lines);
}

static int	count_lines(const char *filename)
{
	int		fd;
	int		count;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (perror("open"), -1);
	count = 0;
	line = get_next_line(fd);
	while (line)
	{
		count++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	if (count == 0)
		return (print_err("empty file file"), -1);
	return (count);
}

static void	trim_newline(char *line)
{
	size_t	len;

	if (!line)
		return ;
	len = ft_strlen(line);
	if (len > 0 && line[len - 1] == '\n')
		line[len - 1] = '\0';
}

static char	**get_lines(int fd, t_file *file)
{
	char	**lines;
	char	*line;
	int 	line_len;
	int		i;

	lines = malloc(sizeof(char *) * (file->line_count + 1));
	if (!lines)
		return (perror("malloc"), NULL);
	i = -1;
	while (++i < file->line_count)
	{
		line = get_next_line(fd);
		if (!line)
		{
			free_file_lines(lines, i);
			return (close(fd), print_err("gnl failed"), NULL);
		}
		trim_newline(line);
		lines[i] = line;
		line_len = ft_strlen(line);
		if (line_len > file->width)
			file->width = line_len;
	}
	lines[i] = NULL;
	return (lines);
}

int	read_file(const char *filename, t_file *file)
{
	char	**lines;
	int		fd;

	if (!filename || !file)
		return (print_err("invalid file args"), 1);
	file->line_count = count_lines(filename);
	if (file->line_count == -1)
		return (1);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (perror("open"), 1);
	lines = get_lines(fd, file);
	if (!lines)
		return (1);
	close(fd);
	file->file = lines;
	file->height = file->line_count;
	return (0);
}
