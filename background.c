#include "cub3d.h"

int	background(t_data *data)
{
	data->fb.img = mlx_new_image(data->mlx, data->win_width, data->win_height);
	if (data->fb.img == NULL)
		return (1);
	data->fb.addr = mlx_get_data_addr(data->fb.img, &data->fb.bpp, &data->fb.line_len, &data->fb.endian);

	return (0);
}
