/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangseo <sangseo@student.42gyeongsan.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 22:57:27 by sangseo           #+#    #+#             */
/*   Updated: 2025/11/12 22:57:59 by sangseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	on_loop(t_data *data)
{
	if (!data->running)
		return (0);
	draw(data);
	return (0);
}

int	on_key_press(int kc, t_data *data)
{
	if (kc < 256 && ft_strchr("wsad", kc))
		move_player(data, &data->player, kc);
	if (kc == 65361 || kc == 65363)
		rotate_player(&data->player, kc);
	draw(data);
	if (kc == 65307)
	{
		data->keys[514] = 1;
		on_close(data);
	}
	return (0);
}

int	on_key_release(int kc, t_data *data)
{
	if (kc >= 0 && kc < 512)
		data->keys[kc] = 0;
	if (kc == 65361)
		data->keys[512] = 0;
	if (kc == 65363)
		data->keys[513] = 0;
	if (kc == 65307)
		data->keys[514] = 0;
	return (0);
}

int	on_close(t_data *data)
{
	data->running = 0;
	if (data->win)
	{
		mlx_destroy_window(data->mlx, data->win);
		data->win = NULL;
	}
	return (0);
}
