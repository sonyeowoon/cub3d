/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechoi <student.42gyeongsan.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 10:40:55 by jechoi            #+#    #+#             */
/*   Updated: 2025/05/17 17:37:47 by jechoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_line(int fd, char *buffer, char *backup)
{
	int		count;
	char	*temp;

	count = 1;
	while (count)
	{
		count = read(fd, buffer, BUFFER_SIZE);
		if (count < 0)
			return (NULL);
		else if (count == 0)
			break ;
		buffer[count] = '\0';
		if (!backup)
			backup = gft_strdup("");
		temp = backup;
		backup = gft_strjoin(temp, buffer);
		if (!backup)
			return (free(temp), NULL);
		free(temp);
		temp = NULL;
		if (gft_strchr(buffer, '\n'))
			break ;
	}
	return (backup);
}

char	*ft_extract(char *line)
{
	int		i;
	char	*result;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	if (line[i] == '\0')
		return (0);
	result = gft_substr(line, i + 1, gft_strlen(line) - i);
	if (!result)
		return (NULL);
	if (result[0] == '\0')
	{
		free(result);
		result = NULL;
		return (NULL);
	}
	line[i] = '\0';
	return (result);
}

char	*get_next_line(int fd)
{
	static char	*backup[OPEN_MAX];
	char		*buffer;
	char		*result;
	int			len;

	if (fd < 0 || fd > 256 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	result = ft_read_line(fd, buffer, backup[fd]);
	free(buffer);
	buffer = NULL;
	if (!result)
		return (NULL);
	backup[fd] = ft_extract(result);
	len = gft_strlen(result);
	if (len > 0 && result[len - 1] == '\n')
		result[len - 1] = '\0';
	return (result);
}
