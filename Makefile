# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: robindehouck <robindehouck@student.42.f    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/05 17:44:48 by robindehouc       #+#    #+#              #
#    Updated: 2022/02/07 22:49:13 by robindehouc      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= fdf

GREEN		= "\033[32m"
RESET		= "\033[0m"

# src / obj files
SRC			= 	main.c \
				get_next_line_utils.c \
				get_next_line.c \
				struct.c \
				
OBJ			= $(addprefix $(OBJDIR),$(SRC:.c=.o))

# compiler
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror

# mlx library
MLX			= ./miniLibX/
MLX_LIB		= $(addprefix $(MLX),mlx.a)
MLX_INC		= -I ./miniLibX
MLX_LNK		= -L ./miniLibX -l mlx -framework OpenGL -framework AppKit

# ft library
FT			= ./libft/
FT_LIB 		= $(addprefix $(FT),libft.a)
FT_INC 		= -I ./libft
FT_LNK 		= -L ./libft -l ft

# directories
SRCDIR		= ./srcs/
INCDIR		= ./includes/
OBJDIR		= ./obj/

all: obj $(FT_LIB) $(MLX_LIB) $(NAME)

obj:
		@mkdir -p $(OBJDIR)

$(OBJDIR)%.o:$(SRCDIR)%.c
		$(CC) $(CFLAGS) $(MLX_INC) $(FT_INC) -I $(INCDIR) -o $@ -c $<

$(FT_LIB):
		@make -C $(FT)

$(MLX_LIB):
		@make -C $(MLX)

$(NAME): $(OBJ)
		@$(CC) $(OBJ) $(MLX_LNK) $(FT_LNK) -lm -o $(NAME)
		@echo $(GREEN)"Compilation done !" $(RESET)

clean:
		@rm -rf $(OBJDIR)
		@make -C $(FT) clean
		@make -C $(MLX) clean

fclean: clean
		@rm -rf $(NAME)
		@make -C $(FT) fclean

re: fclean all

.PHONY: all clean fclean re