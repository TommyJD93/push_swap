NAME = push_swap

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g

LIBFT_PATH = libft/

LIBFT_LIB = $(LIBFT_PATH)libft.a

PRINTF_PATH = ft_printf/

PRINTF_LIB = $(PRINTF_PATH)libftprintf.a

Y = "\033[33m"
R = "\033[31m"
G = "\033[32m"
B = "\033[34m"
X = "\033[0m"
UP = "\033[A"
CUT = "\033[K"

CFILES = push_swap.c converter.c moves/moves_a.c moves/moves_b.c moves/moves_cases.c moves/moves_utils.c \
		utils.c algorithm/algo.c algorithm/sorting.c algorithm/sorting_utils.c checker.c algorithm/sorting_utils2.c \

OBJECTS = $(CFILES:.c=.o)

all: libraries $(NAME)

%.o : %.c
	@echo $(Y)Compiling [$<]...$(X)
	@$(CC) $(CFLAGS) -Imlx -c -o $@ $<
	@printf $(UP)$(CUT)

libraries:
	@echo $(B)
	make -C $(LIBFT_PATH) all
	@echo $(B)
	make -C $(PRINTF_PATH) all

$(NAME): $(OBJECTS)
	@echo $(Y)Compiling [$(CFILES)]...$(X)
	@echo $(G)Finished [$(CFILES)]$(X)
	@echo
	@echo $(Y)Compiling [$(NAME)]...$(X)
	@$(CC) $(CFLAGS) $(LIBFT_LIB) $(PRINTF_LIB) $(OBJECTS) -o $(NAME)
	@echo $(G)Finished [$(NAME)]$(X)

clean:
	@make -C $(LIBFT_PATH) clean
	@rm -f $(OBJECTS)
	@echo $(R)Removed [$(OBJECTS)]$(X)
	@echo $(R)Removed libraries.o$(X)

fclean: clean
	@make -C $(LIBFT_PATH) fclean
	@make -C $(PRINTF_PATH) fclean
	@rm -f $(NAME)
	@echo $(R)Removed [$(NAME)]$(X)

re: fclean all

norm:
	norminette libft ft_printf utils checker

run:	all
		@./push_swap  4 5 9 6 7 8

.PHONY: all clean fclean re norm