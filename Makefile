NAME = all

CC =gcc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

$(NAME): client server

client: client.c utils.c
	${CC} ${CFLAGS} client.c utils.c -o client

server: server.c utils.c
	${CC} ${CFLAGS} server.c utils.c -o server

cclean:
	${RM} client

sclean:
	${RM} server

clean: cclean sclean

fclean: clean

re : fclean all
