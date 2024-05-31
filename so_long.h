/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eburnet <eburnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 16:08:54 by eburnet           #+#    #+#             */
/*   Updated: 2024/05/31 15:52:52 by eburnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdlib.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "./LIBFT/libft.h"
# include "./minilibx-linux/mlx.h"
# include "./GNL/get_next_line.h"

typedef struct s_data
{
	char	**map;
	void	*floor;
	void	*wall;
	void	*player;
	void	*item;
	void	*door;
	int		img_width;
	int		img_height;
	int		x;
	int		y;
	int		prev_x;
	int		prev_y;
	void	*mlx;
	void	*mlx_win;
}				t_data;

int		ft_parsing(t_data *data, char *filname);
void	ft_free_split(char	**tab);
void	*ft_line_len(char **map, int len, int *line_len);
char	*ft_concat(int fd_map);
int		ft_x_check(char *str);

#endif