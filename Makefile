# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbailly- <tbailly-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/28 14:40:30 by tbailly-          #+#    #+#              #
#    Updated: 2018/03/06 21:47:52 by tbailly-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	=	fractol
FLAGS	=	-Werror -Wall -Wextra -g
LIB		=	-L libft/ -lft
MLX		=	-lmlx -framework OpenGL -framework AppKit

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
	make -C libft/
	gcc $(FLAGS) -o $(NAME) $(OBJS) -I ./ $(MLX) $(LIB)

%.o		: %.c
	gcc -c $(FLAGS) $(SRCS)


clean	:
	make -C libft/ clean
	rm -rf $(OBJS)

fclean	: clean
	make -C libft/ fclean
	rm -f $(NAME)

re		: fclean all



nl		: $(OBJS)
	gcc $(FLAGS) -o $(NAME) $(OBJS) -I ./ $(MLX) $(LIB)

nl_clean:
	rm -rf $(OBJS)

nl_fclean: clean
	rm -f $(NAME)

nl_re	: fclean all

.PHONY	: all lib clean fclean re nl nl_clean nl_fclean nl_re
