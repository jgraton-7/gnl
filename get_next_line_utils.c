/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraton- <jgraton-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 21:34:52 by jgraton-          #+#    #+#             */
/*   Updated: 2021/03/18 16:45:37 by jgraton-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t count;

	count = 0;
	while (s[count] != '\0')
	{
		count++;
	}
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
	if (!(cpy = (char *)malloc(sizeof(*s) * ft_strlen(s) + 1)))
		return (0);
	while (s[count])
	{
		cpy[count] = s[count];
		count++;
	}
	cpy[count] = 0;
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

