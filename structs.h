//
// Created by sergey on 13.02.2021.
//

#ifndef CUB3D_STRUCTS_H
# define CUB3D_STRUCTS_H

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

#endif
