# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eburnet <eburnet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/18 13:44:02 by eburnet           #+#    #+#              #
#    Updated: 2023/12/18 14:33:35 by eburnet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = solong.a
CFLAGS = -Wall -Wextra #-Werror
SRCS = main.c
OBJS = $(SRCS:.c=.o)
LINKS = -lmlx -lXext -lX11
HEADERS =

.c.o : 
	gcc $(CFLAGS) $(HEADERS) -c $<

$(NAME): $(OBJS)
	gcc $(SOURCES) -o $(NAME) $(CFLAGS) $(LINKS)

all : $(NAME)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all
	
.PHONY : all clean flcean re
