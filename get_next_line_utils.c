/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadjane <kadjane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 14:48:46 by kadjane           #+#    #+#             */
/*   Updated: 2023/02/23 18:55:04 by kadjane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (0);
	else
	{
		while (str[i])
			i++;
	}
	return (i);
}

char	*ft_strdup(char *src)
{
	int		l;
	int		i;
	char	*p;
	char	*p2;

	i = 0;
	l = ft_strlen(src) + 1;
	p = (char *)malloc(l);
	if (!p)
		return (NULL);
	p2 = p;
	while (src[i])
	{
		*p = src[i];
		p++;
		i++;
	}
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
