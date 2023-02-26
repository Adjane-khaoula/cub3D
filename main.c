/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadjane <kadjane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 16:31:28 by kadjane           #+#    #+#             */
/*   Updated: 2023/02/26 01:31:25 by kadjane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int main (int ac, char **av)
{
	if (ac == 2)
	{
		char	**line;
		int		fd;
	
		line = malloc(sizeof(char *));
		*line = ft_strdup("");
		fd = open(av[1], O_RDONLY);
		if (fd < 0)
			return (0);
		while (*line)
		{
			*line = get_next_line(fd);
			parse_texture(*line);
		}
	}
}