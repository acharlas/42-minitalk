NAME = minitalk

SRCS = srcs/ft_atoi.c \
		srcs/ft_bzero.c \
		srcs/ft_isdigit.c \
		srcs/ft_strlen.c \
		srcs/ft_memset.c \
		srcs/ft_itoa.c

CLIENT_SRC = srcs/client.c 
SERVER_SRC = srcs/server.c	  
CC = clang

OBJ = $(SRCS:.c=.o)
CLIENT_OBJ = $(CLIENT_SRC:.c=.o)
SERVER_OBJ = $(SERVER_SRC:.c=.o)


INC = includes

CFLAGS = -Wall -Wextra -Werror -g3 -I includes

all : $(NAME)

server : $(SERVER_OBJ)
	$(CC) -o server $(OBJ) $(SERVER_OBJ) $(CFLAGS)
client : $(CLIENT_OBJ)
	$(CC) -o client $(OBJ) $(CLIENT_OBJ) $(CFLAGS)

$(NAME) : $(OBJ) server client

clean :
	rm -f $(OBJ) $(CLIENT_OBJ) $(SERVER_OBJ)

fclean : clean
	rm -f server
	rm -f client

re : fclean all