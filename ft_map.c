/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eburnet <eburnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 15:17:21 by eburnet           #+#    #+#             */
/*   Updated: 2024/05/31 16:28:05 by eburnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_verif_acces(int x, int y, t_data *data)
{
	// part de x et y sur une copie de split
	// tant aue pas 1 remplacer char par 'F'
	// recucive x +1/-1 y+1/-1
	// parcourir map coper si reste E ou C pas bon
	if ()
	{
		ft_verif_acces();
		ft_verif_acces();
		ft_verif_acces();
		ft_verif_acces();
	}
	
/* 		début
	si couleur(pixel) = colcible 
	alors
		couleur(pixel) ← colrep
		remplissage4(pixel au nord, colcible, colrep)
		remplissage4(pixel au sud, colcible, colrep)
		remplissage4(pixel à l'est, colcible, colrep)
		remplissage4(pixel à l'ouest, colcible, colrep)
	finsi
	fin */
}

int	ft_verif_map(t_data *data)
{
	int	len;
	int	line_len;
	int	i;

	i = 0;
	len = 0;
	line_len = 0;
	while (data->map[len] != NULL)
		len++;	
	if (ft_line_len(data->map, len, &line_len) != NULL)
		return (ft_free_split(data->map), ft_putstr_fd("Error\nLine size\n", 2), 1);
	if (ft_x_check(data->map[0]) || ft_x_check(data->map[len - 1]))
		return (ft_free_split(data->map), ft_putstr_fd("Error\nHole in edges\n", 2), 1);
	line_len--;
	while (data->map[i])
	{
		if (data->map[i][0] != '1' || data->map[i][line_len] != '1')
			return (ft_free_split(data->map), ft_putstr_fd("Error\nHole in edges\n", 2), 1);
		i++;
	}
	return (0);
}

int	ft_error(int c, int e, int p)
{
	if (c < 1)
		return (ft_putstr_fd("Error\nAt leat one 'C'\n", 2), 1);
	if (e != 1)
		return (ft_putstr_fd("Error\nOne and only one 'E'\n", 2), 1);
	if (p != 1)
		return (ft_putstr_fd("Error\nOne and Only one 'P'\n", 2), 1);
	return (0);
}

int	ft_verify_char(char *str)
{
	int	i;
	int	c;
	int	e;
	int	p;

	i = 0;
	c = 0;
	e = 0;
	p = 0;
	while (str[i] != '\0' && (str[i] == '1' || str[i] == '0' || str[i] == 'C'
		|| str[i] == 'E' || str[i] == 'P' || str[i] == '\n'))
	{
		if (str[i] == 'C')
			c++;
		else if (str[i] == 'E')
			e++;
		else if (str[i] == 'P')
			p++;
		i++;
	}
	if (str[i] != '\0')
		return (free(str), ft_putstr_fd("Error\nNot allowed char\n", 2), 1);
	if (ft_error(c, e, p) == 1)
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
	concat = ft_concat(fd_map);
	if (concat == NULL)
		return (close(fd_map), ft_putstr_fd("Error\nEmpty map file\n", 2), 1);
	if (ft_verify_char(concat) == 1)
		return (close(fd_map), 1);
	data->map = ft_split(concat, '\n');
	free(concat);
	if (data->map == NULL)
		return (close(fd_map), ft_putstr_fd("Error\nSplit\n", 2), 1);
	if (ft_verif_map(data))
		return (close(fd_map), 1);
	if (ft_verif_acces(data))
		return (close(fd_map), ft_free_split(data->map), 1);
	return (0);
}
