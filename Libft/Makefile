# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmaria <lmaria@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/28 13:25:14 by lmaria            #+#    #+#              #
#    Updated: 2024/12/10 13:15:40 by lmaria           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY : all clean fclean re

# Nom de l'exécutable
NAME = libft.a

# Répertoires
OBJS_DIR = obj/
SRCS_DIR = srcs/

#Options de compilation
CC = cc
CFLAGS = -Wall -Werror -Wextra

# Source Files
LST_SRCS = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
	ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c \
	ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c \
	ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c \
	ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c \
	ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c \
	ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c ft_lstadd_back.c \
    ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c ft_lstiter.c \
	ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c


# Fichiers objets
SRCS = $(addprefix $(SRCS_DIR), $(LST_SRCS))
OBJS = $(addprefix $(OBJS_DIR), $(LST_SRCS:.c=.o))

# Règles
all : $(NAME)

$(NAME) : $(OBJS)
	@ar rcs $@ $^
	@echo "Executable $(NAME) created."

$(OBJS_DIR)%.o : $(SRCS_DIR)%.c Makefile libft.h | $(OBJS_DIR)
	@$(CC) -o $@ -c $< $(CFLAGS)

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

print-nameexec:
	@echo $(NAME)

clean :
	@rm -rf $(OBJS_DIR)

fclean : clean
	@rm -f $(NAME)

re : fclean all
