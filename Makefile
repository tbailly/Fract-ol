# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbailly- <tbailly-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/28 14:40:30 by tbailly-          #+#    #+#              #
#    Updated: 2018/10/13 22:07:49 by tbailly-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	=	fractol
FLAGS	=	-Werror -Wall -Wextra
# FLAGS	=	-g
ARCHS	=	libft/libft.a minilibx/libmlx.a
MLX		=	-framework OpenGL -framework AppKit

SRCS 	= 	fractol.c \
			ft_refresh_fractal.c \
			\
			ft_keyboard_events.c \
			ft_mouse_events.c \
			\
			ft_julia.c \
			ft_mandelbrot.c \
			ft_burning_ship.c \
			ft_butterfly.c \
			ft_funnel.c \
			ft_mandelbrot_modified.c \
			\
			tools.c \
			color_palette.c

OBJS 	= 	$(SRCS:.c=.o)

all		: $(NAME)

$(NAME) : $(OBJS)
	make -C libft/ -s
	make -C minilibx/ -s
	gcc $(FLAGS) -o $(NAME) $(OBJS) -I ./ $(MLX) $(ARCHS)

%.o		: %.c
	gcc -c $(FLAGS) $(SRCS)


clean	:
	make -C libft/ clean
	make -C minilibx/ clean
	rm -rf $(OBJS)

fclean	: clean
	make -C libft/ fclean
	make -C minilibx/ clean
	rm -f $(NAME)

re		: fclean all

.PHONY	: all lib clean fclean re
