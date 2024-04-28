NAME	 =	dogs_vs_cats

CPP		 =	c++
CPPFLAGS =	-Wall -Wextra -Werror -std=c++98

GREEN	 =	\033[0;32m
CYAN	 =	\033[0;36m
CLEAR	 =	\033[0m

OBJ_DIR  =	./objs

SRC		 =	main.cpp Animal.cpp Dog.cpp Cat.cpp Brain.cpp WrongAnimal.cpp WrongCat.cpp

OBJ		 =	$(addprefix $(OBJ_DIR)/, $(SRC:%.cpp=%.o))

# ----------------------- Makefile Rules ----------------------- #
$(NAME): $(OBJ)
	@$(CPP) $(CPPFLAGS) $(OBJ) -o $(NAME)
	@echo "$(GREEN)$(NAME) compiled!$(CLEAR)"

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	@$(CPP) $(CPPFLAGS) -c $< -o $@

all: $(NAME)

clean:
	@rm -rf $(OBJ_DIR)
	@echo "$(CYAN)Object files cleaned!$(CLEAR)"

fclean:
	@rm -f $(NAME)
	@rm -rf $(OBJ_DIR)
	@echo "$(CYAN)Executable and object files cleaned!$(CLEAR)"

re: fclean all

.PHONY: all clean fclean re