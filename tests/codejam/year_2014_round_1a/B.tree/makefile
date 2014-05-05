NAME = b

all:
	g++ -O2 -I/usr/include/g++/4.4/ -I../../../../inc/ -o $(NAME) $(NAME).cc -W -Wall -Wextra -std=c++11

test:
	@./$(NAME) < test.in

small:
	@./$(NAME) < small.in

large:
	@./$(NAME) < large.in

run:
	@./$(NAME)
