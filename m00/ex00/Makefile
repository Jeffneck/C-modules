NAME		= megaphone

CC			= c++

CFLAGS		= -Wall -Wextra -Werror -std=c++98

SRC_FILES 	=	megaphone.cpp

OBJ			= $(SRC_FILES:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@echo -n "Compiling executable $(NAME)..."
	@$(CC) $(CFLAGS) $(OBJ) -I. -o $(NAME)
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

test: $(NAME)
	./megaphone "shhhhh... I think the students are asleep..."
	./megaphone Damnit " ! " "Sorry students, I thought this thing was off."
	./megaphone

re: fclean all

.PHONY : all clean fclean re test