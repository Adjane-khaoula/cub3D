/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadjane <kadjane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 14:48:46 by kadjane           #+#    #+#             */
/*   Updated: 2023/02/26 15:35:00 by kadjane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	char	*p;
	char	*p2;

	p = (char *)malloc(ft_strlen(src) + 1);
	if (!p)
		return (NULL);
	p2 = p;
	while (src && *src)
		*p++ = *src++;
	*p = '\0';
	return (p2);
}

char	*ft_strjoin(char *line, char *buff)
{
	char	*stock;
	char	*pstock;
	char	*pline;

	if (!(*line))
	{
		free(line);
		return (ft_strdup(buff));
	}
	stock = malloc(ft_strlen(line) + ft_strlen(buff) + 1);
	if (!stock)
		return (NULL);
	pstock = stock;
	pline = line;
	while (*line)
		*stock++ = *line++;
	while (*buff)
		*stock++ = *buff++;
	*stock = '\0';
	free(pline);
	return (pstock);
}
