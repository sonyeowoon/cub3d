/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechoi <jechoi@student.42gyongsan.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 10:41:06 by jechoi            #+#    #+#             */
/*   Updated: 2025/04/18 16:54:18 by jechoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX 1024
# endif

int		gft_strlen(const char *str);
char	*gft_strdup(const char *s1);
char	*gft_substr(const char *str, unsigned int start, size_t len);
char	*gft_strjoin(const char *s1, const char *s2);
char	*gft_strchr(const char *str, int c);
char	*ft_read_line(int fd, char *buffer, char *backup);
char	*ft_extract(char *line);
char	*get_next_line(int fd);

#endif
