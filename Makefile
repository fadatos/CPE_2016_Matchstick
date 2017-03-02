##
## Makefile for Makefile in /home/fadatos
## 
## Made by Titouan Albouy
## Login   <Titouan.albouy@epitech.net>
## 
## Started on  Wed Feb 15 11:38:54 2017 albouy titouan
## Last update Mon Feb 27 12:15:40 2017 albouy titouan
##

CC	=	@gcc
#CFLAGS	+=	-W -Wall
#CFLAGS	+=	-ansi -pedantic
CFLAGS	+=	-I./include

#LDFLAGS	+=	-lmy -lprintf -L./libs

RM	=	@rm -f

NAME	=	matchstick

DIR	=	./srcs/
SRCS	=	main.c\
		fonction_lib_1.c\
		fonction_lib_2.c\
		fonction_lib_3.c\
		fonction_lib_4.c\
		gestion_error.c\
		get_next_line.c\
		ia_value.c\
		init_map.c\
		loop_game.c\
		modif_map_game.c\
		player_value.c\
		round_player.c\
		win_player.c\

OBJS	=	$(foreach SRCS,$(SRCS),$(DIR)$(SRCS:.c=.o))


all:	$(NAME)

$(NAME):$(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(LDFLAGS) $(CFLAGS)

create:
	@mkdir srcs includes libs
clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
