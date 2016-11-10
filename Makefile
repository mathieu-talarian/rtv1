# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/10 11:58:59 by mmoullec          #+#    #+#              #
#    Updated: 2016/11/10 14:12:49 by mmoullec         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = rt_v1
PARS = pars
SRCS = fill_list.c\
	   main.c\
	   parseur.c\
	   print_list.c\
	   print_scene.c\
	   get_scene_datas.c\
	   get_scene_datas2.c\
		test_doc.c
SRCD = ./parseur/
OBJ = $(SRCS:.c=.o)

all: $(PARS)



$(PARS): $(OBJ)
	make -C ./libft
	clang -o $(PARS) $(OBJ) -lft -L./libft


%.o: $(SRCD)%.c
	$(CC) -o $@ -c $< -I. -I./libft


clean:
	rm -rf *.o

fclean: clean
	rm -rf $(NAME)
