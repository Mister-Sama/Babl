GCC = gcc
EXEC = babl
SRC = $(wildcard src/*.c)
OBJ = $(SRC:.c=.o)
INCLUDE = -I ./include/
FLAG = -g -W -Wall -Werror

all:    $(EXEC)

%.o : %.c
	@$(GCC) -o $@ -c $< $(INCLUDE) $(FLAG)

$(EXEC) : $(OBJ)
	@$(CC) -o $@ $^ $(FLAG)

fclean:
	@rm -rf $(EXEC) src/*o src/*~ include/*~ *~
	@rm -rf $(EXEC)
re: fclean all


