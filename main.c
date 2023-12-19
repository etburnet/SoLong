/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eburnet <eburnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 10:26:16 by eburnet           #+#    #+#             */
/*   Updated: 2023/12/19 15:51:32 by eburnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 500

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	int		i;
	int		j;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1200, 500, "Hello world!");
	img.img = mlx_new_image(mlx, 1200, 500);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	// carré
	i = 0;
	j = 0;
	while (i < 250)
	{
		my_mlx_pixel_put(&img, 150 + i, 150 + j, 0x00609C);
		i++;
	}
	while (j < 250)
	{
		my_mlx_pixel_put(&img, 150 + i, 150 + j, 0x00609C);
		j++;
	}
	i = 0;
	while (i < 250)
	{
		my_mlx_pixel_put(&img, 150 + i, 150 + j, 0x00609C);
		i++;
	}
	j = 0;
	i = 0;
	while (j < 250)
	{
		my_mlx_pixel_put(&img, 150 + i, 150 + j, 0x00609C);
		j++;
	}
	// triangle
	i = 0;
	j = 0;
	while (i < 250)
	{
		my_mlx_pixel_put(&img, 450 + i, 150 + j++, 0x00609C);
		i++;
	}
	i = 0;
	while (i < 250)
	{
		my_mlx_pixel_put(&img, 450 + i, 150 + j, 0x00609C);
		i++;
	}
	j = 0;
	i = 0;
	while (j < 250)
	{
		my_mlx_pixel_put(&img, 450 + i, 150 + j, 0x00609C);
		j++;
	}
	// rond
	i = 0;
	j = 0;
	while (i < 250)
	{
		my_mlx_pixel_put(&img, 750 + i, 150 + j++, 0x00609C);
		i++;
	}
	i = 0;
	while (i < 250)
	{
		my_mlx_pixel_put(&img, 750 + i, 150 + j, 0x00609C);
		i++;
	}
	j = 0;
	i = 0;
	while (j < 250)
	{
		my_mlx_pixel_put(&img, 750 + i, 150 + j, 0x00609C);
		j++;
	}
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}