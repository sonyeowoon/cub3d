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

static int	get_rgb(t_color *color, char *line)
{
	char	**colors;
	int		i;

	while (is_space(*line))
		line++;
	colors = ft_split(line, ',');
	i = 0;
	while (colors[i])
		i++;
	if (i != 3)
		return (treat_err("rgb error"), -1);
		// return (free_arr(colors), treat_err("rgb error"), -1);
	color->r = ft_atoi(colors[0]);
	if (color->r == -1 || !(color->r >= 0 && color->r<= 255))
		return (-1);
	color->g = ft_atoi(colors[1]);
	if (color->g == -1 || !(color->g >= 0 && color->g <= 255))
		return (-1);
	color->b = ft_atoi(colors[2]);
	if (color->b == -1 || !(color->b >= 0 && color->b <= 255))
		return (-1);
	return (1);	
}

int	set_color_rgb(t_texture *texture, char *line, int j)
{
	if (line[j + 1] && line[j + 1] != ' ' && line[j + 1] != '\t')
		return 1;
	if (line[j] == 'F' && texture->has_floor == 0)
	{
		texture->has_floor = get_rgb(&texture->floor, &line[j + 2]);
		if (texture->has_floor == -1)
			return (treat_err("floor rgb error"), 1);
	}
	else if (line[j] == 'C' && texture->has_ceiling == 0)
	{
		texture->has_ceiling = get_rgb(&texture->ceiling, &line[j + 2]);
		if (texture->has_ceiling == -1)
			return (treat_err("ceiling rgb error"), 1);
	}
	else
		return (treat_err("rgb error"), 1);
	return (0);
}
