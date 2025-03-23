# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: azorlutu <azorlutu@student.42istanbul      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/12 21:25:23 by azorlutu          #+#    #+#              #
#    Updated: 2025/03/12 21:25:24 by azorlutu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
MLXFLAGS = -lXext -lX11

NAME = fractol
NAME_BONUS = fractol_bonus

SRCS = handle_events.c \
		fractal_events.c \
		fractal_init.c \
		fractal_render.c \
		handle_errors.c \
		main.c \
		string_utils.c \
		fractal_sets.c \
		messages.c \
		fractal_utils.c \

SRCS_BONUS = handle_events_bonus.c \
				fractal_events_bonus.c \
				fractal_init_bonus.c \
				fractal_render_bonus.c \
				handle_errors_bonus.c \
				main_bonus.c \
				string_utils_bonus.c \
				fractal_sets_bonus.c \
				messages_bonus.c \
				fractal_utils_bonus.c \

OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

# Reset
COLOR_RESET='\033[0m'

# Regular Colors
COLOR_BLACK='\033[0;30m'
COLOR_RED='\033[0;31m'
COLOR_GREEN='\033[0;32m'
COLOR_YELLOW='\033[0;33m'
COLOR_BLUE='\033[0;34m'
COLOR_PURPLE='\033[0;35m'
COLOR_CYAN='\033[0;36m'
COLOR_WHITE='\033[0;37m'

RM = rm -rf

MLX_PATH	= minilibx-linux/
MLX_NAME	= libmlx.a
MLX			= $(MLX_PATH)$(MLX_NAME)

all: $(MLX) $(NAME)

$(NAME): $(OBJS) 
	@echo "$(COLOR_YELLOW)Compiling fractol...$(COLOR_RESET)"
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX) $(MLXFLAGS)
	@echo "$(COLOR_GREEN)Fractol ready."

bonus: $(MLX) $(NAME_BONUS)

$(NAME_BONUS): $(OBJS_BONUS) 
	@echo "$(COLOR_YELLOW)Compiling fractol bonus...$(COLOR_RESET)"
	$(CC) $(CFLAGS) -o $(NAME_BONUS) $(OBJS_BONUS) $(MLX) $(MLXFLAGS)
	@echo "$(COLOR_GREEN)Fractol bonus ready."

$(MLX):
	@echo "$(COLOR_PURPLE)Making MiniLibX...$(COLOR_RESET)"
	@make -sC $(MLX_PATH)


clean:
	@echo "$(COLOR_RED)Removing .o object files...$(COLOR_RESET)"
	$(RM) $(OBJS) $(OBJS_BONUS)
	@make clean -C $(MLX_PATH)

fclean: clean
	@echo "$(COLOR_RED)Removing fractol...$(COLOR_RESET)"
	$(RM) $(NAME) $(NAME_BONUS)
	$(RM) $(LIBFT_PATH)$(LIBFT_NAME)

re: fclean all bonus

.PHONY: all clean fclean re bonus
