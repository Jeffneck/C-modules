NAME		= sed_is_for_loosers

CC			= c++

CFLAGS		= -Wall -Wextra -Werror -std=c++98

SRC_FILES 	=	main.cpp \
				Harl.cpp \

OBJ			= $(SRC_FILES:.cpp=.o)

%.o   : %.cpp
	${CC} ${CFLAGS} -c -I. $< -o $@

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

test: $(NAME)
	./$(NAME) main.cpp std SED

re: fclean all

.PHONY : all clean fclean re test