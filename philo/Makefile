# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yothmani <yothmani@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/26 19:09:24 by yothmani          #+#    #+#              #
#    Updated: 2023/11/20 17:13:15 by yothmani         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


https://rphlr.github.io/42-Evals/Cursus/Philosophers/

NAME 				= philo

CC 					= gcc 
CFLAGS 				= -Wall -Wextra -Werror -pthread 
# CFLAGS 				=  -fsanitize=thread -g 

RM					= rm -rf

SRC_DIR 			= src/
INC_DIR 			= includes

INC 				= -I$(INC_DIR) 

SRC = $(SRC_DIR)main.c $(SRC_DIR)parse.c $(SRC_DIR)print.c $(SRC_DIR)time.c\
$(SRC_DIR)philo_state.c $(SRC_DIR)print.c $(SRC_DIR)init.c $(SRC_DIR)philo_routine.c\

OBJ 				= $(SRC:.c=.o)

all:  $(NAME)

$(NAME): $(OBJ) 
	@$(CC) $(CFLAGS) -o $@ $^ $(INC)
	@printf $(CUT)$(CUT)$(CUT)$(CUT)
	@echo $(BOLD) $(MINT)Only philosophers accepted !
	

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $< $(INC)
	@echo "Compiled $<"


norm :
	@echo $(BOLD)$(PINK)" Mandatory part!"$(MINT)
	@norminette $(SRC) $(INC_DIR)


leaks:
	@leaks --atExit -- ./philo 8 800 200 200  3


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
RED="\033[0m"
RESET="\033[0m"
BOLD="\033[1m"
UP = "\033[A"
DOWN = "\033[B"
RIGHT = "\033[C"
LEFT = "\033[D"
CUT = "\033[K"
SAVE = "\033[s"
RESTORE = "\033[u"