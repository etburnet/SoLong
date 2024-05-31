/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eburnet <eburnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 12:25:32 by eburnet           #+#    #+#             */
/*   Updated: 2024/05/31 15:52:44 by eburnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free_split(char	**tab)
{
	int	i;

	i = 0;
	while (tab[i])
		free (tab[i++]);
	free (tab);
}

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
	return NULL;
}

char	*ft_concat(int fd_map)
{
	char	*tmp;
	char	*buff;
	char	*concat;

	concat = ft_strdup("");
	buff = get_next_line(fd_map);
	if (buff == NULL)
		return (NULL);
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
