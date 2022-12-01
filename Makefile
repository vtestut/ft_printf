###########################################################
#### NAME

NAME			= libftprintf.a

###########################################################
#### PATH TO SOURCES

PATH_SRCS 		+= srcs/

###########################################################
#### SOURCES

SRCS			+=	ft_printf.c
#SRCS			+=	ft_print_connvertors.c

vpath %.c $(PATH_SRCS)

###########################################################
#### OBJS

PATH_OBJS		= objs
OBJS			= $(patsubst %.c, $(PATH_OBJS)/%.o, $(SRCS))

###########################################################
#### LIBRARY

LIBFT_PATH 		= A.Libft/
LIBFT 			= $(LIBFT_PATH)/libft.a

###########################################################
#### INCLUDES

INCLUDES 		= includes/
INCLUDES_LIB	= $(LIBFT_PATH)/includes/
HEADER			= includes/ft_printf.h

###########################################################
#### COMPILATION

CC				= cc
CFLAGS			= -Wall -Wextra -Werror

###########################################################
#### RULES

all : $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	cp $(LIBFT) $(NAME)
	ar rcs $(NAME) $(OBJS)

$(LIBFT):
	$(MAKE) -sC $(LIBFT_PATH)

$(OBJS): $(PATH_OBJS)/%.o: %.c $(HEADER)
	@mkdir -p $(PATH_OBJS)
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INCLUDES) -I $(INCLUDES_LIB)

clean:
	$(RM) -R $(PATH_OBJS)
	$(MAKE) -sC $(LIBFT_PATH) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -sC $(LIBFT_PATH) fclean

re: fclean
	$(MAKE)

del: fclean
	rm a.out

test: 
	@ $(CC) srcs/*.c $(NAME) && ./a.out | cat -e

full_test: fclean all test

norm:
	@norminette $(PATH_SRCS) $(INCLUDES)

.PHONY: all clean fclean re del test full_test

# variables spéciales
# $@ fait référence au nom de la cible
# $< nom première dépendance
# $^ liste dépendance
# $? liste dépendance plus récentes que la cible
# $* nom fichier, sans son extension
# CIBLE > DEPENDANCES > REGLES

