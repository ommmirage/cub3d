#include <stdio.h>
#include <stdlib.h>
#include "minilibx_linux/mlx.h"
#include "structs.h"

void	pixel_put(t_img *img, int x, int y, int color)
{
	int 	offset;
	char	*dst;

	offset = y * img->line_length + x * (img->bits_per_pixel / 8);
	dst = img->addr + offset;
	*(unsigned int*)dst = color;
}

int 	key_hook(int keycode, t_data *data)
{
	if (keycode == 65307)
		mlx_destroy_window(data->mlx, data->win);
	printf("%d\n", keycode);
	return (0);
}

int 	mouse_hook(int button, int x, int y)
{
	printf("%d x=%d, y=%d\n", button, x , y);
	return (0);
}

void	draw_h_line(t_data *data, int len, int width)
{
	int	x;
	int y;

	x = 0;
	while (x < len)
	{
		y = 0;
		while (y < width)
			pixel_put(data->img, x, y++, 0x00FFFF00);
		x++;
	}
}

void	draw_cross(t_data *data)
{
	data->img->img = mlx_new_image(data->mlx, 400, 300);
	data->img->addr = mlx_get_data_addr(data->img->img,
										&data->img->bits_per_pixel,
										&data->img->line_length,
										&data->img->endian);
	draw_h_line(data, 15, 3);
	mlx_put_image_to_window(data->mlx, data->win, data->img->img, 0, 15);

}

int 	render_next_frame(t_data *data)
{
	draw_cross(data);

	mlx_destroy_image(data->mlx, data->img->img);
	return (0);
}

int		main()
{
	t_data	data;

	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, 1000, 700, "Cub3d");

	mlx_key_hook(data.win, key_hook, &data);

	mlx_hook(data.win, 04, 1L << 2, mouse_hook, data.mlx);

	mlx_loop_hook(data.mlx, render_next_frame, &data);
	mlx_loop(data.mlx);
}

