/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasabir <hasabir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 15:23:53 by hasabir           #+#    #+#             */
/*   Updated: 2023/04/05 15:32:49 by hasabir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	move_u_d(t_data *data, double player_x, double player_y, int direction)
{
	long double	next_player_y;
	long double	next_player_x;

	if (data->map[(int)(player_y / 40)]
		[(int)(data->coordinate.x1 / 40)] != '1')
	{
		next_player_y = player_y + (direction * (-1)) * 20
			* sin(data->player.angle);
		if (data->map[(int)(next_player_y / 40)]
			[(int)(data->coordinate.x1 / 40)] != '1')
			data->coordinate.y1 = player_y;
	}
	if (data->map[(int)(data->coordinate.y1 / 40)]
		[(int)(player_x / 40)] != '1')
	{
		next_player_x = player_x + (direction * 20 * cos(data->player.angle));
		if (data->map[(int)(data->coordinate.y1 / 40)]
			[(int)(next_player_x / 40)] != '1')
			data->coordinate.x1 = player_x;
	}
}

void	move_w_e(t_data *data, double player_x, double player_y, int direction)
{
	long double	next_player_y;
	long double	next_player_x;

	if (data->map[(int)(player_y / 40)]
		[(int)(data->coordinate.x1 / 40)] != '1')
	{
		next_player_y = player_y + (direction * (-1)) * 20
			* sin(data->player.angle + M_PI / 2);
		if (data->map[(int)(next_player_y / 40)]
			[(int)(data->coordinate.x1 / 40)] != '1')
			data->coordinate.y1 = player_y;
	}
	if (data->map[(int)(data->coordinate.y1 / 40)]
		[(int)(player_x / 40)] != '1')
	{
		next_player_x = player_x + direction * 20
			* cos(data->player.angle + M_PI / 2);
		if (data->map[(int)(data->coordinate.y1 / 40)]
			[(int)(next_player_x / 40)] != '1')
			data->coordinate.x1 = player_x;
	}
}
