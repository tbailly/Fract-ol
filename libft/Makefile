# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbailly- <tbailly-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/07 14:55:46 by tbailly-          #+#    #+#              #
#    Updated: 2018/03/06 21:32:04 by tbailly-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libft.a

FLAGS		=	-Wall -Werror -Wextra
HDPATH		=	./includes/

LIB_PATH	=	./libft/
LIB_SRC		=	ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c \
				ft_memchr.c ft_memcmp.c ft_strlen.c ft_strdup.c ft_strcpy.c \
				ft_strncpy.c ft_strcat.c ft_strncat.c ft_strlcat.c ft_strchr.c \
				ft_strrchr.c ft_strstr.c ft_strnstr.c ft_strcmp.c ft_strncmp.c \
				ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
				ft_isprint.c ft_toupper.c ft_tolower.c \
				\
				ft_memalloc.c ft_memdel.c ft_strnew.c ft_strdel.c ft_strclr.c \
				ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c ft_strequ.c \
				ft_strnequ.c ft_strsub.c ft_strjoin.c ft_strtrim.c ft_strsplit.c \
				ft_itoa.c ft_putchar.c ft_putstr.c ft_putendl.c ft_putnbr.c \
				ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
				\
				ft_swap.c ft_strup.c ft_strlw.c ft_strcleandbl.c ft_strrepchr.c \
				ft_putstrarr.c ft_itoa_base.c ft_abs.c ft_min.c ft_max.c \
				ft_abs_dbl.c \
				\
				ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c \
				ft_lstmap.c
LIBS		=	$(addprefix $(LIB_PATH)/, $(LIB_SRC))

GNL_PATH	=	./get_next_line/
GNL_SRC		=	get_next_line.c
GNLS		=	$(addprefix $(GNL_PATH)/, $(GNL_SRC))


OBJS		=	$(LIBS:.c=.o)
G_OBJS		=	$(GNLS:.c=.o)
OBJS		+=	$(G_OBJS)




all: $(NAME)

$(NAME): $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

%.o : %.c
	@gcc $(FLAGS) -c $< -o $@ -I $(HDPATH)

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
