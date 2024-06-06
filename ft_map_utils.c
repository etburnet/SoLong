/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eburnet <eburnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 12:24:40 by eburnet           #+#    #+#             */
/*   Updated: 2024/06/06 11:04:05 by eburnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_x_check(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != '1')
			return (1);
		i++;
	}
	return (0);
}

int	ft_file_type(char *file)
{
	int	l;

	l = ft_strlen(file);
	if (ft_strncmp(&file[l - 4], ".ber", 3))
		return (1);
	if (open(file, __O_DIRECTORY) >= 0)
		return (1);
	return (0);
}

void	*ft_line_len(char **map, int len, int *line_len)
{
	int	i;
	int	tmp;

	i = 0;
	while (i < len)
	{
		tmp = 0;
		while (map[i][tmp] != '\0')
			tmp++;
		if (*line_len == 0)
			*line_len = tmp;
		if (tmp != *line_len)
			return (&map[i][tmp]);
		i++;
	}
	return (NULL);
}

int	ft_find_start(t_data *data)
{
	int	i;
	int	j;

	j = 0;
	while (data->map[j])
	{
		i = 0;
		while (data->map[j][i])
		{
			if (data->map[j][i] == 'P')
			{
				data->x = i;
				data->y = j;
				return (0);
			}
			i++;
		}
		j++;
	}
	return (1);
}

int	ft_verif_acces(t_data *data)
{
	int	j;
	int	i;

	ft_algo_diff(data->x, data->y, data);
	j = 0;
	while (data->dup_map[j])
	{
		i = 0;
		while (data->dup_map[j][i])
		{
			if (data->dup_map[j][i] == 'C' || data->dup_map[j][i] == 'E')
				return (1);
			i++;
		}
		j++;
	}
	return (0);
}
