/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eburnet <eburnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 10:26:16 by eburnet           #+#    #+#             */
/*   Updated: 2024/05/31 15:38:32 by eburnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#define WINDOW_WIDTH 500
#define WINDOW_HEIGHT 500
 
int	ft_put_image(t_data *data)
{
	data->floor = mlx_xpm_file_to_image(data->mlx, "./assets/floor.xpm", &data->img_width, &data->img_height);
	if (data->floor == NULL)
		return (1);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->floor, 10, 10);
	data->wall = mlx_xpm_file_to_image(data->mlx, "./assets/wall.xpm", &data->img_width, &data->img_height);
	if (data->wall == NULL)
		return (1);	
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->wall, 50, 50);
	return (0);
}

int	ft_put_player(t_data *data)
{
	data->floor = mlx_xpm_file_to_image(data->mlx, "./assets/floor.xpm", &data->img_width, &data->img_height);
	if (data->floor == NULL)
		return (1);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->floor, data->prev_x, data->prev_y);
	data->player = mlx_xpm_file_to_image(data->mlx, "./assets/player.xpm", &data->img_width, &data->img_height);
	if (data->player == NULL)
		return (1);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->player, data->x, data->y);
	return (0);
}

int	ft_key_hook(int keycode, t_data *data)
{
	data->prev_y = data->y;
	data->prev_x = data->x;
	if (keycode == 65307)
	{
		mlx_destroy_window(data->mlx, data->mlx_win);
		exit(0);
	}
	else if (keycode == 119)
		data->y -= 32;
	else if (keycode == 115)
		data->y += 32;
	else if (keycode == 100)
		data->x += 32;
	else if (keycode == 97)
		data->x -= 32;
	//printf("Movements: %d\n", );
	ft_put_player(data);
	return (0);
}

int	ft_x_close(t_data *data)
{
	mlx_destroy_window(data->mlx, data->mlx_win);
	free(data->mlx);
	free(data);
	exit(0);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_data	data;

	if (argc != 2)
		return (1);
	if (ft_parsing(&data, argv[1]) == 1)
		return (1);
	data.mlx = mlx_init();
	data.mlx_win = mlx_new_window(data.mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "So long");
	data.x = 150;
	data.y = 150;
	if (ft_put_image(&data))
		return (1);
	mlx_key_hook(data.mlx_win, (int (*)(int, void *))ft_key_hook, &data);
	mlx_hook(data.mlx_win, 17, 0, ft_x_close, &data);
	mlx_loop(data.mlx);
	return (0);
}
