/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechoi <jechoi@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 07:28:52 by jechoi            #+#    #+#             */
/*   Updated: 2025/10/23 07:35:03 by jechoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_texture_path(t_assets *asset)
{
	if (check_file(asset->north.path, 0) != 0)
		return (1);
	if (check_file(asset->south.path, 0) != 0)
		return (1);
	if (check_file(asset->west.path, 0) != 0)
		return (1);
	if (check_file(asset->east.path, 0) != 0)
		return (1);
	return (0);
}
