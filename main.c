/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadjane <kadjane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 16:31:28 by kadjane           #+#    #+#             */
/*   Updated: 2023/02/27 18:54:58 by kadjane          ###   ########.fr       */
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
		int		i;
		int		j;

		i = 0;
		j = -1;
		data = malloc (sizeof(t_data));
		data->tab_identifier = NULL;
		data->identifier = fill_TabIdentifier();
		(data->line) = malloc(sizeof(char *));
		(data->map) = malloc(sizeof(char *));
		while (++j < 3)
			(data->map)[j] = NULL;
		*(data->line)= ft_strdup("");
		data->fd = open(av[1], O_RDONLY);
		if (data->fd < 0)
			return (0);
		while (*(data->line))
		{
			free(*data->line);
			(*data->line) = get_next_line(data->fd);
			while(data->line && *(data->line) && **(data->line) ==' ')
				(*(data->line))++;
			if(ft_strcmp(*(data->line), "\n") && !ft_isnum(**(data->line)))
				parse_texture(&data);
			else if (ft_strcmp(*(data->line), "\n") && ft_isnum(**(data->line)))
				break ;
		}
		while (*(data->line))
		{
			
		}
		// while (*(data->line))
		// {
		// 	// printf ("****> {%s} \n", *(data->line));
		// 	if (!(data->map)[0])
		// 	{
		// 		(data->map)[0] = ft_strdup(*(data->line));
		// 		while (++i < 3)
		// 			(data->map)[i] = ft_strdup(get_next_line(data->fd));
		// 		// parse_map(map);
		// 	}
		// 	else if ((data->map)[3])
		// 	{
		// 		free (*(data->line));
		// 		free ((data->map)[0]);
		// 		*(data->line) = ft_strdup(get_next_line(data->fd));
		// 		(data->map)[0] = ft_strdup(data->map[1]);
		// 		free ((data->map)[1]);
		// 		(data->map)[1] = ft_strdup(data->map[2]);
		// 		free ((data->map)[2]);
		// 		(data->map)[3] = *(data->line);
		// 		// parse_map(map);
		// 	}
		// }
		close(data->fd);
	}
}