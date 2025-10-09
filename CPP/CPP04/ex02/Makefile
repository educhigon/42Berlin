NAME = Aanimal
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic -Wshadow -Wno-shadow
SRC = \
AAnimal.cpp \
Brain.cpp \
Cat.cpp \
Dog.cpp \
main.cpp \
WrongAnimal.cpp \
WrongCat.cpp 

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re all

