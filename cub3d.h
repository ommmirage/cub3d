//
// Created by sergey on 13.02.2021.
//

#ifndef CUB3D_CUB3D_H
# define CUB3D_CUB3D_H

# include "structs.h"

void	pixel_put(t_img *img, int x, int y, int color);
void	draw_h_line(t_data *data, int len, int width, int x, int y1, int color);
void	draw_v_line(t_data *data, int len, int width, int x, int y1, int color);
void	draw_cross(t_data *data);

#endif
