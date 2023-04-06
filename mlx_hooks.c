/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasabir <hasabir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 18:56:51 by hasabir           #+#    #+#             */
/*   Updated: 2023/04/05 15:29:32 by hasabir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	key_hook_destroy(int key, t_mlx *mlx_data)
{
	if (key == 53)
	{
		mlx_destroy_window(mlx_data->mlx, mlx_data->mlx_win);
		mlx_data->mlx_win = NULL;
		exit (EXIT_SUCCESS);
	}
	return (0);
}

int	key_hook(int key, t_data *data)
{
	if (key == 2)
		data->mlx_data->key_state.west = 1;
	if (key == 0)
		data->mlx_data->key_state.east = 1;
	if (key == 1)
		data->mlx_data->key_state.south = 1;
	if (key == 13)
		data->mlx_data->key_state.north = 1;
	if (key == 123)
		data->mlx_data->key_state.trigonometric_rotation = 1;
	if (key == 124)
		data->mlx_data->key_state.clockwise_rotation = 1;
	speed_control(key, data);
	key_hook_destroy(key, data->mlx_data);
	return (0);
}

int	key_release(int key, t_data *data)
{
	if (key == 2)
		data->mlx_data->key_state.west = 0;
	if (key == 0)
		data->mlx_data->key_state.east = 0;
	if (key == 1)
		data->mlx_data->key_state.south = 0;
	if (key == 13)
		data->mlx_data->key_state.north = 0;
	if (key == 123)
		data->mlx_data->key_state.trigonometric_rotation = 0;
	if (key == 124)
		data->mlx_data->key_state.clockwise_rotation = 0;
	return (0);
}

int	mouse_hook(int mouse_button, int x, int y, t_data *data)
{
	(void)x;
	(void)y;
	if (mouse_button == 4 || mouse_button == 5
		|| mouse_button == 1 || mouse_button == 2)
	{
		if (mouse_button == 5)
			rotate_player(data, WEST);
		if (mouse_button == 4)
			rotate_player(data, EAST);
		if (mouse_button == 1)
			data->player.rotation_speed++;
		if (mouse_button == 2)
			data->player.rotation_speed--;
		mlx_clear_window(data->mlx_data->mlx, data->mlx_data->mlx_win);
		draw_map(data);
	}
	return (0);
}

int	loop_hook(t_data *data)
{
	mlx_mouse_hook(data->mlx_data->mlx_win, mouse_hook, data);
	mlx_hook(data->mlx_data->mlx_win, 2, 0, key_hook, data);
	mlx_hook(data->mlx_data->mlx_win, 3, 0, key_release, data);
	mlx_hook(data->mlx_data->mlx_win, 17, 0, destroy_window_x, data);
	move_hook(data);
	return (0);
}
