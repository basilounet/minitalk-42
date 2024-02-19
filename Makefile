##========== SOURCES ==========##

SRC_S = server.c
SRC_C = client.c
SRC_S_BONUS = server_bonus.c
SRC_C_BONUS = client_bonus.c

##========== OBJECTS ==========##

OBJ_S = $(SRC_S:.c=.o)
OBJ_C = $(SRC_C:.c=.o)
OBJ_S_BONUS = $(SRC_S_BONUS:.c=.o)
OBJ_C_BONUS = $(SRC_C_BONUS:.c=.o)

##========== COLORS ==========##


BASE_COLOR 	=		\033[0;39m
GRAY 		=		\033[0;90m
RED 		=		\033[0;91m
GREEN 		=		\033[0;92m
YELLOW 		=		\033[0;93m
BLUE 		=		\033[0;94m
MAGENTA		=		\033[0;95m
CYAN 		=		\033[0;96m
WHITE		=		\033[0;97m

##========== COMPILATOR ==========##

CC = clang

##========== FLAGS ==========##

CFLAGS = -Wall -Wextra -Werror -g
LDFLAGS = $(LIBS) #-fsanitize=address
LIBS := -Llibft -lft
LIBFT = libft/libft.a

##========== NAMES ==========##

SERVER = server
CLIENT = client
SERVER_BONUS = server_bonus
CLIENT_BONUS = client_bonus

all : $(LIBFT) $(SERVER) $(CLIENT)

$(SERVER) : $(OBJ_S)
		$(CC) -o $(SERVER) $(CFLAGS) $(OBJ_S) $(LDFLAGS)

$(CLIENT) : $(OBJ_C)
		$(CC) -o $(CLIENT) $(CFLAGS) $(OBJ_C) $(LDFLAGS)

bonus : $(LIBFT) $(SERVER_BONUS) $(CLIENT_BONUS)

$(SERVER_BONUS) : $(OBJ_S_BONUS)
		$(CC) -o $(SERVER_BONUS) $(CFLAGS) $(OBJ_S_BONUS) $(LDFLAGS)

$(CLIENT_BONUS) : $(OBJ_C_BONUS)
		$(CC) -o $(CLIENT_BONUS) $(CFLAGS) $(OBJ_C_BONUS) $(LDFLAGS)

$(LIBFT) :
	@$(MAKE) -C libft --no-print-directory -j4

%.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean :
	@rm -rf $(OBJ_S)
	@rm -rf $(OBJ_C)
	@rm -rf $(OBJ_S_BONUS)
	@rm -rf $(OBJ_C_BONUS)
	@$(MAKE) -C libft clean --no-print-directory

fclean : clean
	@rm -rf $(SERVER)
	@rm -rf $(CLIENT)
	@rm -rf $(SERVER_BONUS)
	@rm -rf $(CLIENT_BONUS)
	@$(MAKE) -C libft fclean --no-print-directory
	@echo "$(CYAN)Files cleaned$(BASE_COLOR)"

re : fclean all

.PHONY : all bonus clean fclean re