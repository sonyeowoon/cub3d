/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechoi <jechoi@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 11:31:46 by sangseo           #+#    #+#             */
/*   Updated: 2025/11/13 14:23:32 by jechoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <errno.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include <math.h>
# include <sys/time.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include "struct.h"
# include "libft.h"
# include "get_next_line.h"
# include "mlx.h"

# define WIN_HEIGHT	480
# define WIN_WIDTH	640
# define PLANE		0.66

// init
int		init_fb(t_data *data, t_img *img);
void	init_data(t_data *data);
void	init_mlx(t_data *data);
void	init_tex_img(t_data *data, t_assets *asset);
int		init_pl_vector(t_player *player, char dir);
void	init_img(t_img *img);
void	init_texture(t_texture *texture);

// parse
int		parse_args(t_data *data, char **argv);
int		check_file(char *file, int cub);
int		read_file(const char *filename, t_file *file);
int		parse_header(t_file *file, t_assets *asset);
int		set_color_rgb(t_assets *asset, char *line, int j);
int		extract_map(t_file *file, t_map *map);
int		validate_map(t_data *data, t_map *map);
int		check_map_wall(t_map *map);
int		check_texture_path(t_assets *asset);
void	parse_free_data(t_data *data);

// utils
int		is_space(char c);
int		is_space2(char c);
int		is_space_ex_newline(char c);
void	treat_err(char *str);
int		ft_iscardinal(char c1, char c2);
int		is_valid_char(char c);
void	destroy_img(t_data *d, t_img *fb, t_assets *as);
void	game_exit(t_data *d);

// render
void	draw(t_data *data);
void	render_frame(t_data *data);
void	dda(t_data *data, t_dda *dv, int x);

// hooks
int		on_loop(t_data *data);
int		on_key_press(int kc, t_data *data);
int		on_close(t_data *data);
void	move_player(t_data *d, t_player *pl, int kc);
void	rotate_player(t_player *p, int kc);

#endif
