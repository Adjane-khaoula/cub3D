/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadjane <kadjane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 14:49:15 by kadjane           #+#    #+#             */
/*   Updated: 2023/03/01 16:34:59 by kadjane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	parse_map(char **map)
{
	int	i;
	int	j;
	
	i = -1;

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
}