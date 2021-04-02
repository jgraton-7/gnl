/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraton- <jgraton-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 21:34:52 by jgraton-          #+#    #+#             */
/*   Updated: 2021/04/02 16:06:20 by jgraton-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t count;

	count = 0;
	while (s[count] != '\0')
		count++;
	return (count);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		count;
	int		cpy;

	count = 0;
	if (!(str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (NULL);
	while (s1[count])
	{
		str[count] = s1[count];
		count++;
	}
	cpy = 0;
	while (s2[cpy])
	{
		str[count] = s2[cpy];
		count++;
		cpy++;
	}
	str[count] = '\0';
	if (!str)
		return (NULL);
	return (str);
}

char	*ft_strdup(const char *s)
{
	char	*cpy;
	int		count;

	count = 0;
	if (!(cpy = (char *)malloc(sizeof(const char) * (ft_strlen(s) + 1))))
		return (0);
	while (s[count])
	{
		cpy[count] = s[count];
		count++;
	}
	cpy[count] = '\0';
	return (cpy);
}

char	*ft_strchr(const char *s, int c)
{
	int count;

	count = 0;
	while (s[count])
	{
		if (s[count] == (char)c)
		{
			return ((char*)s + count);
		}
		count++;
	}
	if (s[count] == (char)c)
	{
		return ((char*)s + count);
	}
	return (0);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	count;
	size_t	c2;

	if (!(str = malloc(sizeof(*s) * (len + 1))))
		return (NULL);
	if (!s)
		return (NULL);
	count = 0;
	c2 = 0;
	while (s[c2++])
	{
		if (c2 >= start && count < len)
		{
			str[count] = s[start];
			count++;
			start++;
		}
	}
	str[count] = '\0';
	return (str);
}
