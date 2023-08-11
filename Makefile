NAME		 	= so_long

# files & headers

SRC		= src/so_long.c src/print_map.c src/init_map.c src/init_game.c src/destroy.c src/check_map.c src/movement.c src/utils.c

OBJS 	= $(SRC:.c=.o)

MAKEFLAGS += --no-print-directory

# libft

LIBFT			=		./libft/libft.a
MLIBFT			=		@$(MAKE) -C libft

# mlx

MLX				=		./mlx/libmlx.a
MMLX			=		@$(MAKE) -C mlx

# flags

CC 				= gcc
CFLAGS			= -Wall -Wextra -Werror -g3 -Iincludes
MINILIBX		= -Lmlx -lmlx -framework OpenGL -framework AppKit
RM 				= rm -rf

# compilation

all: lib $(NAME) 

lib:
	@$(MLIBFT)
	@$(MMLX)

$(NAME) :	${OBJS}
			${CC} ${CFLAGS} -o ${NAME} ${OBJS} ${LIBFT} $(MINILIBX)

l :
	@$(MLIBFT)
	@$(MMLX)
	$(GCC) $(L) $(SRC) $(LIBFT) $(MINILBX) -o $(NAME)


# clean

clean:
			@$(S_OBJS)
			@${RM} ${OBJS}
			@${MLIBFT} clean
			@${MMLX} clean

fclean:		clean
			@${RM} ${NAME}
			@${MLIBFT} fclean
			@echo "Success cleaning"

re:			fclean all

.PHONY:		all clean fclean re

