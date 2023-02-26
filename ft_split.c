/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadjane <kadjane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 15:14:09 by kadjane           #+#    #+#             */
/*   Updated: 2023/02/26 00:16:37 by kadjane          ###   ########.fr       */
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

char	*allocat(char const *s, char **tabstr, char c, int i)
{
	// int	j;
	*(tabstr + i) = (char *)malloc(lenword(s, c) + 1);
	// if (!tabstr)
	// {
	// 	printf ("************enter hear\n");
	// 	j = 0;
	// 	while (j++ < i)
	// 		free(*(tabstr + j));
	// 	free(tabstr);
	// 	return (0);
	// }
	return (*(tabstr + i));
}

char	**rempltab(char const *s, char **tabstr, char c)
{
	int	l;
	int	k;
	int	i;
	// int	m;

	i = -1;
	k = nbrword(s, c);
	while (*s && ++i < k)
	{
		while (*s == c)
			s++;
		allocat(s, tabstr, c, i);
		// m = lenword(s, c);
		l = -1;
		while (*s && *s != c)
			tabstr[i][++l] = *s++;
		tabstr[i][++l] = '\0';
	}
	return (tabstr);
}

char	**ft_split(char const *s, char c)
{
	char	**tabstr;

	if (!s)
		return (0);
	tabstr = (char **)malloc((nbrword(s, c) + 1) * sizeof(char *));
	if (!tabstr)
		return (0);
	rempltab(s, tabstr, c);
	return (tabstr);
}
