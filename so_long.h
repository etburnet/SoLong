/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eburnet <eburnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 16:08:54 by eburnet           #+#    #+#             */
/*   Updated: 2024/05/17 11:14:33 by eburnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdlib.h>
# include <stdio.h>
# include "./LIBFT/libft.h"
# include "./minilibx-linux/mlx.h"
# include "./GNL/get_next_line.h"

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		img_width;
	int		img_height;
	int		x;
	int		y;
	void	*mlx;
	void	*mlx_win;
}				t_data;

#endif