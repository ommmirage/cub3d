#include <stdio.h>
#include "minilibx_linux/mlx.h"

typedef struct s_img
{
	void	*img;
	char	*addr;
	int 	bits_per_pixel;
	int 	line_length;
	int 	endian;
}			t_img;

typedef struct	s_data
{
	void	*mlx;
	void	*win;
	t_img	*img;
}				t_data;

void	pixel_put(t_img *img, int x, int y, int color)
{
	int 	offset;
	char	*dst;

	offset = y * img->line_length + x * (img->bits_per_pixel / 8);
	dst = img->addr + offset;
	*(unsigned int*)dst = color;
}

int 	key_hook(int keycode, t_data *mlx)
{
	if (keycode == 65307)
		mlx_destroy_window(mlx->mlx, mlx->win);
	printf("%d\n", keycode);
	return (0);
}

int 	mouse_hook(int button, int x, int y)
{
	printf("%d x=%d, y=%d\n", button, x , y);
	return (0);
}

int 	render_next_frame(t_data *data)
{
	data->img->img = mlx_new_image(data->mlx, 400, 300);
	data->img->addr = mlx_get_data_addr(data->img->img,
									 &data->img->bits_per_pixel,
									 &data->img->line_length,
									 &data->img->endian);
	pixel_put(data->img, 5, 5, 0x0000FF00);
	mlx_put_image_to_window(data->mlx, data->win, data->img->img, 0, 0);
	return (0);
}

int		main()
{
	t_data	data;

	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, 400, 300, "Hello world!");

	mlx_key_hook(data.win, key_hook, &data);

	mlx_hook(data.win, 04, 1L << 2, mouse_hook, data.mlx);

	mlx_loop_hook(data.mlx, render_next_frame, &data);
	mlx_loop(data.mlx);
}

