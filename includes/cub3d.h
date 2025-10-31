#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <errno.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/time.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include "struct.h"
# include "libft.h"
# include "get_next_line.h"
# include "mlx.h"

# define WIN_HEIGHT	480
# define WIN_WIDTH	640

// init
void	init_data(t_data *data);
void	init_mlx(t_data *data);
//void	init_texture(t_data *data);

// parse
int		parse_args(t_data *data, char **argv);
int		check_file(char *file, int cub);
int		read_file(const char *filename, t_file *file);
int		parse_header(t_file *file, t_texture *texture);
int		set_color_rgb(t_texture *texture, char *line, int j);
int		extract_map(t_file *file, t_map *map);
int		validate_map(t_data *data, t_map *map);
int		check_map_wall(t_map *map);
int		check_texture_path(t_texture *texture);
void	free_file(t_file *file);

// utils
int		is_space(char c);
int		is_space2(char c);
int		is_space_ex_newline(char c);
void	print_err(char *str);
void	treat_err(char *str);


#endif
