NAME		= fixed_better

CC			= c++

CFLAGS		= -Wall -Wextra -Werror -std=c++98

SRC_FILES 	=	main.cpp \
				Fixed.cpp \

INC			= Fixed.hpp

OBJ			= $(SRC_FILES:.cpp=.o)

%.o   : %.cpp $(INC)
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

test: re
	./$(NAME) > output_prog.txt
	@echo "\n\n"
	diff output_prog.txt output_wanted.txt
	@rm output_prog.txt output_wanted.txt
	@make fclean

re: fclean all

.PHONY : all clean fclean re test