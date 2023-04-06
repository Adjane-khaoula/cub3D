/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadjane <kadjane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 16:31:28 by kadjane           #+#    #+#             */
/*   Updated: 2023/04/06 01:17:29 by kadjane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	ft_end_stock_textures(t_data *data, char *tmp, int *j)
{
	if (ft_strcmp(*(data->line), "\n")
		&& *tmp && ft_isum(*tmp) && !data->other_whitespace)
	{
		if (*j != 6)
			ft_error("Number of textures not correct\n");
		data->textures[*j] = NULL;
		return (1);
	}
	return (0);
}

void	ft_textures(t_data *data)
{
	char	*tmp;
	int		j;

	j = 0;
	tmp = NULL;
	while (*(data->line))
	{
		free(*data->line);
		data->other_whitespace = 0;
		(*data->line) = get_next_line(data->fd);
		if (!*data->line)
			ft_error("empty file \n");
		check_whitespace(data, &(data->other_whitespace), &tmp);
		if (ft_strcmp(*(data->line), "\n") && *tmp && !ft_isum(*tmp) && j < 7)
		{
			parse_texture(&data);
			data->textures[j++] = ft_strdup(*data->line);
		}
		else if (ft_end_stock_textures(data, tmp, &j))
			break ;
	}
}

void	ft_map(t_data *data)
{
	while (*(data->line))
	{
		data->init_map = ft_strjoin(data->init_map, *(data->line));
		free(*(data->line));
		*(data->line) = NULL;
		*(data->line) = get_next_line(data->fd);
		if (!*(data->line) || (*(data->line) && *(data->line)[0] == '\n'))
		{
			free (data->map);
			data->map = ft_split(data->init_map, '\n');
			parse_map(data->map);
			while (*(data->line) && *(data->line)[0] == '\n')
			{
				free(*(data->line));
				*data->line = NULL;
				*(data->line) = get_next_line(data->fd);
			}
			break ;
		}
	}
	if (*(data->line))
	{
		free (*(data->line));
		ft_error("map_invalid\n");
	}
}

void	ft_check_textures(t_data *data)
{
	int		i;
	int		nbr;
	char	**tmp;
	char	*buff;

	buff = malloc(2);
	i = -1;
	while (data->textures[++i])
	{
		tmp = ft_split_textures(data->textures[i]);
		if (!ft_isum(*tmp[1]))
		{
			data->fd_2 = open(tmp[1], O_RDONLY);
			if (data->fd_2 < 0 || !check_file_name(tmp[1], "xpm"))
				ft_error("wrong file xpm\n");
			nbr = read(data->fd_2, buff, 1);
			if (nbr == 0 || nbr < 0)
				ft_error("empty xpm file");
			close(data->fd_2);
		}
		ft_free(tmp);
	}
	free (buff);
}

int	main(int ac, char **av)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (0);
	if (ac == 2)
	{
		init_data(data, av);
		ft_textures(data);
		ft_check_textures(data);
		set_colors(data);
		ft_map(data);
		close(data->fd);
		set_mlx_data(data);
		init_textures(data);
		draw_map(data);
		mlx_loop_hook(data->mlx_data->mlx, loop_hook, data);
		mlx_loop(data->mlx_data->mlx);
		ft_free(data->textures);
		ft_free(data->map);
		ft_free(data->identifier);
		ft_free(data->tab_identifier);
	}
}
