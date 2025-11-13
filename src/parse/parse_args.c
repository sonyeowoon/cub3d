/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechoi <jechoi@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 20:34:35 by jechoi            #+#    #+#             */
/*   Updated: 2025/11/13 14:38:34 by jechoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	parse_args(t_data *data, char **argv)
{
	if (check_file(argv[1], 1) != 0)
		return (1);
	if (read_file(argv[1], &data->file) != 0)
		return (1);
	if (parse_header(&data->file, &data->asset) != 0)
		return (1);
	if (extract_map(&data->file, &data->map) != 0)
		return (1);
	if (validate_map(data, &data->map) != 0)
		return (1);
	if (check_texture_path(&data->asset) != 0)
		return (1);
	return (0);
}
