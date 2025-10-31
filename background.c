#include "cub3d.h"

int	background(t_data *data)
{
	data->img.bg_img_ptr = mlx_new_image(data->mlx, data->win_width, data->win_height);
	if (data->img.bg_img_ptr == NULL)
		return (1);
	data->img.bg_addr = mlx_get_data_addr(data->img.bg_img_ptr, data->img.bg_bpp, data->img.bg_sl, data->img.bg_endian);

	return (0);
}
