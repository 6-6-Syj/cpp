#------------------------------------------------#
#					FILES						 #
#------------------------------------------------#
NAME = megaphone
SRC = megaphone.cpp

#------------------------------------------------#
#					DIRECTORY					 #
#------------------------------------------------#
OBJ_DIR = .build/

#------------------------------------------------#
#					PATHS						 #
#------------------------------------------------#
OBJ = $(OBJ_DIR)$(SRC:.cpp=.o)
DEP = $(OBJ_DIR)$(SRC:.cpp=.d)

-include $(DEP)

#------------------------------------------------#
#					FLAGS						 #
#------------------------------------------------#
CXX = c++
CXXFLAGS = -Wall -Wextra -std=c++98

#------------------------------------------------#
#					RULES						 #
#------------------------------------------------#
all: $(NAME)

$(NAME): $(OBJ) Makefile
	@echo "\n$(MAGENTA)$(BOLD)💻 Compiling executable...$(RESET)"
	@$(CXX) $(OBJ) -o $@
	@echo "$(GREEN)$(BOLD)✅ Compilation successfull !$(RESET)"

$(OBJ_DIR)%.o: %.cpp Makefile | $(OBJ_DIR)
	@echo " → Compiling $(YELLOW) $< $(RESET)"
	@$(CXX) $(CXXFLAGS) -MMD -MP -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	@rm -rf $(OBJ_DIR)
	@echo "$(MAGENTA)$(BOLD)\n🧹 Cleaning up project files...$(RESET)"
	@echo "$(CYAN)    └─ Cleaned build directory: $(OBJ_DIR)\n$(RESET)"

fclean: clean
	@rm -rf $(NAME)
	@echo "$(GREEN)$(BOLD)🗑️  Full clean-up completed:$(RESET)"
	@echo "$(CYAN)    └─ Executable removed: ./$(NAME)\n$(RESET)"

re: fclean all

.PHONY: all clean fclean re

#------------------------------------------------#
#					COLORS						 #
#------------------------------------------------#
GREEN	= \033[0;32m
YELLOW	= \033[1;33m
CYAN	= \033[0;36m
MAGENTA	= \033[0;35m
BOLD    = \033[1m
RESET   = \033[0m