/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eburnet <eburnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 10:26:16 by eburnet           #+#    #+#             */
/*   Updated: 2024/06/03 16:53:19 by eburnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_put_image(t_data *data)
{
	int	j;
	int	i;

	j = 0;
	while (data->map[j])
	{
		i = 0;
		while (data->map[j][i])
		{
			if (data->map[j][i] == '1')
				mlx_put_image_to_window(data->mlx, data->mlx_win,
					data->img_wall, i * TILE_SIZE, j * TILE_SIZE);
			if (data->map[j][i] == '0')
				mlx_put_image_to_window(data->mlx, data->mlx_win,
					data->img_floor, i * TILE_SIZE, j * TILE_SIZE);
			if (data->map[j][i] == 'C')
				mlx_put_image_to_window(data->mlx, data->mlx_win,
					data->img_item, i * TILE_SIZE, j * TILE_SIZE);
			if (data->map[j][i] == 'E')
				mlx_put_image_to_window(data->mlx, data->mlx_win,
					data->img_door, i * TILE_SIZE, j * TILE_SIZE);
			i++;
		}
		j++;
	}
}

void	ft_put_player(t_data *data)
{
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img_floor,
		data->prev_x * 32, data->prev_y * 32);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img_player,
		data->x * 32, data->y * 32);
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
	else if (keycode == 'w' && ft_valid_action(data, 'y', -1) != 1)
		data->y -= 1;
	else if (keycode == 's' && ft_valid_action(data, 'y', 1) != 1)
		data->y += 1;
	else if (keycode == 'd' && ft_valid_action(data, 'x', 1) != 1)
		data->x += 1;
	else if (keycode == 'a' && ft_valid_action(data, 'x', -1) != 1)
		data->x -= 1;
	ft_put_player(data);
	return (0);
}

int	ft_x_close(t_data *data)
{
	mlx_destroy_window(data->mlx, data->mlx_win);
	free(data->mlx);
	free_tab(data->dup_map);
	free_tab(data->map);
	exit(0);
	free(data);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_data	data;

	if (argc != 2)
		return (1);
	if (ft_parsing(&data, argv[1]) == 1)
		return (1);
	data.mooves = 0;
	data.mlx = mlx_init();
	data.mlx_win = mlx_new_window(data.mlx, (data.len_x + 1) * TILE_SIZE,
			(data.len_y) * TILE_SIZE, "So long");
	if (ft_init_image(&data))
		return (1);
	ft_put_image(&data);
	mlx_key_hook(data.mlx_win, (int (*)(int, void *))ft_key_hook, &data);
	mlx_hook(data.mlx_win, 17, 0, ft_x_close, &data);
	mlx_loop(data.mlx);
	return (0);
}
