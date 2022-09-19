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

CFILES = push_swap.c converter.c moves/moves_a.c moves/moves_b.c moves/cases_moves.c\
		utils.c algorithm/algo.c algorithm/sorting.c algorithm/sorting_utils.c checker.c \
		algorithm/sorting_utils2.c \

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
		@./push_swap 40 61 6 1 66 57 83 93 62 48 77 73 30 100 32 98 19 84 56 15 50 65 58 36 46 95 38 45 14 76 60 35 70 37 42 74 64 7 16 5 43 9 3 25 80 51 2 18 24 86 34 20 26 85 63 8 33 47 27 39 96 11 78 4 59 71 31 29 68 90 87 81 91 12 23 92 49 88 41 10 89 99 82 44 79 97 69 17 94 22 28 72 13 75 55 54 53 67 21 52
#50 3 10 7 40 80 27 1

.PHONY: all clean fclean re norm