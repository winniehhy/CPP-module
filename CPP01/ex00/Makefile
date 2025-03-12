# Colors for terminal output
GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m
YELLOW = \033[0;33m

# Project name and compiler settings
NAME = BraiiiiiiinnnzzzZ
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic

# Source and object files
SRC = Zombie.cpp main.cpp NewZombie.cpp randomChump.cpp
OBJ = $(SRC:.cpp=.o)
HEADERS = zombie.hpp

# Default target
all: $(NAME)

# Linking
$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "$(GREEN)Executable $(NAME) created.$(RESET)"

# Compiling
%.o: %.cpp $(HEADERS)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(YELLOW)Compiled $<$(RESET)"

# Clean object files
clean:
	@rm -f $(OBJ)
	@echo "$(RED)Cleaned object files.$(RESET)"

# Clean everything
fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)Removed executable $(NAME).$(RESET)"

# Rebuild everything
re: fclean all

# Phony targets
.PHONY: all clean fclean re