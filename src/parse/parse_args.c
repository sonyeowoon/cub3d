/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechoi <jechoi@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 20:34:35 by jechoi            #+#    #+#             */
/*   Updated: 2025/10/24 13:14:43 by jechoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	print_data(t_data *data)
{
	printf("=== t_file ===\n");
	printf("height: %d, width: %d\nline_count: %d, read_count: %d\n", data->file.height, data->file.width, data->file.line_count, data->file.read_count);
	printf("=== t_map ===\n");
	for (int i = 0; data->map.map[i]; i++)
	{
		for (int j = 0; data->map.map[i][j]; j++)
			printf("%c", data->map.map[i][j]);
		printf("\n");
	}
	printf("height: %d, width: %d, player_count: %d, map_start: %d\n", data->map.height, data->map.width, data->map.player_count, data->map.map_start);
	printf("=== t_texture ===\n");
	printf("north path: %s\n", data->texture.north);
	printf("south path: %s\n", data->texture.south);
	printf("east path: %s\n", data->texture.east);
	printf("west path: %s\n", data->texture.west);
	printf("floor: %d, %d, %d\n", data->texture.floor.r, data->texture.floor.g, data->texture.floor.b);
	printf("ceiling: %d, %d, %d\n", data->texture.ceiling.r, data->texture.ceiling.g, data->texture.ceiling.b);
}

int	parse_args(t_data *data, char **argv)
{
	if (check_file(argv[1], 1) != 0)
		return (1);
	if (read_file(argv[1], &data->file) != 0)
		return (free_file(&data->file), 1);
	if (parse_header(&data->file, &data->texture) != 0)
		return (1);
	if (extract_map(&data->file, &data->map) != 0)
		return (1);
	print_data(data);
	if (validate_map(data, &data->map) != 0)
		return (1);
	if (check_texture_path(&data->texture) != 0)
		return (1);
	return (0);
}
