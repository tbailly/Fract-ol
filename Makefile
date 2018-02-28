# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbailly- <tbailly-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/28 14:40:30 by tbailly-          #+#    #+#              #
#    Updated: 2018/02/28 15:51:20 by tbailly-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	=	fractol
FLAGS	=	-Werror -Wall -Wextra
LIB		=	-L libft/ -lft

SRCS 	= 	main.c \
			ft_create_list.c \
			ft_compute_iterations.c \
			print_debug.c \

OBJS 	= 	$(SRCS:.c=.o)

all		: $(NAME)

$(NAME) : $(OBJS)
	# make -C libft/
	gcc $(FLAGS) -o $(NAME) $(OBJS) -I ./ $(LIB)

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
