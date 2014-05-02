GCC   := g++
CFLAG := -fmudflap
LFLAG := -lmudflap
OFLAG := -O2
WARN  := -W -Wall -Wextra
INC   := -I/usr/include/g++/4.4/
EXE   := kolapp2

all:
	$(GCC) $(OFLAG) $(CFLAG) $(INC) -o $(EXE) $(EXE).c mytime.c $(WARN) $(LFLAG)

run:
	./$(EXE) < indata.txt | tee outdata.txt
