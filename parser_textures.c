/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_textures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasabir <hasabir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 16:29:05 by kadjane           #+#    #+#             */
/*   Updated: 2023/04/02 03:44:59 by hasabir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	set_color_ceiling(t_data *data)
{
	data->color->c_red = ft_atoi(data->color->rgb_ceiling[0]);
	data->color->c_green = ft_atoi(data->color->rgb_ceiling[1]);
	data->color->c_blue = ft_atoi(data->color->rgb_ceiling[2]);
	data->color->c_ceiling
		= data->color->c_red << 16
		| data->color->c_green << 8 | data->color->c_blue;
}

void	set_colors(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	while (data->textures && data->textures[++i])
	{
		j = -1;
		while (is_whitespace(data->textures[i][++j]))
			;
		if (data->textures[i][j] == 'F')
		{
			data->color->f_red = ft_atoi(data->color->rgb_floor[0]);
			data->color->f_green = ft_atoi(data->color->rgb_floor[1]);
			data->color->f_blue = ft_atoi(data->color->rgb_floor[2]);
			data->color->c_floor
				= data->color->f_red << 16
				| data->color->f_green << 8 | data->color->f_blue;
		}
		else
			set_color_ceiling(data);
	}
}

char	**split_texture(char *textures)
{
	char	**line;

	line = ft_split_textures(textures);
	if (len_tab(line) != 2)
		ft_error("textures not correct\n");
	return (line);
}

int	parse_textures_2(char **line, t_data **data)
{
	int	i;

	i = -1;
	while (++i < 6)
	{
		if (line && !ft_strcmp(*line, ((*data)->identifier)[i]))
		{
			(*data)->tab_identifier
				= check_dup((*data)->tab_identifier, *line);
			if (!ft_strcmp(*line, "F") || !ft_strcmp(*line, "C"))
				check_ceiling_floor((line), *data);
			break ;
		}
	}
	return (i);
}

void	parse_texture(t_data **data)
{
	char	**line;
	char	*texture;
	int		i;

	i = -1;
	line = NULL;
	texture = *(*data)->line;
	if (texture)
	{
		while (is_whitespace(*texture))
			texture++;
		line = split_texture(texture);
		i = parse_textures_2(line, data);
		if (i == 6)
			ft_error("identifier not exist \n");
	}
	ft_free(line);
}
