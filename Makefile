NAME = philo

PATH_INCS = ./includes/
PATH_OBJS = ./objects/
PATH_SRCS = ./sources/
PATH_MAIN = $(PATH_SRCS)main/
PATH_TOOL = $(PATH_SRCS)tools/

SRCS = $(addprefix $(PATH_MAIN),\
		action_eat.c\
		action_sleep.c\
		action_think.c\
		action_wait.c\
		allign_start_times.c\
		check_arguments.c\
		exit_handler.c\
		init_simulation.c\
		init_table.c\
		is_it_over.c\
		main.c\
		observer_routine.c\
		philosopher_routine.c\
		print_status.c\
		simulate.c)\
		$(addprefix $(PATH_TOOL),\
		ft_atoi.c\
		ft_calloc.c\
		ft_fetch_time.c\
		ft_free_pointer.c\
		ft_free_ppointer.c\
		ft_onlydigits.c)
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