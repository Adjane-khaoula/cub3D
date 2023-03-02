/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadjane <kadjane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 14:49:15 by kadjane           #+#    #+#             */
/*   Updated: 2023/03/02 18:50:48 by kadjane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	valid_char(char c)
{
	if (c == '1' || c == '0' || c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (1);
	else
		return (0);
}

void	check_first_char(char *line)
{
	while (line && *line == ' ')
		line++;
	if (line && *line && *line != '1')
	{
		printf ("ERROR: map invalid \n");
		exit (1);
	}
}

void	check_first_last_line(char *line)
{
	while (line && *line == ' ')
		line++;
	while (*line == '1')
		line++;
	if (line && *line && *line != '1')
	{
		printf ("ERROR: map invalid \n");
		exit (1);
	}
}

void	parse_map(char **map)
{
	int	i;
	int	j;
	
	i = 0;

	while (map[++i])
	{
		printf("{%s}\n", map[i]);
		j = -1;
		while (i - 1 >= 0 && map[i][++j])
		{
			if (map[i][j] == '0' && (map[i - 1][j] == ' ' || map[i + 1][j] == ' '
					|| (!map[i][j + 1] && map[i][j - 1] == '0') || map[i][j + 1] == ' '|| map[i][j - 1] == ' '))
			{
				printf ("ERROR: map invalid \n");
				exit (1);
			}
		}
	}
	j = 0;
	check_first_char(map[0]);
	check_first_last_line(map[0]);
	// while (map[0][++j])
	// {
	// 	printf ("-------------map[0][%d] == %c\n",j, map[0][j]);
	// 	if (map[0][j] != '1')
	// 	{
	// 		printf ("ERROR: map invalid \n");
	// 		exit (1);
	// 	}
	// }
// 	while (map[++i])
// 	{
// 		j = 0;
// 		check_first_char(map[i]);
// 		while (map[i][++j])
// 		{
// 			if (map[i][j] == '0' && (map[i - 1][j] == ' ' || map[i + 1][j] == ' '
// 				|| !map[i][j + 1] || map[i][j + 1] == ' '|| map[i][j - 1] == ' '))
// 			{
// 				printf ("ERROR: map invalid \n");
// 				exit (1);
// 			}
// 		}
// 		// while (map[i][++j])
// 		// {
// 		// 	if (!valid_char(map[i][j]))
// 		// 	{
// 		// 		printf ("ERROR: map invalid \n");
// 		// 		exit (1);
// 		// 	}
// 		// }
// 	}
// }

//check the first and last line 
//check the space inside the map 
// the first in map shod be 1
