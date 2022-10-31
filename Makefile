# ****************************** Colors & Styles *******************************
NC							:= \033[m
RED							:= \033[0;31m
GREEN						:= \033[1;32m
YELLOW						:= \033[1;33m
BLUE						:= \033[0;34m
PURPLE						:= \033[1;35m
CYAN						:= \033[1;36m

ITALIC						:= \033[1;3m
UNDERLINE					:= \033[1;4m

# ******************************** Directories *********************************
SRC_DIR						:= src
OBJ_DIR						:= obj
INC_DIR						:= include
LIB_DIR						:= lib

# ****************************** Compiler Options ******************************
CC							:= cc
CFLAGS						:= -Wall -Wextra -Werror
IFLAGS						:= -I $(INC_DIR)
LFLAGS						:=

# ********************************* Main Files *********************************
NAME						:= miniRT
SRCS						:= $(shell find $(SRC_DIR) -type f -name *.c)
OBJS						:= $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o,$(SRCS))

# ***************************** Main Dependencies ******************************

# ****************************** Make Arguments ********************************
ifdef DEBUG
CFLAGS	+= -g
endif

# ******************************* Main Targets *********************************
all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	echo "$(BLUE)Linking $(ITALIC)$(UNDERLINE)$(PURPLE)$(NAME)$(NC)"
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

.SECONDEXPANSION:
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $$(addprefix $$(INC_DIR)/, $$($$*_INC_DEP)) | $(OBJ_DIR)
	echo "$(GREEN)Compiling $(ITALIC)$(UNDERLINE)$(YELLOW)$(shell basename $<)$(NC)"
	$(CXX) $(CXXFLAGS) $(IDEFAULT) -c $< -o $@

$(OBJ_DIR):
	mkdir $@

# ****************************** Global Targets ********************************
clean:
	echo "$(RED)Removing $(ITALIC)$(UNDERLINE)$(YELLOW)Object files$(NC)"
	rm -rf $(OBJ_DIR)

fclean: clean
	if [ -d *.dSYM ]; then
		echo "$(RED)Removing$(NC) $(ITALIC)$(UNDERLINE)Debug symbols$(NC)"
		rm -rf *.dSYM;
	fi
	echo "$(RED)Removing $(ITALIC)$(UNDERLINE)$(PURPLE)$(NAME)$(NC)"
	$(RM) $(NAME)

re: fclean all

.SILENT: $(NAME) $(OBJ_DIR) $(OBJS) clean fclean re all

.PHONY: all clean fclean re
