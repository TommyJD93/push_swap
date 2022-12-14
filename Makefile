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

CFILES = push_swap.c converter.c moves/moves_a.c moves/moves_b.c \
			moves/rrotate.c utils.c algo.c dioporco.c checker.c \

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

fclean: clean
	@make -C $(LIBFT_PATH) fclean
	@make -C $(PRINTF_PATH) fclean
	@rm -f $(NAME)
	@echo $(R)Removed [$(NAME)]$(X)

re: fclean all

norm:
	norminette libft ft_printf utils checker

run:	all
		@./push_swap 50 3 10 7 40 80 27 1

# 50 3 10 7 40 80

.PHONY: all clean fclean re norm
