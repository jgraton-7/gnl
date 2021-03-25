/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraton- <jgraton-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 21:34:33 by jgraton-          #+#    #+#             */
/*   Updated: 2021/03/25 17:45:45 by jgraton-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "get_next_line.h"

char *ft_insert_in_line(char *str,char **line, int count)
{
    int c2;
    char *tmp;

    c2 = 0;
    while(str[c2])
    {
        if(str[c2] == '\n')       
            break ;
        c2++;
    }
    if((size_t)c2 < ft_strlen(str))
    {
        *line = ft_substr(str, 0, 1);
        tmp = ft_substr(str, (size_t)c2 + 1,  ft_strlen(str));
        free(str);
        str =  ft_strdup(tmp);
        free(tmp);
    }
    else if(count == 0)
    {
        *line = str;
        str = NULL;
    }
    return (str);
}

char *ft_concatenar(char *buffer, char *str)
{
    char *tmp;
    if(str)
    {
        tmp = ft_strjoin(str, buffer);
        free(str);
        str = ft_strdup(tmp);
        free(tmp);
    }
    else
    {
      str = ft_strdup(buffer);  
    }
    return (str);
}


int get_next_line(int fd, char **line)
{
    static char *str;
    char buffer[BUFFER_SIZE + 1];
    int count;

    while((count = read(fd, buffer, BUFFER_SIZE)))
    {
        if(count == -1)
            return (-1);
        buffer[count] = '\0';
        str = ft_concatenar(buffer, str);
        if(ft_strchr(str, '\n'))
            break;
    }
    if(count <= 0 && !str)
    {
        *line = ft_strdup("");
        return (count);
    }
    str = ft_insert_in_line(str, line, count);
    if(count <= 0 && !str)
    {
        *line = ft_strdup("");
        return (count);
    }
    return (1);
}
