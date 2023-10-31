# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yothmani <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/26 19:09:24 by yothmani          #+#    #+#              #
#    Updated: 2023/10/26 19:58:23 by yothmani         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME 				= philo

CC 					= gcc
CFLAGS 				= -Wall -Wextra -Werror

RM					= rm -rf

# LIBFT 				= $(LIBFT_DIR)/libft.a

SRC_DIR 			= src
INC_DIR 			= includes
# LIBFT_DIR 			= lib/libft

INC 				= -I$(INC_DIR) 
# -I$(LIBFT_DIR)



SRC = $(SRC_DIR)/main.c \



OBJ 				= $(SRC:.c=.o)


all:  $(NAME)


$(NAME): $(OBJ) 
	$(CC) $(CFLAGS) -o $@ $^ $(INC)
	@printf $(CUT)$(CUT)$(CUT)$(CUT)
	@echo $(BOLD) $(MINT)Only philosophers accepted !
	

# $(LIBFT): # make -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $< $(INC)
	@echo "Compiled $<"


norm :
	@echo $(BOLD)$(PINK)" Mandatory part!"$(MINT)
	@norminette $(SRC) $(INC_DIR)


leaks:
	leaks --atExit -- ./philo


clean :
	@printf $(CUT)$(CUT)
	@$(RM) $(OBJ) $(BONUS_OBJ) so_long.dSYM
	@echo $(BOLD)$(L_PURPLE)"Cleaned objects and executables!" ... 🧹🗑️$(RESET)

fclean : clean
	@$(RM) $(NAME) philo.dSYM fclean
	@printf $(CUT)$(CUT)
	@echo $(BOLD)$(L_PURPLE) ✨so_long✨ $(PINK)All cleaned up! ....🧹🗑️$(RESET)

re: fclean all

.PHONY: all  clean fclean re

# ######################### Color #########################

GREEN="\033[32m"
MINT="\033[38;5;51m"
L_PURPLE="\033[38;5;55m"
MAUVE="\033[38;5;147m"
PINK="\033[38;5;175m"
RESET="\033[0m"
BOLD="\033[1m"
UP = "\033[A"
DOWN = "\033[B"
RIGHT = "\033[C"
LEFT = "\033[D"
CUT = "\033[K"
SAVE = "\033[s"
RESTORE = "\033[u"