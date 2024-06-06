/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eburnet <eburnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 15:17:21 by eburnet           #+#    #+#             */
/*   Updated: 2024/06/06 11:48:19 by eburnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_algo_diff(int x, int y, t_data *data)
{
	if (data->dup_map[y][x] == '0' || data->dup_map[y][x] == 'C' ||
		data->dup_map[y][x] == 'E' || data->dup_map[y][x] == 'P')
	{
		data->dup_map[y][x] = 'V';
		ft_algo_diff(x, y + 1, data);
		ft_algo_diff(x, y - 1, data);
		ft_algo_diff(x - 1, y, data);
		ft_algo_diff(x + 1, y, data);
	}
}

int	ft_verif_map(t_data *data)
{
	int	i;

	i = 0;
	data->len_y = 0;
	data->len_x = 0;
	while (data->map[data->len_y] != NULL)
		data->len_y++;
	if (ft_line_len(data->map, data->len_y, &data->len_x) != NULL)
		return (free_tab(data->map), ft_putstr_fd("Error\nLine size\n", 2), 1);
	if ((data->len_y * TILE_SIZE) > 1000 || (data->len_x * TILE_SIZE) > 1800)
		return (free_tab(data->map), ft_putstr_fd("Error\nUnplayable\n", 2), 1);
	if (ft_x_check(data->map[0]) || ft_x_check(data->map[data->len_y - 1]))
		return (free_tab(data->map), ft_putstr_fd("Error\nHole in edge\n", 2), 1);
	data->len_x--;
	if (ft_find_start(data) == 1)
		return (free_tab(data->map), ft_putstr_fd("Error\nNo 'P'\n", 2), 1);
	while (data->map[i])
	{
		if (data->map[i][0] != '1' || data->map[i][data->len_x] != '1')
			return (free_tab(data->map),
				ft_putstr_fd("Error\nHole in edges\n", 2), 1);
		i++;
	}
	return (0);
}

int	ft_error(int items, int e, int p)
{
	if (items < 1)
		return (ft_putstr_fd("Error\nAt leat one 'C'\n", 2), 1);
	if (e != 1)
		return (ft_putstr_fd("Error\nOne and only one 'E'\n", 2), 1);
	if (p != 1)
		return (ft_putstr_fd("Error\nOne and Only one 'P'\n", 2), 1);
	return (0);
}

int	ft_verify_char(t_data *data, char *str)
{
	int	i;
	int	e;
	int	p;

	i = 0;
	data->items = 0;
	e = 0;
	p = 0;
	while (str[i] != '\0' && (str[i] == '1' || str[i] == '0' || str[i] == 'C'
			|| str[i] == 'E' || str[i] == 'P' || str[i] == '\n'))
	{
		if (str[i] == 'C')
			data->items++;
		else if (str[i] == 'E')
			e++;
		else if (str[i] == 'P')
			p++;
		i++;
	}
	if (str[i] != '\0')
		return (free(str), ft_putstr_fd("Error\nNot allowed char\n", 2), 1);
	if (ft_error(data->items, e, p) == 1)
		return (free(str), 1);
	return (0);
}

int	ft_parsing(t_data *data, char *filname)
{
	int		fd_map;
	char	*concat;

	data->map = NULL;
	fd_map = open(filname, O_RDONLY);
	if (fd_map < 0)
		return (ft_putstr_fd("Error\nCan't read map file\n", 2), 1);
	if (ft_file_type(filname) == 1)
		return (close(fd_map), ft_putstr_fd("Error\nWrong file type\n", 2), 1);
	concat = ft_concat(fd_map);
	if (concat == NULL)
		return (close(fd_map), ft_putstr_fd("Error\nEmpty map file\n", 2), 1);
	if (ft_verify_char(data, concat) == 1)
		return (close(fd_map), 1);
	data->map = ft_split(concat, '\n');
	data->dup_map = ft_split(concat, '\n');
	free(concat);
	if (data->map == NULL || data->dup_map == NULL)
		return (close(fd_map), ft_putstr_fd("Error\nSplit\n", 2), 1);
	if (ft_verif_map(data))
		return (close(fd_map), free_tab(data->dup_map), 1);
	if (ft_verif_acces(data))
		return (close(fd_map), free_tab(data->map), free_tab(data->dup_map),
			ft_putstr_fd("Error\n'E' or 'C' not reachable\n", 2), 1);
	return (0);
}
