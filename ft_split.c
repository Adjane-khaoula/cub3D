/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadjane <kadjane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 15:14:09 by kadjane           #+#    #+#             */
/*   Updated: 2023/02/26 19:22:04 by kadjane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	nbrword(char const *s, char c)
{
	int	i;

	i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			i++;
		while (*s && *s != c)
			s++;
	}
	return (i);
}

int	lenword(char const *s, char c)
{
	int	i;

	i = 0;
	while (s && *s && *s++ != c)
		i++;
	return (i);
}

void	rempltab(char const *s, char **tabstr, char c)
{
	int	j;
	int	i;
	int	len;
//error hear
	i = -1;
	len = nbrword(s, c);
	while (*s && ++i < len)
	{
		while (s && *s == c)
			s++;
		printf("*s == {%s}\n",s);
		if (s && *s && *s != '\n')
		{
			*(tabstr + i) = malloc(lenword(s, c) + 1);
			if (!(*(tabstr + i)))
				return ;
		}
		j = -1;
		while (*s && *s != c)
			tabstr[i][++j] = *s++;
		tabstr[i][++j] = '\0';
	}
	tabstr[++i] = NULL;
}

char	**ft_split(char const *s, char c)
{
	char	**tabstr;

	if (!s)
		return (0);
	tabstr = malloc((nbrword(s, c) + 1) * sizeof(char *));
	if (!tabstr)
		return (0);
	rempltab(s, tabstr, c);
	return (tabstr);
}
