# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ncolliau <ncolliau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/07 15:24:29 by ncolliau          #+#    #+#              #
#    Updated: 2015/01/22 17:17:17 by ncolliau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

LIB_OBJ =	ft_itoa.o ft_putstr.o ft_putchar.o ft_strdup.o ft_nbrlen.o \
			ft_strlen.o ft_atoi.o ft_isdigit.o ft_isspace.o ft_strcmp.o

LIBFT_OBJ = $(addprefix libft/,$(LIB_OBJ))

OBJ = ft_printf.o option.o

FLAGS = -Wall -Wextra -Werror

.PHONY: make, all, $(NAME), clean, fclean, re, norme

all : $(NAME)

$(NAME) : $(OBJ) $(LIBFT_OBJ)
		@ar rc $(NAME) $(OBJ) $(LIBFT_OBJ)
		@echo "libftprintf compiled"
		ranlib $(NAME)

$(OBJ): %.o: %.c includes/libft.h includes/ft_printf.h
		gcc $(FLAGS) -I includes -c $< -o $@

$(LIBFT_OBJ): %.o: %.c includes/libft.h includes/ft_printf.h
		gcc $(FLAGS) -I includes -c $< -o $@
clean :
		@rm -f $(OBJ) $(LIBFT_OBJ)
		@echo "clean done"

fclean : clean
		rm -f $(NAME)

re : fclean all
