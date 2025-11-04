/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechoi <jechoi@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 03:29:56 by jechoi            #+#    #+#             */
/*   Updated: 2025/10/24 12:09:49 by jechoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	get_rgb(unsigned int *bg, char *line)
{
	char	**colors;
	int		i;
	int		c[3];

	while (is_space(*line))
		line++;
	colors = ft_split(line, ',');
	i = 0;
	while (colors[i])
		i++;
	if (i != 3)
		return (treat_err("rgb error"), -1);
		// return (free_arr(colors), treat_err("rgb error"), -1);
	c[0] = ft_atoi(colors[0]);
	c[1] = ft_atoi(colors[1]);
	c[2] = ft_atoi(colors[2]);
	if (!(c[0] >= 0 && c[0] <= 255 && c[1] >= 0 && c[1] <= 255 && c[2] >= 0 && c[2] <= 255))
		return (-1);
	if (c[0] == -1 || c[1] == -1 || c[2] == -1)
		return (-1);
	*bg = ((c[0] << 16) | (c[1] << 8) | c[2]);
	return (1);
}

int	set_color_rgb(t_assets *asset, char *line, int j)
{
	if (line[j + 1] && line[j + 1] != ' ' && line[j + 1] != '\t')
		return 1;
	if (line[j] == 'F' && asset->has_floor == 0)
	{
		asset->has_floor = get_rgb(&asset->floor_rgb, &line[j + 2]);
		if (asset->has_floor == -1)
			return (treat_err("floor rgb error"), 1);
	}
	else if (line[j] == 'C' && asset->has_ceiling == 0)
	{
		asset->has_ceiling = get_rgb(&asset->ceil_rgb, &line[j + 2]);
		if (asset->has_ceiling == -1)
			return (treat_err("ceiling rgb error"), 1);
	}
	else
		return (treat_err("rgb error"), 1);
	return (0);
}
