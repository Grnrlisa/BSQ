##
## EPITECH PROJECT, 2021
## B-CPE-110-REN-1-1-BSQ-lisa.garnier
## File description:
## Makefile
##

## Sources of the prog
SRC	=	sources/main.c 				\
		sources/display.c 			\
		sources/find_sizes.c 		\
		sources/bsq.c 				\
		sources/transform_map.c 	\
		sources/errors.c

OBJ = $(SRC:.c=.o)

NAME =	bsq

LIB = -L lib/ -lmy

INCLUDE = -I include/

## Compilation flags (auto pick-up)
CFLAGS = -Wall -Werror -W $(INCLUDE)

## Make commande
all:	mylib $(OBJ)
	gcc -o $(NAME) $(SRC) $(INCLUDE) $(LIB)

mylib:
	make -C lib/my/

## clean commande : rm files object
clean:
	rm -f $(OBJ)
	make clean -C lib/my/


## fclean commande : rm binary
fclean:
	rm -f $(NAME)
	make clean
	make fclean -C lib/my/


## re commande : remake after cleaning
re:
	make fclean
	make all


.PHONY: clean, fclean, re, all