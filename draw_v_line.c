//
// Created by sergey on 13.02.2021.
//

#include "cub3d.h"

void	draw_v_line(t_data *data, int len, int width, int x, int y1, int color)
{
	int y;

	len += y1;
	width += x;
	while (x < width)
	{
		y = y1;
		while (y < len)
			pixel_put(data->img, x, y++, color);
		x++;
	}
}