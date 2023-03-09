/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadjane <kadjane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 16:31:28 by kadjane           #+#    #+#             */
/*   Updated: 2023/03/09 18:09:42 by kadjane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

char **fill_TabIdentifier()
{
	char **identifier;

	identifier = malloc(sizeof(char *) * 7);
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

void	ft_free(char **map)
{
	while (map && *map)
	{
		free (*map);
		*map = NULL;
	}
}

int	is_whitespace(char c)
{
	if (c == 9 || (c > 10 && c <= 13) || c == ' ')
		return (1);
	return (0);
}

int main(int ac, char **av)
{
	if (ac == 2)
	{
		t_data	*data;
		char	*tmp;
		int		other_whitespace;
		int		i;
		int		j;

		j = 0;
		data = malloc(sizeof(t_data));
		(data->line) = malloc(sizeof(char *));
		*(data->line) = ft_strdup("");
		data->tab_identifier = NULL;
		data->identifier = fill_TabIdentifier();
		data->init_map = ft_strdup("");
		data->map = malloc(sizeof(char *));
		data->textures = malloc(sizeof(char *));
		data->fd = open(av[1], O_RDONLY);
		if (data->fd < 0)
			return (0);
		while (*(data->line))
		{
			free(*data->line);
			other_whitespace = 0;
			(*data->line) = get_next_line(data->fd);
			tmp = (*data->line);
			if (data->line && *(data->line) && is_whitespace(**(data->line)))
			{
				while (is_whitespace(*tmp))
				{
					if (*tmp != ' ')
						other_whitespace++;
					tmp++;
				}
				if (*tmp++ == '\n')
				// {
					other_whitespace = 0;
					// tmp++;
				// }
			}
			printf ("÷----> [%d]\n",other_whitespace);
			// printf ("----> [%s]\n",tmp);
			if (ft_strcmp(*(data->line), "\n") && *tmp && !ft_isum(*tmp))
			{
				parse_texture(&data);
				data->textures[j++] = ft_strdup(*data->line);
			}
			else if (ft_strcmp(*(data->line), "\n") && *tmp && ft_isum(*tmp) && !other_whitespace)
				break ;
			// printf ("{%s}\n", tmp);
		}
			// printf ("----> %s\n",*(data->line));
		while (*(data->line))
		{
			data->init_map = ft_strjoin(data->init_map, *(data->line));
			free(*(data->line));
			*(data->line) = NULL;
			*(data->line) = get_next_line(data->fd);
			if (!*(data->line) || (*(data->line) && *(data->line)[0] == '\n'))
			{
				data->map = ft_split(data->init_map, '\n');
				i = parse_map(data->map);
			}
			if (i == 0 && (*(data->line) && *(data->line)[0] == '\n'))
			{
				ft_free(data->map);
				free (data->init_map);
				data->init_map = ft_strdup("");
				while (*(data->line) && *(data->line)[0] == '\n')
				{
					printf("i == %d\n", i);
					free(*(data->line));
					*(data->line) = get_next_line(data->fd);
				}
			}
		}
		if (i == 0)
		{
			printf("ERROR: map invalid \n");
			exit(1);
		}
		// printf ("----> [%s]\n", data->init_map);
		// parse_map(data->map);
		// printf("len tab == %d\n", len_tab(data->map));
		// while(*(data->map++))
		// 	printf("%s\n", *(data->map));
		close(data->fd);
	}
}