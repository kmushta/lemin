# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kmushta <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/01 16:56:19 by kmushta           #+#    #+#              #
#    Updated: 2018/03/01 16:56:22 by kmushta          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := lem-in
NAME2 := visu-hex

SRC_DIR := ./src/
OBJ_DIR := ./obj/
INC_DIR := ./inc/
LIB_DIR := ./lib/

SRC := main.c errors.c utils.c readers.c print_arrays.c rooms.c room_adds.c \
	ways.c lemin.c algo.c spec_utils.c

SRC2 := errors.c utils.c readers.c print_arrays.c rooms.c room_adds.c \
	ways.c lemin.c algo.c spec_utils.c line.c image.c circle.c text.c \
	visu_rooms.c mlx.c visu_hex.c

OBJ = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))
OBJ2 = $(addprefix $(OBJ_DIR), $(SRC2:.c=.o))

LIBFT = $(LIBFT_DIR)libft.a
LIBFT_DIR := $(LIB_DIR)libft/
LIBFT_INC := $(LIBFT_DIR)inc/
LIBFT_FLAGS := -lft -L $(LIBFT_DIR)

LIBMLX_FLAGS := -lmlx -framework OpenGL -framework AppKit

CC_FLAGS := -O2 -Wall -Wextra -Werror

LINK_FLAGS := $(LIBFT_FLAGS) $(LIBMLX_FLAGS)

HEADER_FLAGS := -I $(INC_DIR) -I $(LIBFT_INC)

CC := gcc

all: $(NAME) $(NAME2)

$(NAME): $(LIBFT) $(OBJ)
	@$(CC) $(OBJ) $(LINK_FLAGS) -o $(NAME)

$(NAME2): $(LIBFT) $(OBJ2)
	@$(CC) $(OBJ2) $(LINK_FLAGS) -o $(NAME2)

$(OBJ): $(INC_DIR)lemin.h | $(OBJ_DIR)

$(OBJ2): $(INC_DIR)lemin.h | $(OBJ_DIR)

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)

$(OBJ_DIR)%.o: %.c
	@$(CC) -c $< -o $@ $(CC_FLAGS) $(HEADER_FLAGS)


$(LIBFT):
	@make -C $(LIBFT_DIR)

clean:
	@rm -f $(OBJ)
	@rm -f $(OBJ2)
	@make clean -C $(LIBFT_DIR)

fclean: clean
	@rm -f $(NAME)
	@rm -f $(NAME2)
	@rm -rf $(OBJ_DIR)
	@make fclean -C $(LIBFT_DIR)

re: fclean all

vpath %.c $(SRC_DIR)

.PHONY: all clean fclean re
