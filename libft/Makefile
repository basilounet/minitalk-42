##========== SOURCES ==========##

SRC = ft_abs.c \
	ft_atoi.c \
	ft_atoi_base.c \
	ft_bzero.c \
	ft_calloc.c \
	ft_countc.c \
	ft_isalnum.c \
	ft_isalpha.c \
	ft_isascii.c \
	ft_isdigit.c \
	ft_isprint.c \
	ft_itoa.c \
	ft_itob.c \
	ft_lennum.c \
	ft_lst_getel.c \
	ft_lst_getindex.c \
	ft_lstadd_back.c \
	ft_lstadd_front.c \
	ft_lstclear.c \
	ft_lstdelone.c \
	ft_lstiter.c \
	ft_lstlast.c \
	ft_lstmap.c \
	ft_lstnew.c \
	ft_lstsize.c \
	ft_map.c \
	ft_max.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_memcpy.c \
	ft_memmove.c \
	ft_memset.c \
	ft_mod.c \
	ft_numbers_of_lines.c \
	ft_power.c \
	ft_printf.c \
	ft_putchar_fd.c \
	ft_putchar.c \
	ft_putendl_fd.c \
	ft_putendl.c \
	ft_putmalloc.c \
	ft_putnbr_fd.c \
	ft_putnbr.c \
	ft_putnbru.c \
	ft_putptr.c \
	ft_putstr_fd.c \
	ft_putstr.c \
	ft_rand.c \
	ft_split.c \
	ft_split_plus.c \
	ft_strcat.c \
	ft_strchr.c \
	ft_strdup.c \
	ft_striteri.c \
	ft_strjoin.c \
	ft_strlcat.c \
	ft_strlcpy.c \
	ft_strlen.c \
	ft_strmapi.c \
	ft_strncmp.c \
	ft_strncpy.c \
	ft_strnstr.c \
	ft_strrchr.c \
	ft_strtrim.c \
	ft_substr.c \
	ft_tolower.c \
	ft_toupper.c \
	get_next_line_bonus.c

##========== OBJECTS ==========##

OBJ = $(SRC:.c=.o)

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
NAME = libft.a

all : $(NAME)

$(NAME) : $(OBJ)
	@ar rcs $(NAME) $(OBJ)

%.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean :
	@rm -rf $(OBJ)

fclean : clean
	@rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re