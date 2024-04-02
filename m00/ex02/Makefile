NAME		= account

CC			= c++

CFLAGS		= -Wall -Wextra -Werror -std=c++98

SRC_FILES 	=	tests.cpp Account.cpp

OBJ			= $(SRC_FILES:.cpp=.o)

.cpp.o: $(NAME)
	${CC} ${CFLAGS} -c -I. $< -o ${<:.cpp=.o}

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

re: fclean all

test: $(NAME)
		@echo "index:0;amount:42;created\nindex:1;amount:54;created\nindex:2;amount:957;created\nindex:3;amount:432;created\nindex:4;amount:1234;created\nindex:5;amount:0;created\nindex:6;amount:754;created\nindex:7;amount:16576;created\naccounts:8;total:20049;deposits:0;withdrawals:0\nindex:0;amount:42;deposits:0;withdrawals:0\nindex:1;amount:54;deposits:0;withdrawals:0\nindex:2;amount:957;deposits:0;withdrawals:0\nindex:3;amount:432;deposits:0;withdrawals:0\nindex:4;amount:1234;deposits:0;withdrawals:0\nindex:5;amount:0;deposits:0;withdrawals:0\nindex:6;amount:754;deposits:0;withdrawals:0\nindex:7;amount:16576;deposits:0;withdrawals:0\nindex:0;p_amount:42;deposit:5;amount:47;nb_deposits:1\nindex:1;p_amount:54;deposit:765;amount:819;nb_deposits:1\nindex:2;p_amount:957;deposit:564;amount:1521;nb_deposits:1\nindex:3;p_amount:432;deposit:2;amount:434;nb_deposits:1\nindex:4;p_amount:1234;deposit:87;amount:1321;nb_deposits:1\nindex:5;p_amount:0;deposit:23;amount:23;nb_deposits:1\nindex:6;p_amount:754;deposit:9;amount:763;nb_deposits:1\nindex:7;p_amount:16576;deposit:20;amount:16596;nb_deposits:1\naccounts:8;total:21524;deposits:8;withdrawals:0\nindex:0;amount:47;deposits:1;withdrawals:0\nindex:1;amount:819;deposits:1;withdrawals:0\nindex:2;amount:1521;deposits:1;withdrawals:0\nindex:3;amount:434;deposits:1;withdrawals:0\nindex:4;amount:1321;deposits:1;withdrawals:0\nindex:5;amount:23;deposits:1;withdrawals:0\nindex:6;amount:763;deposits:1;withdrawals:0\nindex:7;amount:16596;deposits:1;withdrawals:0\nindex:0;p_amount:47;withdrawal:refused\nindex:1;p_amount:819;withdrawal:34;amount:785;nb_withdrawals:1\nindex:2;p_amount:1521;withdrawal:657;amount:864;nb_withdrawals:1\nindex:3;p_amount:434;withdrawal:4;amount:430;nb_withdrawals:1\nindex:4;p_amount:1321;withdrawal:76;amount:1245;nb_withdrawals:1\nindex:5;p_amount:23;withdrawal:refused\nindex:6;p_amount:763;withdrawal:657;amount:106;nb_withdrawals:1\nindex:7;p_amount:16596;withdrawal:7654;amount:8942;nb_withdrawals:1\naccounts:8;total:12442;deposits:8;withdrawals:6\nindex:0;amount:47;deposits:1;withdrawals:0\nindex:1;amount:785;deposits:1;withdrawals:1\nindex:2;amount:864;deposits:1;withdrawals:1\nindex:3;amount:430;deposits:1;withdrawals:1\nindex:4;amount:1245;deposits:1;withdrawals:1\nindex:5;amount:23;deposits:1;withdrawals:0\nindex:6;amount:106;deposits:1;withdrawals:1\nindex:7;amount:8942;deposits:1;withdrawals:1\nindex:0;amount:47;closed\nindex:1;amount:785;closed\nindex:2;amount:864;closed\nindex:3;amount:430;closed\nindex:4;amount:1245;closed\nindex:5;amount:23;closed\nindex:6;amount:106;closed\nindex:7;amount:8942;closed" > test.log;
		@./$(NAME) | cut -d' ' -f2 > mytest.log
		-diff mytest.log test.log
		@rm mytest.log test.log

.PHONY : all clean fclean re test
