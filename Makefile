NAME = minitalk

CLIENT_SRC = srcs/client.c 
SERVER_SRC = srcs/server.c
	  
CC = clang

CLIENT_OBJ = $(CLIENT_SRC:.c=.o)
SERVER_OBJ = $(SERVER_SRC:.c=.o)

OBJ_BONUS = $(SRC_BONUS:.c=.o)

INC = includes

CFLAGS = -Wall -Wextra -Werror -I includes

all : $(NAME)

$(NAME) : libft $(OBJ) $(SERVER_OBJ) $(CLIENT_OBJ)
	$(CC) -o server $(OBJ) $(SERVER_OBJ) $(LDFLAGS) 
	$(CC) -o client $(OBJ) $(CLIENT_OBJ) $(LDFLAGS)

clean :
	rm -f $(OBJ) $(OBJ_CLIENT) $(OBJ_SERVER)

fclean : clean
	rm -f server
	rm -f client

re : fclean all