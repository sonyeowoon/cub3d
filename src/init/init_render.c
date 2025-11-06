#include "cub3d.h"

int	init_fb(t_data *data, t_img *img)
{
	img->img = mlx_new_image(data->mlx, data->win_width, data->win_height);
	if (img->img == NULL)
		return (1);
	img->addr = mlx_get_data_addr(img->img, &img->bpp, &img->line_len, &img->endian);
	return (0);
}

static void	set_dir(char dir, double *x, double *y)
{
	if (dir == 'N')
	{
		*x = 0.0;
		*y = -1.0;
	}
	else if (dir == 'S')
	{
		*x = 0.0;
		*y = 1.0;
	}
	else if (dir == 'E')
	{
		*x = 1.0;
		*y = 0.0;
	}
	else if (dir == 'W')
	{
		*x = -1.0;
		*y = 0.0;
	}
}

int	init_pl_vector(t_player *player, char dir)
{
	if (dir != 'N' && dir != 'S' && dir != 'E' && dir != 'W')
		return (1);
	set_dir(dir, &player->dir_x, &player->dir_y);
	player->plane_x = -(player->dir_y) * player->plane;
	player->plane_y = player->dir_x * player->plane;
	return (0);
}
