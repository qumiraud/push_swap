NAME = push_swap

CC = cc
CFLAGS = -Wall -Werror -Wextra -g

SRC_D = src
SRC = $(SRC_D)/test.c $(SRC_D)/utils.c $(SRC_D)/atol.c $(SRC_D)/fullarg.c $(SRC_D)/list_functions.c

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
