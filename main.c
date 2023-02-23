/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadjane <kadjane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 16:31:28 by kadjane           #+#    #+#             */
/*   Updated: 2023/02/23 18:56:48 by kadjane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int main (/*int ac, char **av*/)
{
	char	**line;
	int		fd;

	// *line = ft_strdup("");
	fd = open("map.cub", O_RDONLY);
	if (fd < 0)
		return (0);
	line = get_next_line(fd);
	while (*line)
	{
		line = get_next_line(fd);
		printf ("line = {%s}\n", *line);
	}
}