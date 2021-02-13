//
// Created by sergey on 13.02.2021.
//

#include "cub3d.h"

void	draw_h_line(t_data *data, int len, int width, int x, int y1, int color)
{
	int y;

	len += x;
	width += y1;
	while (x < len)
	{
		y = y1;
		while (y < width)
			pixel_put(data->img, x, y++, color);
		x++;
	}
}