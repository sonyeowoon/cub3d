/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechoi <jechoi@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 09:21:38 by jechoi            #+#    #+#             */
/*   Updated: 2025/11/13 14:40:32 by jechoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	free_asset(t_assets *asset)
{
	if (asset->north.path)
		free(asset->north.path);
	if (asset->south.path)
		free(asset->south.path);
	if (asset->east.path)
		free(asset->east.path);
	if (asset->west.path)
		free(asset->west.path);
}

void	parse_free_data(t_data *data)
{
	int	i;

	if (data->map.map)
	{
		i = -1;
		while (data->map.map[++i])
			free(data->map.map[i]);
		free(data->map.map);
	}
	if (data->file.file)
	{
		i = -1;
		while (data->file.file[++i])
			free(data->file.file[i]);
		free(data->file.file);
	}
	free_asset(&data->asset);
}
