NAME := fractol

SRC := main.c draw.c init.c utils.c zoom.c		\
	some_libft.c tricorn.c color.c mandelbrot.c	\
	key.c mouse.c julia.c

OBJS := $(SRC:.c=.o)

FLAG := -lm -lbsd -lXext -lX11 \
	-fsanitize=address

CFLAG := -Wall -Wextra -Werror

all: $(NAME) minilibx

bonus: all

.c.o: $(SRC)
	clang $(CFLAG) -c $< -o $@
	
$(NAME): $(OBJS) minilibx
	clang $(OBJS) -o $(NAME) $(CFLAG) minilibx-linux/libmlx_Linux.a $(FLAG)

mandelbrot:
	./fractol mandelbrot

tricorn:
	./fractol tricorn

minilibx:
	cd minilibx-linux && make

julia1:
	./fractol julia -0.835 -0.2321
julia2:
	./fractol julia 0.285 0
julia3:
	./fractol julia 0.285 0.01
julia4:
	./fractol julia 0.45 0.1428 
julia5:
	./fractol julia -0.70176 -0.3842

norminette:
	norminette *.c && norminette *.h

setDebian:
	sudo apt-get update && sudo apt-get upgrade  && sudo apt-get install gcc make xorg libxext-dev libbsd-dev

clean:
	rm -f $(OBJS)

fclean: clean minilibx_clean
	rm -f $(NAME)

minilibx_clean:
	cd minilibx-linux && make clean

re: fclean all
