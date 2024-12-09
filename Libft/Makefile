# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmaria <lmaria@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/28 13:25:14 by lmaria            #+#    #+#              #
#    Updated: 2024/12/09 15:41:38 by lmaria           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY : all clean fclean re

# Nom de l'exécutable
NAME = libft.a

# Répertoires
OBJ_DIR = obj
#SRC_DIR = src

#Options de compilation
CC = cc
CFLAGS = -Wall -Werror -Wextra

# Fichiers source
LIBFT_SRC = \
	ft_atoi.c \
	ft_bzero.c \
	ft_calloc.c \
	ft_isalnum.c \
	ft_isalpha.c \
	ft_isascii.c \
	ft_isdigit.c \
	ft_isprint.c \
	ft_itoa.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_memcpy.c \
	ft_memmove.c \
	ft_memset.c \
	ft_putchar_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c \
	ft_putstr_fd.c \
	ft_split.c \
	ft_strchr.c \
	ft_strdup.c \
	ft_striteri.c \
	ft_strjoin.c \
	ft_strlcat.c \
	ft_strlcpy.c \
	ft_strlen.c \
	ft_strmapi.c \
	ft_strncmp.c \
	ft_strnstr.c \
	ft_strrchr.c \
	ft_strtrim.c \
	ft_substr.c \
	ft_tolower.c \
	ft_toupper.c \
	ft_lstadd_back_bonus.c \
    ft_lstadd_front_bonus.c \
    ft_lstclear_bonus.c \
    ft_lstdelone_bonus.c \
    ft_lstiter_bonus.c \
    ft_lstlast_bonus.c \
    ft_lstmap_bonus.c \
    ft_lstnew_bonus.c \
    ft_lstsize_bonus.c


# Fichiers objets
OBJ = $(addprefix $(OBJ_DIR)/, $(LIBFT_SRC:.c=.o))

# Règles
all : $(NAME)

$(NAME) : $(OBJ)
	@ar rcs $@ $^
	@echo "Executable $(NAME) created."

$(OBJ_DIR)/%.o : %.c Makefile libft.h | $(OBJ_DIR)
	@$(CC) -o $@ -c $< $(CFLAGS)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

print-nameexec:
	@echo $(NAME)

clean :
	@rm -rf $(OBJ_DIR)

fclean : clean
	@rm -f $(NAME)

re : fclean all
