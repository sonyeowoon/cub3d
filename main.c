/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechoi <jechoi@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 19:25:56 by jechoi            #+#    #+#             */
/*   Updated: 2025/10/24 14:20:05 by jechoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#include <stdio.h>
int background(t_data *data);
int main(int argc, char **argv)
{
	t_data data;

	if (argc != 2)
		return (print_err("argc"), 1);
	init_data(&data);
	if (parse_args(&data, argv) != 0)
		return (1);
	init_mlx(&data);
	if (background(&data))
		printf("sibal\n");
	mlx_loop(data.mlx);
	//if (raycast(&data) != 0)
	//	return (1);
	// init_textures(&data);


	
	// mlx_loop(data.mlx);
	return (0);
}
