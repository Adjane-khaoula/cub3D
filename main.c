/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadjane <kadjane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 16:31:28 by kadjane           #+#    #+#             */
/*   Updated: 2023/02/27 12:49:15 by kadjane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

char	**fill_TabIdentifier()
{
	char	**identifier;

	identifier = malloc (sizeof (char *) * 7);
	if (!identifier)
		return (NULL);
	identifier[0] = ft_strdup("NO");
	identifier[1] = ft_strdup("SO");
	identifier[2] = ft_strdup("WE");
	identifier[3] = ft_strdup("EA");
	identifier[4] = ft_strdup("F");
	identifier[5] = ft_strdup("C");
	identifier[6] = NULL;
	return (identifier);
}

int main (int ac, char **av)
{
	if (ac == 2)
	{
		char	**line;
		char	**identifier;
		char	**tab_identifier;
		int		fd;

		tab_identifier = NULL;
		identifier = fill_TabIdentifier();
		line = malloc(sizeof(char *));
		*line = ft_strdup("");
		fd = open(av[1], O_RDONLY);
		if (fd < 0)
			return (0);
		while (*line)
		{
			free(*line);
			*line = get_next_line(fd);
			// printf("*line == %s \n", *line);
			if(ft_strcmp(*line, "\n"))
				tab_identifier = parse_texture(*line, identifier, tab_identifier);
		}
	}
}