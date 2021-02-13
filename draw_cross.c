//
// Created by sergey on 13.02.2021.
//

#include "cub3d.h"
#include "minilibx_linux/mlx.h"

void	draw_cross(t_data *data)
{
	data->img->img = mlx_new_image(data->mlx, 400, 300);
	data->img->addr = mlx_get_data_addr(data->img->img,
										&data->img->bits_per_pixel,
										&data->img->line_length,
										&data->img->endian);
	draw_h_line(data, 10, 3, 0, 15, 0x00FFFF00);
	draw_v_line(data, 10, 3, 15, 0, 0x00FFFF00);
	draw_h_line(data, 10, 3, 23, 15, 0x00FFFF00);
	draw_v_line(data, 10, 3, 15, 23, 0x00FFFF00);
	mlx_put_image_to_window(data->mlx, data->win, data->img->img, 0, 0);
	mlx_destroy_image(data->mlx, data->img->img);
}
