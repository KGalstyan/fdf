/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgalstya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 18:45:08 by kgalstya          #+#    #+#             */
/*   Updated: 2024/03/01 18:51:52 by kgalstya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
int		ft_strchr(char *s, char c);
int		ft_strlen(const char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_removeline(char *buffer);
char	*ft_readtext(int fd, char *buffer);
char	*ft_newline(char *buf);
char	*ft_strjoin_free(char *buffer, char *str);

#endif
