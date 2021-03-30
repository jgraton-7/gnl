/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraton- <jgraton-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 21:34:33 by jgraton-          #+#    #+#             */
/*   Updated: 2021/03/30 20:24:17 by jgraton-         ###   ########.fr       */
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

char *ft_swap(char *str, char **line, size_t c2, size_t c3)
{
    char *tmp;
    
    *line = ft_substr(str, 0, c2);
    tmp = ft_substr(str, c2 + 1,  c3);
    free(str);
    str =  ft_strdup(tmp);
    free(tmp);
    return (str);
}

char *ft_insert_in_line(char *str,char **line, int count)
{
    size_t c2;
    size_t c3;

    c2 = ft_len_fist_line(str, 0);
    c3 = ft_strlen(str);
    if (c2 < c3)
        str = ft_swap(str, line, c2, c3);
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
        return (count);
    return (1);
}
