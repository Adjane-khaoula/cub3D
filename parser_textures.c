/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_textures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadjane <kadjane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 16:29:05 by kadjane           #+#    #+#             */
/*   Updated: 2023/03/09 19:41:50 by kadjane          ###   ########.fr       */
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
			{
				printf("ERROR : duplicate texture\n");
				exit (1);
			}
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
		if (ft_atoi(tab_rgb[i]) < 0 || ft_atoi(tab_rgb[i]) > 255 )
		{
			printf("ERROR : false color\n");
			exit (1);
		}
	}
}

void	check_Ceiling_Floor(char *line)
{
	char	**tab_rgb;
	int		i;
	int		j;

	i = -1;
	j = 0;
	while (line[++i])
	{
		if (line[i] == ',')
			j++;
	}
	// printf("****> j == %d \n", j);
	// printf("****> j == {%s} \n", line);
	tab_rgb = ft_split(line, ',');
	// printf("tab_rgb == %d\n", len_tab(tab_rgb));
	// printf("tab_rgb == {%s}\n", tab_rgb[0]);
	// printf("tab_rgb == {%s}\n", tab_rgb[1]);
	// printf("tab_rgb == {%s}\n", tab_rgb[2]);
	// printf("tab_rgb == {%s}\n", tab_rgb[3]);
	if (len_tab(tab_rgb) != 3 || j != 2)
	{
		printf("ERROR : color is incorrect\n");
		exit(1);
	}
	else
		check_range_rgb(tab_rgb);
}

// char	**parse_texture(char *texture, char **identifier, char **tab_identifier)
void	parse_texture(t_data **data)
{
	char	**line;
	char	*texture;
	int		i;

	i = -1;
	texture = *(*data)->line;
	if (texture)
	{
		while (is_whitespace(*texture))
		// {
			texture++;
			// printf ("-----------------%c\n", *texture);
		// }
		// printf("**********%s\n", texture);
		line = ft_split_textures(texture);
		printf("line in texture == line[0] = %s\n", line[0]);
		printf("line in texture == line[1] = %s\n", line[1]);
		printf("line in texture == line[2] = %s\n", line[2]);
		if (len_tab(line) != 2)
		{
			printf("ERROR\n");
			exit(1);
		}
		while (++i < 6)
		{
			if (!ft_strcmp(*line,((*data)->identifier)[i]))
			{
				(*data)->tab_identifier = check_dup((*data)->tab_identifier, *line);
				if (!ft_strcmp(*line,"F") || !ft_strcmp(*line,"C"))
					check_Ceiling_Floor(*(line + 1));
				break ;
			}
		}
		if (i == 6)
		{
			printf("ERROR : identifier not exist \n");
			exit (1);
		}
	}
}
