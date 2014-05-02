NAME = a

all:
	g++ -O2 -I/usr/include/g++/4.4/ -o $(NAME) $(NAME).cc -W -Wall -Wextra

test:
	@./$(NAME) < test.in

small:
	@./$(NAME) < small.in

large:
	@./$(NAME) < large.in

run:
	@./$(NAME)
