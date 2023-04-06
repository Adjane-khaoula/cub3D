/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randring_wall.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadjane <kadjane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 11:43:13 by kadjane           #+#    #+#             */
/*   Updated: 2023/04/05 22:15:49 by kadjane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	rendering_wall_3(t_data *data, int offset_x, int offset_y, int i)
{
	long double	start;

	start = (data->walls->height / 2)
		- (data->walls->height_wall / 2);
	while (data->walls->start < data->walls->end)
	{
		offset_y = (data->walls->start - start)
			* (float)(40 / data->walls->height_wall);
		if (data->ray.flag_h_v
			&& data->coordinate.y1 < data->coordinate.y2)
			my_pixel_put(data->mlx_data, i, data->walls->start++,
				get_color(data, offset_x, offset_y, SOUTH));
		else if (data->ray.flag_h_v
			&& data->coordinate.y1 >= data->coordinate.y2)
			my_pixel_put(data->mlx_data, i, data->walls->start++,
				get_color(data, offset_x, offset_y, NORTH));
		else if (!data->ray.flag_h_v
			&& data->coordinate.x1 >= data->coordinate.x2)
			my_pixel_put(data->mlx_data, i, data->walls->start++,
				get_color(data, offset_x, offset_y, WEST));
		else if (!data->ray.flag_h_v
			&& data->coordinate.x1 < data->coordinate.x2)
			my_pixel_put(data->mlx_data, i, data->walls->start++,
				get_color(data, offset_x, offset_y, EAST));
	}
}

void	rendering_wall_2(int i, t_data *data)
{
	int	j;
	int	offset_x;
	int	offset_y;

	j = -1;
	offset_y = 0;
	while (++j < data->walls->start)
		my_pixel_put(data->mlx_data, i, j, data->color->c_ceiling);
	if (data->ray.flag_h_v)
		offset_x = (int)data->ray.x2_horizontal % 40;
	else
		offset_x = (int)data->ray.y2_vertical % 40;
	rendering_wall_3(data, offset_x, offset_y, i);
	while (data->walls->end < data->walls->height)
		my_pixel_put(data->mlx_data, i,
			data->walls->end++, data->color->c_floor);
}

void	rendering_wall(long double ray_distance, t_data *data)
{
	static int	i = -1;

	data->walls->height_2_d = 40;
	data->walls->width = data->mlx_data->window_width;
	data->walls->height = data->mlx_data->window_hight;
	if (i == data->walls->width - 1)
		i = -1;
	data->walls->dist_3_d = (data->walls->width / 2) / tan(M_PI / 6);
	data->walls->height_wall = ((data->walls->height_2_d / ray_distance)
			* data->walls->dist_3_d);
	data->walls->start = (data->walls->height / 2)
		- (data->walls->height_wall / 2);
	if (data->walls->start < 0)
		data->walls->start = 0;
	data->walls->end = data->walls->start + data->walls->height_wall;
	if (data->walls->end > data->walls->height)
		data->walls->end = data->walls->height;
	if ((++i) < data->walls->width)
		rendering_wall_2(i, data);
}
