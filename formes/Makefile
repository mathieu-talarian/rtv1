NAME=formes
CC=clang
LIB=-I../libft -I../libmlx -I../libvect -I../minilibx_macos -I.
LL=-L../libft -lft -L../libmlx -lmy_mlx -L../libvect -lvect -L../minilibx_macos -lmlx -framework Appkit -framework OpenGL
SRCS=gest_lum.c\
	main.c\
	start_rt.c\
	init_rt.c\
	test.c

OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LL)

%.o: %.c
	$(CC) -o $@ -c $< $(LIB)

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
