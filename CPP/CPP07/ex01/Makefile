NAME = Iter
CXX = c++
RM = rm -f
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic -Wshadow -Wno-shadow
SRC = \
main.cpp 
OBJDIR := build
OBJS := $(addprefix $(OBJDIR)/, $(SRC:.cpp=.o))
DEPS := $(OBJS:.o=.d)

all:
	@echo "\033[34m \n- COMPILING -\033[0m" ; $(MAKE) --no-print-directory $(NAME)

$(NAME): $(OBJS)
	@echo "\033[34m \n- CREATING EXECUTABLE -\033[0m"
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
	@echo " ----- Created executable:" $(NAME)
	@echo "\n\n\033[32m>>>>   'Usage : run ./Iter'   <<<<\n\033[0m"

$(OBJDIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	@$(CXX) $(CXXFLAGS) -c $< -o $@
	@echo " ----- Compiling $< -> $@"

-include $(DEPS)

clean:
	@echo "\033[33m \n- CLEANING .o FILES -\033[0m"
	@$(RM) $(OBJS) $(DEPS)
	@rm -rf $(OBJDIR)
	@echo " ----- Cleaned object and dependancie files"

fclean: clean
	@echo "\033[33m \n- CLEANING EXECUTABLE FILES -\033[0m"
	@$(RM) $(NAME)
	@echo " ----- Removed Executable"

re:	fclean all

cleanly : all clean

.PHONY: all clean fclean re


