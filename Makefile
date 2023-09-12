NAME    =   philo
CC      =   gcc
FLAGS   =   -Wall -Wextra -Werror
SRC     =   ./src/utils/ft_atoi.c \
			./src/error_managament.c \
			./src/checker.c \
			./src/eat.c \
			./src/monitor.c \
			./src/set_argumants.c \
			./src/get_time.c \
			./src/main.c

all:    			$(NAME)
$(NAME):
					$(CC) $(FLAGS) -o ./bin/$(NAME) $(SRC)
exe:				$(NAME)
					./so_long
clean:
					make -C clean
fclean:				clean
					rm -rf $(NAME)
re:					fclean all
.PHONY:				all clean fclean re libft