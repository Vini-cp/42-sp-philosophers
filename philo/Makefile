NAME				= push_swap

SRCS_LIST 	= main.c

SRC_FOLDER 	= src

OBJ_FOLDER	= obj

SRCS 		= $(addprefix ${SRC_FOLDER}/, ${SRCS_LIST})

OBJS 		= $(addprefix ${OBJ_FOLDER}/, ${SRCS:.c=.o})

CFLAGS 		= -Werror -Wall -Wextra

CC 			= gcc

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
