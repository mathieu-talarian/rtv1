NAME=formes
CC=clang
LIB=-I../libft -I../libmlx -I../libvect -I. -I../libmy_math -I../minilibx_macos
LL=-L../libft -lft -L../libmlx -lmy_mlx -L../libvect -lvect -L../libmy_math -lmy_math -L../minilibx_macos -lmlx -framework Appkit -framework OpenGL
SRCS=gest_lum.c\
	main.c\
	start_rt.c\
	init_rt.c\
	test.c\
	shadow.c\
	new_start.c\
	torus.c\
	torus_normal.c\
	check_obj_to_draw.c

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

exec:
	./$(NAME)

run: all exec fclean

re: fclean all
