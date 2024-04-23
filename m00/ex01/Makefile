NAME		= phonebook_app

CC			= c++

CFLAGS		= -Wall -Wextra -Werror -std=c++98

SRC_FILES 	=	main.cpp Contact.cpp PhoneBook.cpp

INC 		=	Contact.hpp PhoneBook.hpp

OBJ			= $(SRC_FILES:.cpp=.o)


all: $(NAME)

$(NAME): $(OBJ)
	@echo -n "Compiling executable $(NAME)..."
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)
	@echo "Done."

%.o : %.cpp $(INC)
	${CC} ${CFLAGS} -c $< -o $@

clean:
	@echo -n Making clean...
	@rm -rf $(OBJ)
	@echo Done.

fclean: clean
	@echo -n Making fclean...
	@rm -f $(NAME)
	@echo Done.

re: fclean all

.PHONY : all clean fclean re