/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechoi <jechoi@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 19:01:44 by jechoi            #+#    #+#             */
/*   Updated: 2025/11/07 13:09:43 by sangseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H
/*
typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}	t_color;
*/
typedef struct s_vector
{
	double	x;
	double	y;
}	t_vector;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		w;
	int		h;
}	t_img;

typedef struct s_texture
{
	char	*path;
	t_img	img;
}	t_texture;

typedef struct s_map
{
	char	**map;
	int		height;
	int		width;
	int		player_count;
	int		map_start;
}	t_map;

typedef struct s_player
{
	char	dir;
	double	plane;
	double	x;
	double	y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	double	move_spd;
	double	rot_spd;
}	t_player;

typedef struct s_file
{
	char	**file;
	int		height;
	int		width;
	int		line_count;
	int		read_count;
}	t_file;

typedef struct s_assets
{
	t_texture	north;
	t_texture	south;
	t_texture	east;
	t_texture	west;
	unsigned int			ceil_rgb;
	unsigned int			floor_rgb;
	int			has_ceiling;
	int			has_floor;
}	t_assets;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	t_img		fb;
	int			win_height;
	int			win_width;
	t_file		file;
	t_map		map;
	t_assets	asset;
	t_player	player;
	int			keys[515];
	int			running;

}	t_data;

#endif
