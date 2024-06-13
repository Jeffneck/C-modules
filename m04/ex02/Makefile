NAME		= animals

CC			= c++

CFLAGS		= -std=c++98 -g3 -Wall -Wextra -Werror

SRC_FILES 	=	main.cpp \
				AAnimal.cpp \
				Brain.cpp \
				Cat.cpp \
				Dog.cpp \

INC			=	Animal.hpp \
				AAnimal.hpp \
				Brain.hpp \
				Cat.hpp \
				Dog.hpp \

OBJ			= $(SRC_FILES:.cpp=.o)

%.o   : %.cpp $(INC)
	${CC} ${CFLAGS} -c $< -o $@ -I.

all: $(NAME)

$(NAME): $(OBJ)
	@echo -n Compiling executable $(NAME)...
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ)
	@echo Done.

clean:
	@echo -n Making clean...
	@rm -rf $(OBJ)
	@echo Done.

fclean: clean
	@echo -n Making fclean...
	@rm -f $(NAME)
	@echo Done.

test: re
	valgrind ./$(NAME)
	@make fclean

re: fclean all

.PHONY : all clean fclean re test