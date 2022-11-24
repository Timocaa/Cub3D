# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fleblanc <fleblanc@student.42angoulem      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/24 17:08:49 by fleblanc          #+#    #+#              #
#    Updated: 2022/11/15 14:03:32 by fleblanc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
# Names

NAME	= cub3D
NAMEB	= cub3D_bonus
LIBNAME	= libft.a
MLXNAME	= mlx.a

# **************************************************************************** #
# Compilation

CC			= clang -g
WFLAGS		= -Wall -Wextra -Werror
MLXFLAGS	= -Lmlx/ -lmlx -L/usr/lib -lXext -lX11 -lm -lz

# **************************************************************************** #
# System Commands

MAKE		= make -sC
MKDIR		= mkdir -p
NORM		= norminette
NORMFLAG_C	= -R CheckForbiddenSourceHeader
NORMFLAG_H	= -R CheckDefine
RM			= rm -rf

# **************************************************************************** #
# Directories

INCDIR	=	inc
LIBDIR	=	libft
MLXDIR	=	mlx
OBJDIR	=	obj
SRCDIR	=	src

# **************************************************************************** #
# List of source file

SRCNAME	=	main.c \
			parsing/ft_check_file.c \
			parsing/ft_check_map.c \
			parsing/ft_parsing_line.c \
			struct/ft_struct_var.c \
			struct/ft_struct_data.c \
			struct/ft_struct_mlx.c \
			struct/ft_struct_play.c \
			struct/ft_struct_ray.c \
			struct/ft_struct_wall.c \
			init/ft_init_draw.c \
			raycasting/ft_draw_screen.c \
			raycasting/ft_rc_init.c \
			image/ft_texturing_fct.c \
			image/ft_color_fct.c \
			close/ft_error.c \
			close/ft_close.c \
			controls/ft_moves.c \
			controls/ft_rotate.c

SRCBNAME =	main_bonus.c \
			parsing/ft_check_file_bonus.c \
			parsing/ft_check_map_bonus.c \
			parsing/ft_parsing_line_bonus.c \
			struct/ft_struct_var_bonus.c \
			struct/ft_struct_data_bonus.c \
			struct/ft_struct_mlx_bonus.c \
			struct/ft_struct_play_bonus.c \
			struct/ft_struct_ray_bonus.c \
			struct/ft_struct_wall_bonus.c \
			init/ft_init_draw_bonus.c \
			raycasting/ft_draw_screen_bonus.c \
			raycasting/ft_minimap_bonus.c \
			raycasting/ft_rc_init_bonus.c \
			image/ft_texturing_fct_bonus.c \
			image/ft_color_fct_bonus.c \
			close/ft_error_bonus.c \
			close/ft_close_bonus.c \
			controls/ft_moves_bonus.c \
			controls/ft_rotate_bonus.c

# **************************************************************************** #
# Variables where are listed the names of source and object files

LFT	= $(addprefix $(LIBDIR)/, $(LIBNAME))
MLX	= $(addprefix $(MLXDIR)/, $(MLXNAME))
OBJ	= $(addprefix $(OBJDIR)/mandatory/, $(SRCNAME:.c=.o))
OBJB = $(addprefix $(OBJDIR)/bonus/, $(SRCBNAME:.c=.o))
SRC	= $(addprefix $(SRCDIR)/mandatory/, $(SRCNAME))
SRCB = $(addprefix $(SRCDIR)/bonus/, $(SRCBNAME))

# **************************************************************************** #
# Extra 

BASENAME	= `basename $(PWD)`
CR			= "\r"$(CLEAR)
CLEAR		= "\\033[0K"
EOC			= "\033[0;0m"
GREY		= "\033[0;30:"
RED			= "\033[0;31m"
GREEN		= "\033[0;32m"
YELLOW		= "\033[0;33m"
BLUE		= "\033[0;34m"
PURPLE		= "\033[0;35m"
CYAN		= "\033[0;36m"
WHITE		= "\033[0;37m"

# **************************************************************************** #
# Rules

$(OBJDIR)/%.o: $(SRCDIR)/%.c
			@$(MKDIR) $(dir $@)
			@$(CC) $(WFLAGS) -c $< -o $@
			@printf $(CR)"[ $(BASENAME)/%s ]"$(CLEAR) $@

all:	$(NAME)

bonus:	$(NAMEB)

$(LFT):
		@$(MAKE) $(LIBDIR)

$(NAME): $(LFT) $(OBJ)
			@printf $(CR)
			@$(MAKE) $(MLXDIR)
			@$(CC) $(OBJ) $(LFT) $(MLXFLAGS) -o $(NAME)
			@printf $(CR)$(GREEN)"✓ $(NAME) is created\n"$(EOC)

$(NAMEB): $(LFT) $(OBJB)
			@printf $(CR)
			@$(MAKE) $(MLXDIR)
			@$(CC) $(OBJB) $(LFT) $(MLXFLAGS) -o $(NAMEB)
			@printf $(CR)$(GREEN)"✓ $(NAMEB) is created\n"$(EOC)

clean:
			@$(MAKE) $(LIBDIR) clean
			@if [ -d $(OBJDIR) ]; then \
				$(RM) $(OBJDIR) \
				&& printf $(CR)$(BLUE)"✗ The objects files of $(NAME) and/or $(NAMEB) " \
				&& printf "are cleaned\n"$(EOC);\
			fi

fclean:	clean
			@$(MAKE) $(LIBDIR) fclean
			@$(MAKE) $(MLXDIR) clean
			@if [ -e $(NAME) ]; then \
				$(RM) $(NAME) \
				&& printf $(CR)$(RED)"✗ $(NAME) is cleaned\n"$(EOC); \
			fi
			@if [ -e $(NAMEB) ]; then \
				$(RM) $(NAMEB) \
				&& printf $(CR)$(RED)"✗ $(NAMEB) is cleaned\n"$(EOC); \
			fi

re:	fclean all

norm:
			@$(NORM) $(NORMFLAG_C) $(SRCDIR) $(LIBDIR)/src ; \
			$(NORM) $(NORMFLAG_H) $(INCDIR) $(LIBDIR)/include

.PHONY: all clean fclean re norm bonus
