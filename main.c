/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadjane <kadjane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 16:31:28 by kadjane           #+#    #+#             */
/*   Updated: 2023/03/01 14:32:43 by kadjane          ###   ########.fr       */
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
		t_data	*data;
		char	*tmp;

		data = malloc (sizeof(t_data));
		(data->line) = malloc(sizeof(char *));
		*(data->line)= ft_strdup("");
		data->tab_identifier = NULL;
		data->identifier = fill_TabIdentifier();
		data->init_map = ft_strdup("");
		data->map = malloc(sizeof(char *));
		data->fd = open(av[1], O_RDONLY);
		if (data->fd < 0)
			return (0);
		while (*(data->line))
		{
			free(*data->line);
			(*data->line) = get_next_line(data->fd);
			tmp = (*data->line);
			if (data->line && *(data->line) && **(data->line) ==' ')
			{
				while (*tmp ==' ')
					tmp++;
			}
			if (ft_strcmp(*(data->line), "\n") && !ft_isnum(*tmp))
				parse_texture(&data);
			else if (ft_strcmp(*(data->line), "\n") && ft_isnum(*tmp))
				break ;
		}
		while (*(data->line))
		{
			data->init_map = ft_strjoin(data->init_map,*(data->line));
			free(*(data->line));
			*(data->line) = NULL;
			*(data->line) = get_next_line(data->fd);
		}
		data->map = ft_split(data->init_map, '\n');
		parse_map(data->map);
		// printf("len tab == %d\n", len_tab(data->map));
		// while(*(data->map++))
			// printf("%s\n", *(data->map));
		close(data->fd);
	}
}