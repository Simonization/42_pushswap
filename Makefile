# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: slangero <slangero@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/15 13:47:33 by slangero          #+#    #+#              #
#    Updated: 2024/10/15 17:00:10 by slangero         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#-------------------------PROGRAM NAME------------------------#
NAME 				= tinyshell
all: 				$(NAME)
MAKEFLAGS 			= --no-print-directory

#---------------------------COMPILER--------------------------#
CC					=	cc
CFLAGS				=	-Wall -Wextra -Werror
CFLAGS				+=	-g3
COMPILER			=	$(CC) $(CFLAGS)
LINKER				=	$(CC) $(CFLAGS)

#-------------------------SOURCE FILES------------------------#
SRC_DIR				=	src
SRC_SUBDIRS			=	$(shell find $(SRC_DIR)/* -type d)
SRC_FILES			=	$(shell find $(SRC_DIR) -type f -name "*.c")

#-------------------------OBJECT FILES------------------------#
OBJ_DIR				=	obj
OBJ_SUBDIRS			=	$(SRC_SUBDIRS:$(SRC_DIR)%=$(OBJ_DIR)%)
OBJ_FILES			=	$(SRC_FILES:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)

$(OBJ_DIR)/%.o:	$(SRC_DIR)/%.c 
	@mkdir -p $(@D) 
	$(COMPILER) $(CPPFLAGS) -c $< -o $@
	
#----------------------------HEADERS--------------------------#
INC_DIR				=	include
CPPFLAGS			+=	-I$(INC_DIR)
CPPFLAGS			+=	-I$(LIBFT_DIR)/$(INC_DIR)

#---------------------------LIBRARIES-------------------------#
LIBFT_DIR			=	libft
LIBFT				=	$(LIBFT_DIR)/libft.a
LIBFLAGS			=	-L$(LIBFT_DIR) -lft
libft:					$(LIBFT)
$(LIBFT):
	@echo "LIBFT being created"
	@$(MAKE) -C $(LIBFT_DIR) all
	
#---------------------------LINKING---------------------------#
$(NAME):	$(LIBFT) $(OBJ_FILES)
	$(LINKER) $(OBJ_FILES) $(LIBFLAGS) -o $@

#---------------------------CLEANING--------------------------#
clean:
	@rm -rf $(OBJ_DIR)
fclean:		clean
	@rm -rf $(NAME)
	@echo  "$(NAME) fully cleaned"
re:		fclean all

libclean:
	@$(MAKE) -C $(LIBFT_DIR) fclean
libre:		libclean libft

ffclean:	fclean libclean
fre:		ffclean re

.PHONY: all libft clean fclean re libclean libre ffclean fre
#-------------------------------------------------------------#