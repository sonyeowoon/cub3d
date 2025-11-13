/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechoi <jechoi@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 19:25:56 by jechoi            #+#    #+#             */
/*   Updated: 2025/11/13 13:05:50 by jechoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#include <stdio.h>
int main(int argc, char **argv)
{
	t_data data;

	if (argc != 2)
		return (treat_err("argc"), 1);
	init_data(&data);
	if (parse_args(&data, argv) != 0)
		return (parse_free_data(&data), 1);
	init_mlx(&data);
	if (init_fb(&data, &data.fb))
		printf("\n");
	init_tex_img(&data, &data.asset);
	if (init_pl_vector(&data.player, data.player.dir) == 1)
	{
		printf("%f %f\n", data.player.x, data.player.y);
		printf("init_pl_vector error\n");
	}
	draw(&data);
	mlx_hook(data.win, 2, 1L<<0, on_key_press, &data);
	mlx_hook(data.win, 17, 0, on_close, &data);
	mlx_loop_hook(data.mlx, on_loop, &data);
	mlx_loop(data.mlx);
	game_exit(&data);
	return (0);
}
