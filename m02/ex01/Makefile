NAME		= fixed

CC			= c++

CFLAGS		= -Wall -Wextra -Werror -std=c++98

SRC_FILES 	=	main.cpp \
				Fixed.cpp \

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
	./$(NAME)
	@echo "\n\n"
	./$(NAME) "I am not sure how tired I am today..."
	@echo "\n\n"
	./$(NAME) "DEBUG"
	@echo "\n\n"
	./$(NAME) "INFO"
	@echo "\n\n"
	./$(NAME) "WARNING"
	@echo "\n\n"
	./$(NAME) "ERROR"

re: fclean all

.PHONY : all clean fclean re test