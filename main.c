/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechoi <jechoi@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 19:25:56 by jechoi            #+#    #+#             */
/*   Updated: 2025/11/13 16:19:26 by jechoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_data	d;

	if (argc != 2)
		return (treat_err("argc"), 1);
	init_data(&d);
	if (parse_args(&d, argv) != 0)
		return (parse_free_data(&d), 1);
	init_mlx(&d);
	if (init_fb(&d, &d.fb) == 1)
		return (game_exit(&d), treat_err("fb"), 1);
	if (init_tex_img(&d, &d.asset) != 0)
		return (game_exit(&d), treat_err("tex_img"), 1);
	if (init_pl_vector(&d.player, d.player.dir) == 1)
	{
		printf("%f %f\n", d.player.x, d.player.y);
		printf("init_pl_vector error\n");
	}
	draw(&d);
	mlx_hook(d.win, 2, 1L << 0, on_key_press, &d);
	mlx_hook(d.win, 17, 0, on_close, &d);
	mlx_loop_hook(d.mlx, on_loop, &d);
	mlx_loop(d.mlx);
	game_exit(&d);
	return (0);
}
