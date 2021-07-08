CLIENT = client
SERVER = server

CLIENT_SRC = srcs/client.c 
SERVER_SRC = srcs/server.c
	  
CC = clang

CLIENT_OBJ = $(CLIENT_SRC:.c=.o)
SERVER_OBJ = $(SERVER_SRC:.c=.o)

OBJ_BONUS = $(SRC_BONUS:.c=.o)

INC = includes


CFLAGS = -Wall -Wextra -g3 -lm -I includes

all : $(CLIENT) $(SERVER)

$(CLIENT) : $(CLIENT_OBJ)
	$(CC) -o $(CLIENT) $(CLIENT_OBJ) $(CFLAGS)

$(SERVER) : $(SERVER_OBJ)
	$(CC) -o $(SERVER) $(SERVER_OBJ) $(CFLAGS)




clean :
	rm -f $(CLIENT_OBJ) $(SERVER_OBJ) $(OBJ_BONUS)

fclean : clean
	rm -f $(CLIENT)
	rm -f $(SERVER)

re : fclean all