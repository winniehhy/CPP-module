NAME = DiamondTrap
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = ClapTrap.cpp ScavTrap.cpp FragTrap.cpp DiamondTrap.cpp main.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

# -Wshadow and-Wno-shadow compiler
# -Wshadow	Want to catch accidental variable shadowing (recommended!)
#-Wshadow: "Warn me if I reuse a name by accident."
# -Wno-shadow	Intentionally reuse variable names and want to silence warnings
# Wno-shadow: "Don’t warn me even if I reuse names."
# Use this if:

# You know what you're doing, and you’re okay with using the same names in different places.

# You want to hide the warnin