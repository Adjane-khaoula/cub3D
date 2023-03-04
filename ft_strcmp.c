/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadjane <kadjane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 08:16:31 by kadjane           #+#    #+#             */
/*   Updated: 2023/03/04 20:44:30 by kadjane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	if (s1 && s2)
	{
		while (s1[i] && s2[i] && s1[i] == s2[i])
			i++;
		return (s1[i] - s2[i]);
	}
	else
		return (0);
}

int	ft_isum(int c)
{
	if ((c >= '0' && c <= '9'))
		return (1);
	else
		return (0);
}

void	remove_space(char **line)
{
	int		i;
	int		j;
	int		len;
	char	*tmp;
	char	*line_without_space;

	i = 0;
	j = 0;
	tmp = *line;
	while (tmp && tmp[ft_strlen(tmp) - (++i)] == ' ')
		j++;
	i = 0;
	line_without_space = malloc(ft_strlen(tmp) - j + 1);
	len = (ft_strlen(tmp) - j);
	while (tmp && *tmp && i < len)
		line_without_space[i++] = *tmp++;
	line_without_space[i] = '\0';
	free(*line);
	*line = line_without_space;
}