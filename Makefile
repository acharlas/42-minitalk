NAME = minitalk

CLIENT_SRC = srcs/client.c 
SERVER_SRC = srcs/server.c
	  
CC = clang

CLIENT_OBJ = $(CLIENT_SRC:.c=.o)
SERVER_OBJ = $(SERVER_SRC:.c=.o)

INC = includes

CFLAGS = -Wall -Wextra -Werror -I includes

all : $(NAME)

$(NAME) : $(OBJ) $(SERVER_OBJ) $(CLIENT_OBJ)
	$(CC) -o server $(OBJ) $(SERVER_OBJ) $(CFLAGS) 
	$(CC) -o client $(OBJ) $(CLIENT_OBJ) $(CFLAGS)

clean :
	rm -f $(OBJ) $(CLIENT_OBJ) $(SERVER_OBJ)

fclean : clean
	rm -f server
	rm -f client

re : fclean all