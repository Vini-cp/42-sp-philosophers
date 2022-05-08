NAME		:= philo

SRCS_LIST 	:= main.c \
			  philosopher/ft_exit_threads.c \
			  philosopher/ft_initiate_constraints.c \
			  philosopher/ft_initiate_forks.c \
			  philosopher/ft_initiate_philosophers.c \
			  philosopher/ft_philosopher_has_died.c \
			  philosopher/ft_run_philosophers.c \
			  utils/ft_atoi.c \
			  utils/ft_free.c \
			  utils/ft_get_time_now.c \
			  utils/ft_print_action.c \
			  utils/ft_print_error.c \
			  utils/ft_print_philosophers.c \
			  utils/ft_time_diff.c

SRC_FOLDER 	:= src

OBJ_FOLDER	:= obj

SRCS 		:= $(addprefix ${SRC_FOLDER}/, ${SRCS_LIST})

OBJS 		:= $(addprefix ${OBJ_FOLDER}/, ${SRCS:.c=.o})

CFLAGS 		:= -Werror -Wall -Wextra

PFLAGS		:= -lpthread

CC 			:= gcc

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(PFLAGS)

$(OBJ_FOLDER)/%.o: %.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	@rm -rf $(OBJ_FOLDER)

fclean: clean
	@rm -f $(NAME)

re: fclean all
