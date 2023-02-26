/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadjane <kadjane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 16:29:05 by kadjane           #+#    #+#             */
/*   Updated: 2023/02/26 01:52:33 by kadjane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	full_TabIdentifier(char **identifier)
{
	identifier = malloc (sizeof (char *) * 6);
	identifier[0] = ft_strdup("NO");
	identifier[1] = ft_strdup("SO");
	identifier[2] = ft_strdup("WE");
	identifier[3] = ft_strdup("EA");
	identifier[5] = ft_strdup("F");
	identifier[6] = ft_strdup("C");
}

void	parse_texture(char *texture)
{
	char	**line;
	char	**identifier;
	int		i;

	i = -1;
	identifier = NULL;
	full_TabIdentifier(identifier);
	if (texture && *texture != '\n')
	{
		line = ft_split(texture, ' ');
			while (++i < 6)
			{
				if (ft_strcmp(line,identifier[i]))
				{
					
				}
			}
			
		
	}
}
