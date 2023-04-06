/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_textures_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasabir <hasabir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 19:23:12 by kadjane           #+#    #+#             */
/*   Updated: 2023/04/02 03:45:38 by hasabir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	len_tab(char **tab_identifier)
{
	int	i;

	i = 0;
	while (tab_identifier[i])
		i++;
	return (i);
}

char	**add_identifier(char **tab_identifier, char *identifier)
{
	char	**tmp;
	int		i;

	i = -1;
	tmp = malloc(sizeof(char *) * (len_tab(tab_identifier) + 2));
	if (!tmp)
		return (NULL);
	while (tab_identifier[++i])
	{
		tmp[i] = ft_strdup(tab_identifier[i]);
		free(tab_identifier[i]);
		tab_identifier[i] = NULL;
	}
	tmp[i++] = ft_strdup(identifier);
	tmp[i] = NULL;
	free (tab_identifier);
	return (tmp);
}

char	**check_dup(char **tab_identifier, char *identifier)
{
	int		i;

	i = -1;
	if (!tab_identifier)
	{
		tab_identifier = malloc(sizeof(char *) * 2);
		tab_identifier[0] = ft_strdup(identifier);
		tab_identifier[1] = NULL;
	}
	else
	{
		while (tab_identifier[++i])
		{
			if (!ft_strcmp(tab_identifier[i], identifier))
				ft_error("duplicate texture\n");
		}
		if (!tab_identifier[i])
			tab_identifier = add_identifier(tab_identifier, identifier);
	}
	return (tab_identifier);
}

void	check_range_rgb(char **tab_rgb)
{
	int	i;

	i = -1;
	while (tab_rgb[++i])
	{
		if (ft_atoi(tab_rgb[i]) < 0 || ft_atoi(tab_rgb[i]) > 255)
			ft_error("rang not correct\n");
	}
}

void	check_ceiling_floor(char **line, t_data *data)
{
	char	**tab_rgb;
	int		i;
	int		j;

	i = -1;
	j = 0;
	while (line[1][++i])
	{
		if (line[1][i] == ',')
			j++;
	}
	tab_rgb = ft_split(line[1], ',');
	if (len_tab(tab_rgb) != 3 || j != 2)
		ft_error("number of rgb not correct\n");
	else
		check_range_rgb(tab_rgb);
	i = -1;
	while (is_whitespace(line[0][++i]))
		;
	if (line[0][i] == 'F')
		data->color->rgb_floor = tab_rgb;
	else
		data->color->rgb_ceiling = tab_rgb;
}
