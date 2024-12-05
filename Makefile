# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmaria <lmaria@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/05 14:17:12 by lmaria            #+#    #+#              #
#    Updated: 2024/12/05 14:24:34 by lmaria           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all compile_submake clean fclean

# Nom de l'exécutable
NAME = libft.a

# Nom du Makefile à compiler
SUBMAKEFILE = Libft/Makefile

# Répertoires
OBJ_DIR = obj

#Options de compilation
CC = cc
CFLAGS = -Wall -Werror -Wextra


# Fichiers source
PRINTF_SRC  = \

# Fichiers objets
OBJ = $(addprefix $(OBJ_DIR)/, $(LIBFT_SRC:.c=.o))




# Règles
all: $(NAME) compile_submake

$(NAME) : $(OBJ)
	@ar rcs $@ $^
	@echo "Executable $(NAME) created."

# Règle pour appeler un autre Makefile
compile_submake:
	@echo "Compilation du Makefile: $(SUBMAKEFILE)"
	$(MAKE) -f $(SUBMAKEFILE)

# Nettoyer les fichiers générés par le Makefile secondaire
clean_libft:
	@echo "Nettoyage des fichiers générés par $(SUBMAKEFILE)"
	$(MAKE) -f $(SUBMAKEFILE) clean

# Nettoyage général
fclean: clean
	@echo "Nettoyage complet terminé."
