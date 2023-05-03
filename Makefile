NAME = philo

PATH_INCS = ./includes/
PATH_OBJS = ./objects/
PATH_SRCS = ./sources/
PATH_MAIN = $(PATH_SRCS)main/
PATH_TOOL = $(PATH_SRCS)tools/

SRCS = $(addprefix $(PATH_MAIN),\
		ft_philosophers.c)\
		$(addprefix $(PATH_TOOL),\
		ft_atoi.c\
		ft_calloc.c\
		ft_check_arguments.c\
		ft_print_error.c)
OBJS = $(patsubst $(PATH_SRCS)%.c, $(PATH_OBJS)%.o, $(SRCS))

CC = cc
CFLAGS = -Wall -Wextra -Werror -pthread
IFLAGS = -I $(PATH_INCS)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(IFLAGS) -o $(NAME) $(OBJS)

$(PATH_OBJS)%.o: $(PATH_SRCS)%.c
	@mkdir -p $(PATH_OBJS)
	@mkdir -p $(PATH_OBJS)main/
	@mkdir -p $(PATH_OBJS)tools/
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

clean:
	@rm -rf $(PATH_OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

r: all
	@clear
	@./philo 4 410 200 200

n:
	@clear
	@norminette ./sources ./includes

PHONY: all clean fclean re r n