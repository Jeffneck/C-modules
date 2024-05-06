NAME		= fragtrap

CC			= c++

CFLAGS		= -Wall -Wextra -Werror -std=c++98 -g3

SRC_FILES 	=	main.cpp \
				ClapTrap.cpp \
				ScavTrap.cpp \
				FragTrap.cpp \

OBJ			= $(SRC_FILES:.cpp=.o)

INC 		= ClapTrap.hpp FragTrap.hpp ScavTrap.hpp

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
	./$(NAME)
	@make fclean

re: fclean all

.PHONY : all clean fclean re test