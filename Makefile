NAME = push_swap

CC = cc
CFLAGS = -Wall -Werror -Wextra -g

SRC_D = src
SRC = $(SRC_D)/utils.c $(SRC_D)/atol.c $(SRC_D)/fullarg.c $(SRC_D)/list_functions.c\
		$(SRC_D)/errors.c $(SRC_D)/no_double.c $(SRC_D)/swap.c $(SRC_D)/main.c $(SRC_D)/push.c\
		$(SRC_D)/rotate.c $(SRC_D)/reverse_rotate.c $(SRC_D)/sort.c $(SRC_D)/special_case.c\
		$(SRC_D)/for_three.c $(SRC_D)/ft_printstack.c $(SRC_D)/for_five.c $(SRC_D)/over_five.c\
		$(SRC_D)/cheapest_move.c $(SRC_D)/search_proxi.c $(SRC_D)/bestmove_in_a.c $(SRC_D)/bestmove_in_b.c\

OBJ_D = .obj
OBJ = $(addprefix $(OBJ_D)/, $(SRC:src/%.c=%.o))

INC = includes

LIBS = libft
LIBFT = libft/libft.a

GREEN =\033[0;32m
RED =\033[0;31m
YLW = \e[0;33m
END =\033[0m

all : $(LIBFT) $(NAME)

$(NAME) : $(OBJ)
	@$(CC) $(CFLAGS) $^ -L$(LIBS) -lft -o $@
	@echo "$(GREEN)$(NAME) successfully created\n$(END)"

$(LIBFT) :
	@$(MAKE) -C $(LIBS)

$(OBJ_D)/%.o : $(SRC_D)/%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -I$(INC) -I$(LIBS) -o $@ -c $<

clean :
	@$(MAKE) -C $(LIBS) clean
	@rm -rf $(OBJ_D)
	@echo "$(RED) .obj has been remove\n$(END)"

fclean : clean
	@$(MAKE) -C $(LIBS) fclean
	@rm -f $(NAME)
	@echo "$(RED)$(NAME) has been remove\n$(END)"

re :fclean all
	@echo "$(GREEN) remake has been a success\n$(END)"

.PHONY : all clean fclean re bonus
