##
## EPITECH PROJECT, 2025
## pokemon_red
## File description:
## Binary Makefile
##

SRC	= \
	src/main.c	\
	\
	src/logger/logger.c	\
	src/logger/type/info.c	\
	\
	src/event/event_destroyer.c	\
	src/event/event_dumper.c	\
	src/event/event_processor.c	\
	src/event/event_registor.c	\
	\
	src/game_loader.c	\
	src/game_destroyer.c	\
	\
	src/printf/my_asprintf.c	\
	src/printf/my_asvprintf.c	\
	\
	src/util/file_util.c	\
	src/util/string_util.c

INCLUDE	=	-iquote./include -iquote./include/util

WARNING	=	-Wall -Wextra

CFLAGS	= 	$(WARNING) $(INCLUDE) -g

OBJ		= 	$(SRC:src/%.c=build/obj/%.o)

LIBS	=	-lcsfml-window -lcsfml-graphics -lcsfml-system

NAME	= 	PokemonRed

build/obj/%.o : src/%.c
	@mkdir -p $@
	@rmdir $@
	@echo "\e[94mCompiled [\e[95m$@\e[94m]\n"\
		"    |-> using [\e[90m$(CFLAGS)\e[94m]\e[0m"
	@$(CC) -c -o "$@" $(CFLAGS) "$<"

all: $(NAME)

re: fclean $(NAME)

$(NAME): $(OBJ)
	@mkdir -p build/out/
	@echo
	@echo "\e[32mCompiling \e[31m.o \e[32mto executable binary:\e[90m"
	gcc -o build/out/$(NAME) $(OBJ) $(INCLUDE) $(LIBS)
	@echo "\033[A\e[0m"
	@cp build/out/$(NAME) .

clean:
	@echo "\e[92mRemove following directory: [\e[90mbuild/obj\e[92m]"
	@rm -rf build/obj/

fclean:
	@echo "\e[92mRemove following directory: [\e[90mbuild\e[92m]"
	@rm -rf build/

	@echo "\e[92mRemove following file: [\e[90m$(NAME), *.gcda, *.gcdo\e[92m]"
	@rm -f $(NAME) *.gcda *.gcdo

run: re
	@echo "\e[32mStarting \e[31m$(NAME)\e[32m.\e[0m"
	@./PokemonRed

vrun: re
	@echo "\e[32mStarting \e[31m$(NAME)\e[32m with \e[31mvalgrind\e[32m.\e[0m"
	@valgrind ./PokemonRed
