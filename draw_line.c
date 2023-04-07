/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasabir <hasabir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 15:02:31 by hasabir           #+#    #+#             */
/*   Updated: 2023/04/07 11:23:55 by hasabir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	creat_coordinate(t_data *data)
{
	data->coordinate.ex = fabsl(data->coordinate.x2 - data->coordinate.x1);
	data->coordinate.ey = fabsl(data->coordinate.y2 - data->coordinate.y1);
	data->coordinate.dx = 2 * data->coordinate.ex;
	data->coordinate.dy = 2 * data->coordinate.ey;
	data->coordinate.px = data->coordinate.ex;
	data->coordinate.py = data->coordinate.ey;
	return ;
}

void	first_case(t_data *data, int xi, int yi)
{
	int	i;
	int	x1;
	int	y1;

	i = 0;
	x1 = data->coordinate.x1;
	y1 = data->coordinate.y1;
	while (i <= data->coordinate.px)
	{
		my_pixel_put(data->mlx_data, x1 * data->factor_x,
			y1 * data->factor_y, YELLOW);
		i++;
		x1 += xi;
		data->coordinate.ex -= data->coordinate.dy;
		if (data->coordinate.ex <= 0)
		{
			y1 += yi;
			data->coordinate.ex += data->coordinate.dx;
		}
	}
	return ;
}

void	second_case(t_data *data, int xi, int yi)
{
	int	i;
	int	x1;
	int	y1;

	i = 0;
	x1 = data->coordinate.x1;
	y1 = data->coordinate.y1;
	while (i <= data->coordinate.py)
	{
		my_pixel_put(data->mlx_data, x1 * data->factor_x,
			y1 * data->factor_y, YELLOW);
		i++;
		y1 += yi;
		data->coordinate.ey -= data->coordinate.dx;
		if (data->coordinate.ey <= 0)
		{
			x1 += xi;
			data->coordinate.ey += data->coordinate.dy;
		}
	}
	return ;
}

int	line_draw(t_data *data)
{	
	int	i;
	int	xi;
	int	yi;

	i = 0;
	xi = 1;
	yi = 1;
	creat_coordinate(data);
	if (data->coordinate.x1 > data->coordinate.x2)
		xi = -1;
	if (data->coordinate.y1 > data->coordinate.y2)
		yi = -1;
	if (data->coordinate.px > data->coordinate.py)
		first_case(data, xi, yi);
	else if (data->coordinate.px <= data->coordinate.py)
		second_case(data, xi, yi);
	return (0);
}