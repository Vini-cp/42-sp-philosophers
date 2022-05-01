NAME		= philo

SRCS_LIST 	= main.c \
			  philosopher/ft_initiate_constraints.c \
			  philosopher/ft_initiate_forks.c \
			  philosopher/ft_initiate_philosophers.c \
			  utils/ft_atoi.c \
			  utils/ft_get_time_now.c \
			  utils/ft_print_action.c \
			  utils/ft_print_error.c \
			  utils/ft_print_philosophers.c

SRC_FOLDER 	= src

OBJ_FOLDER	= obj

SRCS 		= $(addprefix ${SRC_FOLDER}/, ${SRCS_LIST})

OBJS 		= $(addprefix ${OBJ_FOLDER}/, ${SRCS:.c=.o})

CFLAGS 		= -Werror -Wall -Wextra

CC 			= gcc

ARGS		= 10 1000 1000 1000 10

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJ_FOLDER)/%.o: %.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	@rm -rf $(OBJ_FOLDER)

fclean: clean
	@rm -f $(NAME)

re: fclean all

valgrind:
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./philo ${ARGS}

test:
	./philo ${ARGS}
