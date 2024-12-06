# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmaria <lmaria@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/05 14:17:12 by lmaria            #+#    #+#              #
#    Updated: 2024/12/06 19:24:29 by lmaria           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all compile_submake clean fclean

# Nom de l'exécutable
NAME = libftprintf.a

# Nom du Makefile à compiler
SUBMAKEFILE = Libft/Makefile

MAKEFILE = ft_printf/Makefile

# Répertoires
OBJ_DIR = obj

#Options de compilation
CC = cc
CFLAGS = -Wall -Werror -Wextra

# Fichiers source
PRINTF_SRC  = \
	ft_printf.c \
	ft_printf_utils.c

# Fichiers objets
OBJ = $(addprefix $(OBJ_DIR)/, $(PRINTF_SRC:.c=.o))

# Règles
all: $(NAME) compile_submake

$(NAME) : $(OBJ)
	@ar rcs $@ $^
	@echo "Executable $(NAME) created."
	
$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

# Règle pour appeler un autre Makefile
compile_submake:
	@echo "Compiling the Makefile : $(SUBMAKEFILE)"
	@$(MAKE) --no-print-directory -C Libft



# Nettoyage général
clean: clean_libft
	@echo "Cleaning object files generated by $(SUBMAKEFILE) and $(MAKEFILE)."
	@rm -rf $(OBJ_DIR)

# Nettoyer les fichiers générés par le Makefile secondaire
clean_libft:
	@$(MAKE) --no-print-directory -C Libft clean

fclean: clean fclean_libft
	@echo "Complete cleanup (including$(SUBMAKEFILE) and $(MAKEFILE))."
	@rm -f $(NAME)

fclean_libft:
	@$(MAKE) --no-print-directory -C Libft fclean

re: fclean all
