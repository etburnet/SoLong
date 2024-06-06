/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eburnet <eburnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 12:25:32 by eburnet           #+#    #+#             */
/*   Updated: 2024/06/06 11:34:07 by eburnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_tab(char	**tab)
{
	int	i;

	i = 0;
	while (tab[i])
		free (tab[i++]);
	free (tab);
}

char	*ft_concat(int fd_map)
{
	char	*tmp;
	char	*buff;
	char	*concat;

	concat = ft_strdup("");
	buff = get_next_line(fd_map);
	if (buff == NULL)
		return (free(concat), NULL);
	while (buff != NULL)
	{
		tmp = concat;
		concat = ft_strjoin(tmp, buff);
		free(tmp);
		tmp = NULL;
		free(buff);
		buff = get_next_line(fd_map);
	}
	free(tmp);
	return (concat);
}

int	ft_init_image(t_data *data)
{
	data->img_wall = mlx_xpm_file_to_image(data->mlx,
			"./assets/wall.xpm", &data->img_width, &data->img_height);
	if (data->img_wall == NULL)
		return (1);
	data->img_floor = mlx_xpm_file_to_image(data->mlx,
			"./assets/floor.xpm", &data->img_width, &data->img_height);
	if (data->img_floor == NULL)
		return (1);
	data->img_item = mlx_xpm_file_to_image(data->mlx,
			"./assets/item.xpm", &data->img_width, &data->img_height);
	if (data->img_item == NULL)
		return (1);
	data->img_player = mlx_xpm_file_to_image(data->mlx,
			"./assets/player.xpm", &data->img_width, &data->img_height);
	if (data->img_player == NULL)
		return (1);
	data->img_door = mlx_xpm_file_to_image(data->mlx,
			"./assets/door.xpm", &data->img_width, &data->img_height);
	if (data->img_door == NULL)
		return (1);
	return (0);
}

int	ft_x_action(t_data *data, int pm)
{
	if (data->map[data->y][data->x + pm] == '1')
		return (1);
	if (data->map[data->y][data->x + pm] == 'C')
	{
		data->map[data->y][data->x + pm] = '0';
		data->items--;
	}	
	if (data->map[data->y][data->x + pm] == 'E' && data->items == 0)
		ft_x_close(data);
	data->mooves++;
	ft_printf("Mooves: %d\n", data->mooves);
	return (0);
}

int	ft_y_action(t_data *data, int pm)
{
	if (data->map[data->y + pm][data->x] == '1')
		return (1);
	if (data->map[data->y + pm][data->x] == 'C')
	{
		data->map[data->y + pm][data->x] = '0';
		data->items--;
	}	
	if (data->map[data->y + pm][data->x] == 'E' && data->items == 0)
		ft_x_close(data);
	data->mooves++;
	ft_printf("Mooves: %d\n", data->mooves);
	return (0);
}
