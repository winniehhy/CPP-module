
NAME = megaphone

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic -g3

SRC = magaphone.cpp
OBJ = $(SRC:.cpp=.o)

# default target
all: $(NAME)

# linking
$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^
	@echo "$(GREEN)Executable $(NAME) created.$(RESET)"

# compiling
%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(ORANGE)Compiled $<$(RESET)"

# clean up
clean:
	rm -f $(OBJ)
	@echo "$(RED)Cleaned object files.$(RESET)"

fclean: clean
	rm -f $(NAME)
	@echo "$(RED)Removed executable $(NAME).$(RESET)"

re: fclean all

.PHONY: all clean fclean re