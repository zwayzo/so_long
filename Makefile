NAME = so_long
CFLAGS =  -Wall -Wextra -Werror 
FLAGS = -D BUFFER_SIZE=1
MLX =  -lmlx -framework OpenGL -framework AppKit
CC = cc
SRCS = ft_hexadecimale.c ft_putchar.c ft_putnbr.c ft_putstr.c ft_unsigne_value.c \
	ft_printf.c test.c move_right.c paint.c move_left.c move_up.c move_down.c check_maps.c \
	maps_verification.c  door_freq.c count_coin.c coin_verify.c extentions.c\
	get_next_line_utils.c map_stock.c count_lines.c event_handel.c \
	position.c player_position2.c verify_step.c valide_path.c copy.c check_letters.c
SRC1 = get_next_line.c

 
all : $(NAME)

$(NAME) :  ${SRC1} ${SRCS} 
		@${CC} $(SRCS) ${CFALGS} $(MLX) ${FLAGS} ${SRC1} -o $(NAME)
		@tput setaf 2; echo "So_long IS READY"
clean : 
		@rm -fr  $(NAME)
		@tput setaf 1; echo "CLEAN COMPLET"

fclean : clean
		@rm -fr $(NAME) 

re : clean all