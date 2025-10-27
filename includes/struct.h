/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechoi <jechoi@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 19:01:44 by jechoi            #+#    #+#             */
/*   Updated: 2025/10/24 14:06:48 by jechoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}	t_color;

typedef struct s_texture
{
	char	*north;
	char	*south;
	char	*east;
	char	*west;
	t_color	floor;
	t_color	ceiling;
	int		has_floor;
	int		has_ceiling;
}	t_texture;

typedef struct s_img
{
	void	*north;
	void	*south;
	void	*east;
	void	*west;
}	t_img;

typedef struct s_map
{
	char	**map;
	int		height;
	int		width;
	int		player_count;
	int		map_start;
}	t_map;

typedef	struct s_player
{
	char	dir;
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
}	t_player;

typedef struct s_file
{
	char	**file;
	int		height;
	int		width;
	int		line_count;
	int		read_count;
}	t_file;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	int			win_height;
	int			win_width;
	t_file		file;
	t_map		map;
	t_texture	texture;
	t_img		img;
	t_player	player;

}	t_data;

#endif
