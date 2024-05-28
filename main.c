/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eburnet <eburnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 10:26:16 by eburnet           #+#    #+#             */
/*   Updated: 2024/05/28 16:35:34 by eburnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#define WINDOW_WIDTH 500
#define WINDOW_HEIGHT 500
 
void	image(t_data *img)
{
	img->img = mlx_xpm_file_to_image(img->mlx, "./assets/floor.xpm",
			&img->img_width, &img->img_height);
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 10, 10);
	img->img = mlx_xpm_file_to_image(img->mlx, "./assets/wall.xpm",
			&img->img_width, &img->img_height);
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 50, 50);
	img->img = mlx_xpm_file_to_image(img->mlx, "./assets/player.xpm",
			&img->img_width, &img->img_height);
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, img->x, img->y);
}

int	key_hook(int keycode, t_data *img)
{
	printf("Key: %d = %c\n", keycode, keycode);
	if (keycode == 65307)
		exit(0);
	else if (keycode == 119)
		img->y -= 10;
	else if (keycode == 115)
		img->y += 10;
	else if (keycode == 100)
		img->x += 10;
	else if (keycode == 97)
		img->x -= 10;
	image(img);
	return (0);
}

int	main(void)
{
	t_data	img;

	img.mlx = mlx_init();
	img.mlx_win = mlx_new_window(img.mlx, WINDOW_WIDTH, WINDOW_HEIGHT,
			"So long");
	img.x = 150;
	img.y = 150;
	image(&img);
	/* mlx_string_put(img.mlx, img.mlx_win, WINDOW_WIDTH / 2,
		WINDOW_HEIGHT / 2, 0xffffff, "Salut"); */
	mlx_key_hook(img.mlx_win, (int (*)(int, void *))key_hook, &img);
	mlx_loop(img.mlx);
	return (1);
}
