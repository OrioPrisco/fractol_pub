# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: OrioPrisco <47635210+OrioPrisco@users      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/23 15:27:59 by OrioPrisc         #+#    #+#              #
#    Updated: 2023/04/12 11:57:01 by OrioPrisc        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	fractol
CC				=	cc
SRC				=	main.c\
					parse.c\
					complex.c\
					draw.c\
					env.c\
					hooks.c\
					deal_key.c\
					color_chunk.c\
					color.c\
					mandelbrot.c\
					julia.c\
					burning_ship.c\
					julia_ship.c\
					debug.c\
					camera.c\
					winding.c\
					image.c\
					deepen.c\
					palette.c\
					metamandelbrot.c\
					metajulia.c\
					complex_power.c\


OBJ_FOLDER		=	objs/

CFLAGS			=	-Wall -Wextra -Werror -O2 -flto

SRC_FOLDER		=	srcs/

HEADERS_FOLDER	=	includes/\
					minilibx-linux/\
					libft/includes/


OBJS = $(patsubst %.c,$(OBJ_FOLDER)%.o,$(SRC))

DEPENDS		:=	$(patsubst %.c,$(OBJ_FOLDER)%.d,$(SRC))
COMMANDS	:=	$(patsubst %.c,$(OBJ_FOLDER)%.cc,$(SRC))

all: $(NAME) compile_commands.json

bonus: all


minilibx-linux/libmlx.a:
	make -C minilibx-linux MAKEFLAGS=

libft/libft.a:
	make -C libft

libft/libftprintf.a:
	make -C libft

$(NAME): $(OBJS) minilibx-linux/libmlx.a libft/libft.a libft/libftprintf.a
	cc $(CFLAGS) $(OBJS) -lftprintf -Llibft -lft -Lminilibx-linux -lmlx -lXext -lX11 -lm -lbsd -o $(NAME)

-include $(DEPENDS)

COMP_COMMAND = $(CC) -c $(CFLAGS) $(addprefix -I,$(HEADERS_FOLDER)) -MMD -MP $< -o $@
CONCAT = awk 'FNR==1 && NR!=1 {print ","}{print}'

$(OBJ_FOLDER)%.o $(OBJ_FOLDER)%.cc: $(SRC_FOLDER)%.c Makefile
	$(COMP_COMMAND)
	printf '{\n\t"directory" : "$(shell pwd)",\n\t"command" : "$(COMP_COMMAND)",\n\t"file" : "$<"\n}' > $(OBJ_FOLDER)$*.cc

compile_commands.json : $(COMMANDS) Makefile
	echo "[" > compile_commands.json
	$(CONCAT) $(COMMANDS) >> compile_commands.json
	echo "]" >> compile_commands.json

clean:
	rm -f $(OBJS) $(DEPENDS) $(COMMANDS)
	make -C libft clean

fclean: clean
	rm -f $(NAME) compile_commands.json
	make -C libft fclean
	make -C minilibx-linux clean

re: fclean all
	
.PHONY: all clean fclean re bonus
.SUFFIXES:
MAKEFLAGS += --warn-undefined-variables
MAKEFLAGS += --no-builtin-rules
