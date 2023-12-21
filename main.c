/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eburnet <eburnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 10:26:16 by eburnet           #+#    #+#             */
/*   Updated: 2023/12/21 11:53:14 by eburnet          ###   ########.fr       */
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


void my_key_function()
{
	
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	int		img_width;
	int		img_height;
	char	*player = "./player.xpm";
	char	*floor = "./floor.xpm";

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 500, 500, "So long");
	img.img = mlx_new_image(mlx, 500, 500);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	img.img = mlx_xpm_file_to_image(mlx, floor, &img_width, &img_height);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	img.img = mlx_xpm_file_to_image(mlx, player, &img_width, &img_height);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 150, 150);
	//mlx_key_hook(mlx_win, my_key_function, );
	mlx_loop(mlx);
}
