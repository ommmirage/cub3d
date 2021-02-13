#include <stdio.h>
#include <stdlib.h>
#include "minilibx_linux/mlx.h"
#include "cub3d.h"

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

int 	render_next_frame(t_data *data)
{
	draw_cross(data);
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

