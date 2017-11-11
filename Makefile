# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/16 23:26:49 by fhuang            #+#    #+#              #
#    Updated: 2017/11/11 19:04:36 by fhuang           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ===== Editable =====
NAME	:=	lem_in
# ====================

# ===== Subdirectories =====
ROOMDIR	:=	room/
TUBEDIR	:=	tube/
# ==========================

# ===== Standard =====
CC		:=	clang -pipe
CFLAGS	:=	-Wall -Wextra -Werror -g3
SRCDIR	:=	src/
OBJDIR	:=	obj/
BINDIR	:=	bin/
INCDIR	:=	include/
LIBFT	:=	libft/
LIBDIR	:=	lib/
SRC		:=	main.c					\
			init_game.c				\
			clear_game.c			\
			get_command_enum.c		\
			get_command_name.c		\
			handle_line.c			\
			is_command.c			\
			is_comment.c			\
			is_game_ready.c			\
			is_room.c				\
			is_tube.c				\
			read_nb_ants.c			\
			$(ROOMDIR)add.c			\
			$(ROOMDIR)delete_all.c	\
			$(ROOMDIR)find.c		\
			$(ROOMDIR)find_with_coordinates.c	\
			$(ROOMDIR)add_destination.c	\
			$(TUBEDIR)add.c			\
			$(TUBEDIR)delete_all.c	\
			$(TUBEDIR)find.c
OBJ		:=	$(SRC:%.c=$(OBJDIR)%.o)
INC		:=	-I./$(INCDIR) -I./$(LIBFT)$(INCDIR)
LIBPATH	:=	-L./$(LIBFT)$(LIBDIR) -lft -lftprintf
CACHEF	:=	.cache_exists
# ====================

# ====== Colors ======
CLEAR		= "\033[2K"
UP			= "\033[A"
EOC			= "\033[0;0m"
BLACK		= "\033[0;30m"
RED			= "\033[0;31m"
GREEN		= "\033[0;32m"
YELLOW		= "\033[0;33m"
BLUE		= "\033[0;34m"
PURPLE		= "\033[0;35m"
CYAN		= "\033[0;36m"
WHITE		= "\033[0;37m"
# ====================

.PHONY: all libft norme clean fclean re
.SILENT:

all: libft $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $@ $(LIBPATH) $(INC)
	printf $(BLUE)" $@ compiled!\n"$(EOC)

$(OBJDIR)%.o: $(SRCDIR)%.c $(CACHEF)
	$(CC) $(CFLAGS) -c  $< -o $@ $(INC)
	printf $(BLUE)"|"$(EOC)

$(CACHEF):
	test -d $(OBJDIR) || mkdir $(OBJDIR)
	test -d $(OBJDIR)$(ROOMDIR) || mkdir $(OBJDIR)$(ROOMDIR)
	test -d $(OBJDIR)$(TUBEDIR) || mkdir $(OBJDIR)$(TUBEDIR)
	test -d $(CACHEF) || touch $(CACHEF)

%.c:
	printf $(RED)"Missing file : $@\n"$(EOC)

libft:
	make -C $(LIBFT)

norme:
	norminette $(SRCDIR) $(INCDIR) | grep -v Norme -B1 || true
	norminette $(LIBFT)$(SRCDIR) $(LIBFT)$(INCDIR) | grep -v Norme -B1 || true

clean:
	make clean -C $(LIBFT)
	rm -rf $(OBJDIR) $(CACHEF)
	printf $(YELLOW)"All objects removed\n"$(EOC)

fclean: clean
	make fclean -C $(LIBFT)
	rm -f $(NAME)
	printf $(RED)"$(NAME) removed\n"$(EOC)

re: fclean all
