# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/22 15:22:45 by mmoullec          #+#    #+#              #
#    Updated: 2016/11/22 15:34:47 by mmoullec         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= libvect.a
CC = clang -Wall -Werror -Wextra
OBJ = $(SRC:.c=.o)
SRC = vect_add.c\
vect_cos.c\
vect_create.c\
vect_cross.c\
vect_dot.c\
vect_length.c\
vect_s_mul.c\
vect_sub.c\
vect_unit.c\
print_vect.c

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $? $(OBJ)
	@ranlib $(NAME)
	@echo $(NAME) "Created"


%.o: %.c
	@$(CC) -o $@ -c $< -I.
	@echo $@ "OK"

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
