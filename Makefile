# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: xamartin <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/02/01 10:30:09 by xamartin     #+#   ##    ##    #+#        #
#    Updated: 2018/04/12 11:42:47 by xamartin    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

.PHONY = all, clean, fclean, re


#COMPILATION

CC = gcc
LIBFT = libft/
GRAPH = minilibx_macos/libmlx.a
CHECKER = checker
PUSH_SWAP = push_swap
INC = -I includes/push_swap.h
INC_GRAPH = -I minilibx_macos
CFLAGS = -Wall -Werror -Wextra -g
EXT_LIBS = -framework OpenGl -framework Appkit


#PATH

CHECKER_SCRS_PATH = ./srcs_checker/
CHECKER_OBJS_PATH = ./srcs_checker/

CHECKER_FILES = apply_checker.c\
				parse_checker.c\
				main_checker.c\
				list_init.c\
				init_move.c\
				move_rr.c\
				move_s.c\
				move_p.c\
				move_r.c\
				color.c\
				visu.c\


CHECKER_SRCS = $(addprefix $(CHECKER_SRCS_PATH), $(CHECKER_FILES))
CHECKER_OBJS = $(addprefix $(CHECKER_OBJS_PATH), $(CHECKER_FILES:.c=.o))


PUSH_SWAP_SRCS_PATH = ./srcs_push_swap/
PUSH_SWAP_OBJS_PATH = ./srcs_push_swap/

PUSH_SWAP_FILES = main_push_swap.c\
				  parse_push_swap.c\
				  apply_push_swap.c\
				  genius_insert2.c\
				  genius_insert.c\
				  simplesort.c\
				  list_init.c\
				  init_move.c\
				  move_rr.c\
				  move_s.c\
				  move_p.c\
				  move_r.c\
				  color.c\
				  visu.c\


PUSH_SWAP_SRCS = $(addprefix $(PUSH_SWAP_SRCS_PATH), $(PUSH_SWAP_FILES))
PUSH_SWAP_OBJS = $(addprefix $(PUSH_SWAP_OBJS_PATH), $(PUSH_SWAP_FILES:.c=.o))



#RULES

all: $(CHECKER) $(PUSH_SWAP)


$(CHECKER): $(CHECKER_OBJS)
	@make -C $(LIBFT)
	@make -C minilibx_macos
	@$(CC) $(CFLAGS) $(INC) $(GRAPH) $(INC_GRAPH) $(EXT_LIBS) -o $@ $(CHECKER_OBJS) -L $(LIBFT) -lft

$(PUSH_SWAP): $(PUSH_SWAP_OBJS)
	@make -C $(LIBFT)
	@$(CC) $(CFLAGS) $(INC) -o $@ $(PUSH_SWAP_OBJS) -L $(LIBFT) -lft


$(PUSH_SWAP_OBJS_PATH)%.o: $(PUSH_SWAP_SRCS_PATH)%.c
	@$(CC) $(CFLAGS) $(INC) -o $@ -c $< 

$(CHECKER_OBJS_PATH)%.o: $(CHECKER_SRCS_PATH)%.c
	@$(CC) $(CFLAGS) $(INC) -o $@ -c $< 


clean:
	@make -C libft clean
	@make -C minilibx_macos clean
	@rm -rf $(PUSH_SWAP_OBJS)
	@rm -f $(CHECKER_OBJS)

fclean: clean
	@make -C libft fclean
	@make -C minilibx_macos fclean
	@rm -f $(PUSH_SWAP) $(CHECKER)

re: fclean all
	@make -C libft re
	@make -C minilibx_macos re
