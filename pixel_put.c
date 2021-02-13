//
// Created by sergey on 13.02.2021.
//

#include "cub3d.h"

void	pixel_put(t_img *img, int x, int y, int color)
{
	int 	offset;
	char	*dst;

	offset = y * img->line_length + x * (img->bits_per_pixel / 8);
	dst = img->addr + offset;
	*(unsigned int*)dst = color;
}
