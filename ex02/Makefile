#------------------------------------------------#
#					DIRECTORY					 #
#------------------------------------------------#
SRC_DIR		:= src/
INC_DIR		:= include/
OBJ_DIR		:= .build/

#------------------------------------------------#
#					FILES						 #
#------------------------------------------------#
NAME	= 	bureaucrat
SRC		= 	main.cpp					\
			Bureaucrat.cpp				\
			AForm.cpp					\
			ShrubberyCreationForm.cpp	\

SRCS	= 	$(addprefix $(SRC_DIR), $(SRC))

#------------------------------------------------#
#                   PATHS                        #
#------------------------------------------------#
OBJ = $(addprefix $(OBJ_DIR), $(SRC:.cpp=.o))
DEP = $(addprefix $(OBJ_DIR), $(SRC:.cpp=.d))

#------------------------------------------------#
#					FLAGS						 #
#------------------------------------------------#
CXX = c++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98 -I$(INC_DIR) -MMD -MP

#------------------------------------------------#
#					RULES						 #
#------------------------------------------------#
all: $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(NAME): $(OBJ) Makefile
	@echo "\n$(B_BLUE)➤ Building $(NAME)$(RESET)$(BLUE)...$(RESET)"
	@$(CXX) $(CXXFLAGS) $(OBJ) -o $@
	@echo "$(B_CYAN)   → ./$(NAME)$(RESET)\n"

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp Makefile | $(OBJ_DIR)
	@echo "$(B_BLUE)➤ Compiling$(RESET)$(BLUE)...$(RESET)"
	@echo "$(B_YELLOW)   → $<$(RESET)"
	@$(CXX) $(CXXFLAGS) -c $< -o $@

-include $(DEP)

clean:
	@echo "$(B_RED)➤ Cleaning$(RESET)$(RED)...$(RESET)"
	@rm -rf $(OBJ_DIR)
	@echo "$(B_GREEN)   ✓ Clean$(RESET)\n"

fclean: clean
	@rm -rf $(NAME)
	@echo "$(B_RED)➤ Full clean$(RESET)"
	@echo "$(B_GREEN)   ✓ All removed$(RESET)\n"

re: fclean all

.PHONY: all clean fclean re

#------------------------------------------------#
#					COLORS						 #
#------------------------------------------------#
BOLD    	= \033[1m
RESET   	= \033[0m

B_RED 		= \033[1;31m
B_GREEN 	= \033[1;32m
B_YELLOW	= \033[1;33m
B_BLUE 		= \033[1;34m
B_MAGENTA 	= \033[1;35m
B_CYAN 		= \033[1;36m

RED 		= \033[0;31m
GREEN		= \033[0;32m
YELLOW		= \033[0;33m
BLUE		= \033[0;34m
MAGENTA		= \033[0;35m
CYAN		= \033[0;36m