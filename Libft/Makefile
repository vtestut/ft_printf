###########################################################
#### NAME

NAME = libft.a

###########################################################
#### PATH TO SOURCES

PATH_SRCS += srcs/
PATH_SRCS += srcs/conv/
PATH_SRCS += srcs/ctype/
PATH_SRCS += srcs/list/
PATH_SRCS += srcs/memory/
PATH_SRCS += srcs/output/
PATH_SRCS += srcs/strings/

###########################################################
#### SOURCES

SRCS += ft_atoi.c
SRCS += ft_bzero.c
SRCS += ft_calloc.c
SRCS += ft_isalnum.c
SRCS += ft_isalpha.c
SRCS += ft_isascii.c 
SRCS += ft_isdigit.c
SRCS += ft_isprint.c
SRCS += ft_memchr.c
SRCS += ft_memcmp.c
SRCS += ft_memcpy.c
SRCS += ft_memmove.c
SRCS += ft_memset.c
SRCS += ft_putchar_fd.c
SRCS += ft_putendl_fd.c 
SRCS += ft_putnbr_fd.c
SRCS += ft_putstr_fd.c
SRCS += ft_strchr.c
SRCS += ft_strdup.c
SRCS += ft_striteri.c
SRCS += ft_strjoin.c
SRCS += ft_strlcat.c
SRCS += ft_strlcpy.c
SRCS += ft_strlen.c
SRCS += ft_strmapi.c
SRCS += ft_strncmp.c
SRCS += ft_strnstr.c
SRCS += ft_strrchr.c
SRCS += ft_strtrim.c
SRCS += ft_substr.c
SRCS += ft_tolower.c
SRCS += ft_toupper.c
SRCS += ft_itoa.c
SRCS += ft_split.c
SRCS += ft_putchar.c
SRCS += ft_putstr.c 
SRCS += ft_lstnew.c
SRCS += ft_lstadd_front.c
SRCS += ft_lstsize.c
SRCS += ft_lstlast.c
SRCS += ft_lstadd_back.c
SRCS += ft_lstdelone.c
SRCS += ft_lstclear.c
SRCS += ft_lstiter.c
SRCS += ft_lstmap.c
SRCS += ft_putnbr.c
SRCS += ft_putlong.c
SRCS += ft_intlen.c
SRCS += ft_longlen.c

##ifeq (bonus, $(findstring bonus, $(MAKECMDGOALS)))
##  SRCS += $(BONUS) 
##endif

vpath %.c $(PATH_SRCS)

###########################################################
#### OBJS

PATH_OBJS		= objs
OBJS			= $(patsubst %.c, $(PATH_OBJS)/%.o, $(SRCS))

###########################################################
#### INCLUDES

INCLUDES += includes/
HEADER += $(INCLUDES)/libft.h

###########################################################
#### COMPILATION

CFLAGS = -Wall -Wextra -Werror 
CC = cc
AR = ar rcs

###########################################################
#### RULES

all: $(NAME)

bonus: $(NAME)

$(NAME): $(OBJS)
	$(AR) $@ $^

$(OBJS): $(PATH_OBJS)/%.o: %.c $(HEADER)
	@mkdir -p $(PATH_OBJS)
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INCLUDES)

clean:
	 $(RM) -R $(PATH_OBJS)

fclean: clean
	rm -rf $(NAME)	

re: fclean all

# variables spéciales
# $@ fait référence au nom de la cible
# $< nom première dépendance
# $^ liste dépendance
# $? liste dépendance plus récentes que la cible
# $* nom fichier, sans son extension
# CIBLES > DEPENDANCES > REGLES
