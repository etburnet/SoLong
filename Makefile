# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eburnet <eburnet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/18 13:44:02 by eburnet           #+#    #+#              #
#    Updated: 2024/06/07 12:20:00 by eburnet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CFLAGS = -Wall -Wextra -Werror -g3
SRCS = main.c ft_map.c ft_utils.c ft_map_utils.c ./GNL/get_next_line_utils.c ./GNL/get_next_line.c
OBJS = $(SRCS:.c=.o)
CC = gcc
HEADERS = so_long.h
LIBFT_PATH = ./LIBFT
MLX_PATH = ./minilibx-linux

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT_PATH)/libft.a $(MLX_PATH)/libmlx.a
	@echo "Linking $@..."
	@$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_PATH) -lft -L$(MLX_PATH) -lmlx -L/usr/lib -lXext -lX11 -lm -lz -o $(NAME)
	@echo "Executable $(NAME) created."
	
%.o: %.c $(HEADERS)
	@$(CC) $(CFLAGS) -I $(MLX_PATH) -O3 -c $< -o $@ >/dev/null

$(LIBFT_PATH)/libft.a:
	@echo "Building libft..."
	@make -C $(LIBFT_PATH) >/dev/null
	
$(MLX_PATH)/libmlx.a:
	@echo "Building MiniLibX..."
	@make -C $(MLX_PATH) >/dev/null

clean :
	@echo "Cleaning object files..."
	@rm -f $(OBJS)
	@make -C $(LIBFT_PATH) clean >/dev/null
	@make -C $(MLX_PATH) clean >/dev/null
	@echo "Solong cleaned."

fclean :
	@echo "Cleaning all generated files..."
	@rm -f $(OBJS)
	@rm -f $(NAME)
	@make -C $(LIBFT_PATH) fclean >/dev/null
	@make -C $(MLX_PATH) clean >/dev/null
	@echo "Solong Fcleaned."

re : fclean all
