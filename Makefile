# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbailly- <tbailly-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/28 14:40:30 by tbailly-          #+#    #+#              #
#    Updated: 2018/03/02 11:45:38 by tbailly-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	=	fractol
FLAGS	=	-Werror -Wall -Wextra
LIB		=	-L libft/ -lft
MLX		=	-lmlx -framework OpenGL -framework AppKit

SRCS 	= 	main.c \
			print_debug.c \
			ft_draw.c \
			ft_zoom.c \
			tools.c \
			\
			\
			single_point.c

OBJS 	= 	$(SRCS:.c=.o)

all		: $(NAME)

$(NAME) : $(OBJS)
	# make -C libft/
	gcc $(FLAGS) -o $(NAME) $(OBJS) -I ./ $(MLX) $(LIB)

%.o		: %.c
	gcc -c $(FLAGS) $(SRCS)

clean	:
	# make -C libft/ clean
	rm -rf $(OBJS)

fclean	: clean
	# make -C libft/ fclean
	rm -f $(NAME)

re		: fclean all

.PHONY	: all lib clean fclean re
