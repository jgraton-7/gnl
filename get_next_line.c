/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraton- <jgraton-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 21:34:33 by jgraton-          #+#    #+#             */
/*   Updated: 2021/04/01 17:28:27 by jgraton-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "get_next_line.h"

int ft_len_fist_line(char *str, int count)
{
    while (str[count])
    {
        if(str[count] == '\n')
            break ;
        count++;
    }
    return(count);
}

char *ft_insert_in_line(char *str,char **line, int count)
{
    int c2;
    size_t c3;
    char *tmp;

    c2 = ft_len_fist_line(str, 0);
    c3 = ft_strlen(str);
    if ((size_t)c2 < c3)
    {
        *line = ft_substr(str, 0, c2);
        tmp = ft_substr(str, c2 + 1,  c3);
        free(str);
        str =  ft_strdup(tmp);
        free(tmp);
        return (str);
    }
    else if (count == 0)
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
        str = ft_strdup(buffer);  
    return (str);
}
int ft_size_buf(int buf)
{
    if (BUFFER_SIZE > 1000000)
        return (100000);
    else
        return (buf);
    return (buf);
        
}

int get_next_line(int fd, char **line)
{
    static char *str;
    char buffer[ft_size_buf(BUFFER_SIZE + 1)];
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
        return (count);
    return (1);
}
