#include "cub3d.h"

void	init_img(t_img *img)
{
	img->img = NULL;
	img->addr = NULL;
	img->bpp = 0;
	img->line_len = 0;
	img->endian = 0;
	img->w = 0;
	img->h = 0;
}

void	init_texture(t_texture *texture)
{
	texture->path = NULL;
	init_img(&texture->img);
}
