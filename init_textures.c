/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasabir <hasabir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 06:59:46 by kadjane           #+#    #+#             */
/*   Updated: 2023/04/05 14:57:46 by hasabir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	*get_data_addr(t_img *image)
{
	return (mlx_get_data_addr(image->mlx_img, &image->bpp, &image->line_len,
			&image->endian));
}

void	init_img_addr(t_data *data)
{
	char	**path;
	int		i;

	i = -1;
	while (data->textures[++i])
	{
		path = ft_split_textures(data->textures[i]);
		if (!ft_strcmp(path[0], "NO"))
			data->mlx_data->no_image->img_addr
				= get_data_addr(data->mlx_data->no_image);
		else if (!ft_strcmp(path[0], "SO"))
			data->mlx_data->so_image->img_addr
				= get_data_addr(data->mlx_data->so_image);
		else if (!ft_strcmp(path[0], "EA"))
			data->mlx_data->ea_image->img_addr
				= get_data_addr(data->mlx_data->ea_image);
		else if (!ft_strcmp(path[0], "WE"))
			data->mlx_data->we_image->img_addr
				= get_data_addr(data->mlx_data->we_image);
		ft_free(path);
	}
}

void	init_mlx_img(t_data *data)
{
	char	**path;
	int		i;

	i = -1;
	while (data->textures[++i])
	{
		path = ft_split_textures(data->textures[i]);
		if (!ft_strcmp(path[0], "NO"))
			data->mlx_data->no_image->mlx_img = mlx_xpm_file_to_image
				(data->mlx_data->mlx, path[1],
					&data->mlx_data->block_x, &data->mlx_data->block_y);
		else if (!ft_strcmp(path[0], "SO"))
			data->mlx_data->so_image->mlx_img = mlx_xpm_file_to_image
				(data->mlx_data->mlx, path[1],
					&data->mlx_data->block_x, &data->mlx_data->block_y);
		else if (!ft_strcmp(path[0], "EA"))
			data->mlx_data->ea_image->mlx_img = mlx_xpm_file_to_image
				(data->mlx_data->mlx, path[1],
					&data->mlx_data->block_x, &data->mlx_data->block_y);
		else if (!ft_strcmp(path[0], "WE"))
			data->mlx_data->we_image->mlx_img = mlx_xpm_file_to_image
				(data->mlx_data->mlx, path[1],
					&data->mlx_data->block_x, &data->mlx_data->block_y);
		ft_free(path);
	}
}

void	init_textures(t_data *data)
{
	data->mlx_data->no_image = malloc(sizeof(t_img));
	if (!data->mlx_data->no_image)
		exit(EXIT_FAILURE);
	data->mlx_data->so_image = malloc(sizeof(t_img));
	if (!data->mlx_data->so_image)
		exit(EXIT_FAILURE);
	data->mlx_data->we_image = malloc(sizeof(t_img));
	if (!data->mlx_data->we_image)
		exit(EXIT_FAILURE);
	data->mlx_data->ea_image = malloc(sizeof(t_img));
	if (!data->mlx_data->ea_image)
		exit(EXIT_FAILURE);
	init_mlx_img(data);
	init_img_addr(data);
}

unsigned int	get_color(t_data *data, int offset_x, int offset_y, int flag)
{
	char	*dst;

	dst = NULL;
	if (offset_x < 0 || offset_x >= 40 || offset_y < 0 || offset_y >= 40)
		return (0);
	if (flag == SOUTH)
		dst = data->mlx_data->so_image->img_addr + (
				offset_y * data->mlx_data->so_image->line_len
				+ offset_x * (data->mlx_data->so_image->bpp / 8));
	else if (flag == NORTH)
		dst = data->mlx_data->no_image->img_addr + (
				offset_y * data->mlx_data->no_image->line_len
				+ offset_x * (data->mlx_data->no_image->bpp / 8));
	else if (flag == WEST)
		dst = data->mlx_data->we_image->img_addr + (
				offset_y * data->mlx_data->we_image->line_len
				+ offset_x * (data->mlx_data->we_image->bpp / 8));
	else if (flag == EAST)
		dst = data->mlx_data->ea_image->img_addr + (
				offset_y * data->mlx_data->ea_image->line_len
				+ offset_x * (data->mlx_data->ea_image->bpp / 8));
	return (*(unsigned int *)dst);
}
