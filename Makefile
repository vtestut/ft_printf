###########################################################
#### NAME

NAME			= libftprintf.a

###########################################################
#### PATH TO SOURCES

PATH_SRCS 		+= srcs/

###########################################################
#### SOURCES

SRCS			+=	ft_printf.c

vpath %.c $(PATH_SRCS)

###########################################################
#### OBJS

PATH_OBJS		= objs
OBJS			= $(patsubst %.c, $(PATH_OBJS)/%.o, $(SRCS))

###########################################################
#### LIBRARY

LIB_FOLDER 		= A.Libft/
LIB 			= $(LIB_FOLDER)/libft.a

###########################################################
#### INCLUDES

INCLUDES 		= includes/
INCLUDES_LIB	= $(LIB_FOLDER)/includes/
HEADER			= includes/ft_printf.h

###########################################################
#### COMPILATION

CC				= cc
CFLAGS			= -Wall -Wextra -Werror

###########################################################
#### RULES

EXEC = prog

all : $(NAME)

$(NAME): $(LIB) $(OBJS)
	cp $(LIB) $(NAME)
	ar rcs $(NAME) $(OBJS)

$(LIB):
	$(MAKE) -sC $(LIB_FOLDER)

$(OBJS): $(PATH_OBJS)/%.o: %.c $(HEADER)
	@mkdir -p $(PATH_OBJS)
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INCLUDES) -I $(INCLUDES_LIB)

clean:
	$(RM) -R $(PATH_OBJS)
	$(MAKE) -sC $(LIB_FOLDER) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -sC $(LIB_FOLDER) fclean

re: fclean
	$(MAKE)

norm:
	@norminette $(PATH_SRCS) $(INCLUDES)

.PHONY: all clean fclean re

# variables spéciales
# $@ fait référence au nom de la cible
# $< nom première dépendance
# $^ liste dépendance
# $? liste dépendance plus récentes que la cible
# $* nom fichier, sans son extension
# CIBLE > DEPENDANCES > REGLES