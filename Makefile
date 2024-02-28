# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: blarger <blarger@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/13 10:18:55 by blarger           #+#    #+#              #
#    Updated: 2024/02/28 09:54:20 by blarger          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Colors
DEL_LINE =		\033[2K
ITALIC =		\033[3m
BOLD =			\033[1m
DEF_COLOR =		\033[0;39m
GRAY =			\033[0;90m
RED =			\033[0;91m
GREEN =			\033[0;92m
YELLOW =		\033[0;93m
BLUE =			\033[0;94m
MAGENTA =		\033[0;95m
CYAN =			\033[0;96m
WHITE =			\033[0;97m
BLACK =			\033[0;99m
ORANGE =		\033[38;5;209m
BROWN =			\033[38;2;184;143;29m
DARK_GRAY =		\033[38;5;234m
MID_GRAY =		\033[38;5;245m
DARK_GREEN =	\033[38;2;75;179;82m
DARK_YELLOW =	\033[38;5;143m

#Variables
NAME 			:= pipex
HEADER			:= -I ./includes -I ${LIBFT} -I ${FT_PRINTF}
RM 				:= rm -f
LIBFT_DIR		:= Library/Libft/
LIBFT 			:= $(LIBFT_DIR)libft.a
FT_PRINTF_DIR	:= Library/Ft_printf/
FT_PRINTF 		:= $(FT_PRINTF_DIR)libftprintf.a
CC 				:= cc
CFLAGS 			:= -Wall -Werror -Wextra -Imlx -IInclude

#Sources
SRC_DIR					= Sources/
OBJ_DIR					= Objects/
SRC_FILES				= 0_main utils_split 1_file_handling 2_commands 3_create_fork 4_child_process 5_parent_process free_list fix_error errors
SRC						= $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ 					= $(addprefix $(OBJ_DIR), $(addsuffix .o, $(notdir $(SRC_FILES))))
DEPS					= $(addprefix $(OBJ_DIR), $(addsuffix .d, $(SRC_FILES)))
INCS					= $(addprefix $(INCLUDE), $(addsuffix .h, $(INC_FILES)))


#Bonus
BONUS_NAME				= pipex
BONUS_SRC_DIR			= Bonus/Sources/
BONUS_OBJ_DIR			= Bonus/Objects/
BONUS_SRC_FILES			= 0_main_b 3_child_process_b 1_file_handling_b 2_commands_b split_b errors_b free_list_b
BONUS_OBJ				= $(addprefix $(BONUS_OBJ_DIR), $(addsuffix .o, $(notdir $(BONUS_SRC_FILES))))

#Rules
all: libft libpf $(OBJ_DIR) ${NAME}

libft:
			@${MAKE} -C ${LIBFT_DIR}
			@echo "$(GREEN)libft compiled!$(DEF_COLOR)"

libpf:
			@${MAKE} -C ${FT_PRINTF_DIR}
			@echo "$(GREEN)printf compiled!$(DEF_COLOR)"


$(OBJ_DIR)%.o: $(SRC_DIR)%.c
			$(CC) $(CFLAGS) -c -o $@ $< $(HEADER)
			@echo "${BLUE} ◎ $(BROWN)Compiling   ${MAGENTA}→   $(CYAN)$< $(DEF_COLOR)"
			@${CC} ${CFLAGS} -c $< -o $@

$(BONUS_OBJ_DIR)%.o: $(BONUS_SRC_DIR)%.c
			$(CC) $(CFLAGS) -c -o $@ $< $(HEADER)
			@echo "${BLUE} ◎ $(BROWN)Compiling bonus  ${MAGENTA}→   $(CYAN)$< $(DEF_COLOR)"

$(NAME): $(OBJ) $(LIBFT) $(FT_PRINTF)
			@echo "👉 $(BLUE)$(CC) $(CFLAGS) $(OBJ) $(FT_PRINTF) -o $(NAME)$(DEF_COLOR)"
			${CC} -o $(NAME) -L$(LIBFT_DIR) -lft -L$(FT_PRINTF_DIR) -lftprintf $(OBJ)  $(CFLAGS)
			@echo "$(GREEN)$(NAME) ✨ PIPEX compiled!$(DEF_COLOR)"

bonus: $(BONUS_OBJ) $(LIBFT) $(BONUS_OBJ_DIR) $(FT_PRINTF)
	@echo "👉 $(BLUE)$(CC) $(CFLAGS) $(BONUS_OBJ) $(FT_PRINTF) -o $(BONUS_NAME)$(DEF_COLOR)"
	${CC} -o $(BONUS_NAME) -L$(LIBFT_DIR) -lft -L$(FT_PRINTF_DIR) -lftprintf $(BONUS_OBJ)
	@echo "$(GREEN)$(BONUS_NAME) ✨ PIPEX bonus compiled!$(DEF_COLOR)"

clean:
			rm -f $(OBJ)
			rm -f $(BONUS_OBJ)
			make -C $(FT_PRINTF_DIR) clean
			@echo "$(CYAN)ft_printf object cleaned.$(DEF_COLOR)"
			make -C $(LIBFT_DIR) clean
			@echo "$(CYAN)libft object cleaned.$(DEF_COLOR)"

fclean: clean
			$(RM) $(NAME)
			@echo "$(CYAN)pipex executable files cleaned!$(DEF_COLOR)"
			$(RM) $(BONUS_NAME)
			@echo "$(CYAN)pipex_bonus executable files cleaned!$(DEF_COLOR)"
			make -C $(FT_PRINTF_DIR) fclean
			@echo "$(CYAN)ft_printf lib cleaned!$(DEF_COLOR)"
			make -C $(LIBFT_DIR) fclean
			@echo "$(CYAN)libft.a lib cleaned!$(DEF_COLOR)"

re: fclean all

.Phony: all clean fclean re