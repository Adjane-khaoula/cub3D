/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadjane <kadjane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 14:49:15 by kadjane           #+#    #+#             */
/*   Updated: 2023/03/04 18:59:35 by kadjane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int valid_char(char c)
{
	if (c == '1' || c == '0' || c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (1);
	else
		return (0);
}

void check_first_char(char *line)
{
	while (line && *line == ' ')
		line++;
	if (line && *line && *line != '1')
	{
		printf("ERROR: map invalid \n");
		exit(1);
	}
}

void	check_first_last_line(char *line)
{
	while (line && *line == ' ')
		line++;
	while (*line == '1' || *line == ' ')
		line++;
	if (line && *line && *line != '1' && *line != ' ')
	{
		printf("ERROR: map invalid \n");
		exit(1);
	}
}

void	check_surroundings_zero(char **map, int i, int j)
{
	if ((!valid_char(map[i][j]) && map[i][j] != ' ') || (map[i][j] == '0' && (!valid_char(map[i][j - 1])
		|| !valid_char(map[i][j + 1])
		|| !valid_char(map[i - 1][j]) || !valid_char(map[i + 1][j]))))
	{
		printf ("ERROR: map invalid \n");
		exit (1);
	}
	
}

void	parse_map(char **map)
{
	int i;
	int j;

	i = 0;
	j = 0;
	check_first_char(map[0]);
	check_first_last_line(map[0]);
	while (map[++i] && map[i + 1])
	{
		j = 0;
		while (map[i][++j] == ' ')
			;
		check_first_char(map[i]);
		remove_space(&map[i]);
		while (map[i][++j])
			check_surroundings_zero(map, i, j);
	}
	check_first_last_line(map[i]);
	}
//new line in the end
// nb of the texters
// empty map