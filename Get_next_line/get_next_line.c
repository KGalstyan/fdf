/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgalstya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 18:44:07 by kgalstya          #+#    #+#             */
/*   Updated: 2024/03/01 18:51:17 by kgalstya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_newline(char *buf)
{
	int		i;
	char	*buf1;

	i = 0;
	if (!buf)
		return (NULL);
	while (buf[i] != '\n' && buf[i])
		i++;
	buf1 = (char *)malloc(sizeof(char) * (i + 2));
	if (!buf1)
		return (NULL);
	i = 0;
	while (buf[i] != '\n' && buf[i])
	{
		buf1[i] = buf[i];
		i++;
	}
	if (buf[i] == '\n' && buf[i])
	{
		buf1[i] = '\n';
		i++;
	}
	buf1[i] = '\0';
	return (buf1);
}

char	*ft_removeline(char *buffer)
{
	char	*str;
	int		i;
	int		n;

	i = 0;
	n = 0;
	while (buffer[i] != '\n' && buffer[i])
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	i++;
	str = (char *)malloc(ft_strlen(buffer) - i + 1);
	if (!str)
		return (NULL);
	while (buffer[i])
		str[n++] = buffer[i++];
	str[n] = '\0';
	free(buffer);
	return (str);
}

char	*ft_readtext(int fd, char *buffer)
{
	char	*str;
	int		read_char;

	read_char = 1;
	while (read_char > 0)
	{
		str = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!str)
			return (NULL);
		read_char = read(fd, str, BUFFER_SIZE);
		if (read_char == -1)
		{
			free(str);
			return (NULL);
		}
		str[read_char] = '\0';
		buffer = ft_strjoin_free(buffer, str);
		free(str);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (buffer);
}

char	*get_next_line(int fd)
{
	char		*buf;
	static char	*buffer;

	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, 0, 0) < 0)
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	buffer = ft_readtext(fd, buffer);
	if (!buffer)
		return (NULL);
	buf = ft_newline(buffer);
	buffer = ft_removeline(buffer);
	if (*buf == '\0')
	{
		free(buf);
		free(buffer);
		buffer = NULL;
		buf = NULL;
	}
	return (buf);
}

// int	main(void)
// {
// 	int fd;
// 	int i = 0;
// 	fd = open("test.txt", O_RDONLY);

// 	while (i < 1)
// 	{
// 		printf("%s", get_next_line(fd));
// 		i++;
// 	}

// 	// printf("%s", ft_readtext(fd, g));

// 	// printf("%s\n", ft_removeline("aaaa\naaa\ns"));

// 	// printf("%s", ft_newline("aaaa\naaa\ns"));

// 	return (0);
// }
