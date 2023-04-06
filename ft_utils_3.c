/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadjane <kadjane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 12:56:07 by kadjane           #+#    #+#             */
/*   Updated: 2023/04/05 22:04:22 by kadjane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	init_data_2(t_data *data)
{
	data->color = malloc(sizeof(t_color));
	if (!data->color)
		ft_error("error in the allocation\n");
	data->color->c_blue = 0;
	data->color->c_ceiling = 0;
	data->color->c_floor = 0;
	data->color->c_green = 0;
	data->color->c_red = 0;
	data->color->f_blue = 0;
	data->color->f_green = 0;
	data->color->f_red = 0;
	data->color->rgb_floor = NULL;
	data->color->rgb_ceiling = NULL;
}

void	init_data(t_data *data, char **av)
{
	(data->line) = malloc(sizeof(char *));
	*(data)->line = ft_strdup("");
	(data)->tab_identifier = NULL;
	(data)->identifier = fill_tab_identifier();
	(data)->init_map = ft_strdup("");
	(data)->map = malloc(sizeof(char *));
	(data)->textures = malloc(sizeof(char *) * 7);
	(data)->fd = open(av[1], O_RDONLY);
	if (data->fd < 0 || !check_file_name(av[1], "cub"))
		ft_error("file not exist\n");
	if (!data->line || !(data)->textures
		|| !data->map)
		ft_error("error in the allocation\n");
	init_data_2(data);
}

char	**fill_tab_identifier(void)
{
	char	**identifier;

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

void	ft_free(char **tab)
{
	int	i;

	i = -1;
	while (tab[++i])
		free (tab[i]);
	free(tab);
}

int	check_file_name(char *file_name, char *extention)
{
	char	**split_name;

	split_name = ft_split(file_name, '.');
	if (len_tab(split_name) != 2
		|| (len_tab(split_name) == 2 && ft_strcmp(split_name[1], extention)))
	{
		ft_free(split_name);
		return (0);
	}
	ft_free(split_name);
	return (1);
}
