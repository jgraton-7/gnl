/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraton- <jgraton-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 21:35:03 by jgraton-          #+#    #+#             */
/*   Updated: 2021/03/19 19:07:31 by jgraton-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
#endif
#ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
#endif
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *s);
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
int get_next_line(int fd, char **line);
char	*ft_substr(char const *s, unsigned int start, size_t len);