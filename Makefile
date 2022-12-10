NAME = so_long
CFLAGS =  -I includes/
FLAGS = -D BUFFER_SIZE=1
MLX =  -lmlx -framework OpenGL -framework AppKit

SRCS = test.c check_maps.c maps_verification.c  door_freq.c count_coin.c coin_verify.c get_next_line_utils.c map_stock.c count_lines.c event_handel.c position.c player_position2.c verify_step.c
SRC1 = get_next_line.c 



OBJS = $(SRCS:.c=.o)
# OBJS1 = $(SRCS1:.c=.o)

 
all : $(NAME)

$(NAME) :  $(OBJS) 
		cc  $(CFLAGS) $(SRCS) $(MLX) ${FLAGS} ${SRC1} -o $(NAME)
		


clean : 
		rm -fr  $(OBJS) 

fclean : clean
		rm -fr $(NAME) 

re : clean all