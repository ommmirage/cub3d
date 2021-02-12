#include <stdio.h>
#include "minilibx_linux/mlx.h"

typedef struct s_data
{
	void	*img;
	char	*addr;
	int 	bits_per_pixel;
	int 	line_length;
	int 	endian;
}			t_data;

void	pixel_put(t_data *data, int x, int y, int color)
{
	int 	offset;
	char	*dst;

	offset = y * data->line_length + x * (data->bits_per_pixel / 8);
	dst = data->addr + offset;
	*(unsigned int*)dst = color;
}

int		main()
{
    void	*mlx;
    void	*mlx_win;
    t_data	img;

    mlx = mlx_init();
    mlx_win = mlx_new_window(mlx, 1000, 1000, "Hello world!");
	img.img = mlx_new_image(mlx, 1000, 1000);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
							  &img.line_length, &img.endian);
	pixel_put(&img, 5, 5, 0x0000FF00);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}

