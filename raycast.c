#include "cub3d.h"

int	raycast(t_data *data)
{
	double	pos_x = 5.0, pos_y = 1.0;
	double	dir_x = 1.0, dir_y = 0.0;
	double	plane_x = 0.0, plane_y = 0.66;

	double	time = 0;
	double	oldTime = 0;

	double	texWidth;
	double	texHeight;
	// 스크린 버퍼 생성
	// 텍스처 저장
	init_texture(data);
}
