double	get_pwd()
{
}

void	render_frame(t_data *data, t_player *p)
{
	int		x;
	double	perp_wall_dist;
	//double	camera_x;
	//double	ray_dir_x;
	//double	ray_dir_y;

	x = 0;
	while (x < data->win_width)
	{
		perp_wall_dist = get_pwd();
		//camera_x = 2 * x / double(data->win_width) - 1;
		ray_dir_x = p->dir_x + p->plane_x * (2 * x / double(data->win_width) - 1);
		ray_dir_y = p->dir_y + p->plane_y * (2 * x / double(data->win_width) - 1);
		x++;
	}
}
