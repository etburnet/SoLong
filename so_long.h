/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eburnet <eburnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 16:08:54 by eburnet           #+#    #+#             */
/*   Updated: 2024/06/07 18:35:42 by eburnet          ###   ########.fr       */
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

# ifndef TILE_SIZE
#  define TILE_SIZE 32
# endif

# define ERR_LINE "Error\nAll line as to be at the same size\n"
# define ERR_UNPLAY "Error\nUnplayable: map'too big\n"
# define ERR_HOLE "Error\nThe edges of the map must only be composed of '1'\n"
# define ERR_P "Error\nMap must contain a 'P'\n"

typedef struct s_data
{
	char	**map;
	char	**dup_map;
	void	*img_floor;
	void	*img_wall;
	void	*img_player;
	void	*img_item;
	void	*img_door;
	int		items;
	int		mooves;
	int		img_width;
	int		img_height;
	int		x;
	int		y;
	int		prev_x;
	int		prev_y;
	int		len_x;
	int		len_y;
	int		loaded_img;
	void	*mlx;
	void	*mlx_win;
}				t_data;

int		ft_parsing(t_data *data, char *filname);
void	free_tab(char	**tab);
void	*ft_line_len(char **map, int len, int *line_len);
char	*ft_concat(int fd_map);
int		ft_x_check(char *str);
int		ft_verif_acces(t_data *data);
int		ft_file_type(char *file);
int		ft_find_start(t_data *data);
void	ft_algo_diff(int x, int y, t_data *data);
int		ft_init_image(t_data *data);
int		ft_x_action(t_data *data, int pm);
int		ft_y_action(t_data *data, int pm);
int		ft_x_close(t_data *data);
int		ft_iter_null(t_data *data, void *img);

#endif