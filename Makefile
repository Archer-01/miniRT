# ****************************** Colors & Styles *******************************
NC		:= \033[m
RED		:= \033[0;31m
GREEN	:= \033[1;32m
YELLOW	:= \033[1;33m
BLUE	:= \033[0;34m
PURPLE	:= \033[1;35m
CYAN	:= \033[1;36m

ITALIC		:= \033[1;3m
UNDERLINE	:= \033[1;4m

# ******************************** Directories *********************************
SRC_DIR	:= src
OBJ_DIR	:= obj
INC_DIR	:= inc
LIB_DIR	:= lib

# ****************************** Compiler Options ******************************
CC		:= cc
CFLAGS	:= -Wall -Wextra -Werror
IFLAGS	:= -I $(INC_DIR) -I $(LIB_DIR)/MLX42/include -I $(LIB_DIR)/LIBFT/include
LFLAGS	:= -L $(LIB_DIR)/libft -lft
MFLAGS	:= -L $(LIB_DIR)/MLX42 -lmlx42 -L $(shell brew --prefix glfw)/lib -lglfw

# ********************************* Main Files *********************************
NAME	:= miniRT
SRCS	:= $(shell find $(SRC_DIR) -type f -name *.c)
OBJS	:= $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))
LIBS	:= $(LIB_DIR)/MLX42/libmlx42.a $(LIB_DIR)/libft/libft.a

# ***************************** Main Dependencies ******************************
utils_INC					:= utils.h
color_INC					:= color.h
tuple_INC					:= tuple.h $(utils_INC)
vector_INC					:= $(tuple_INC)
tuple_reflect_INC			:= $(tuple_INC)
canvas_INC					:= canvas.h $(color_INC) $(utils_INC)
pattern_INC					:= $(color_INC) $(canvas_INC) $(tuple_INC)
uv_at						:= $(pattern_INC)
matrix_INC					:= matrix.h $(tuple_INC) $(utils_INC)
light_INC					:= light.h $(tuple_INC) $(color_INC)
intersection_INC			:= intersection.h $(tuple_INC)
intersections_INC			:= intersections.h $(utils_INC) $(intersection_INC)
material_INC				:= material.h $(utils_INC) $(color_INC) $(pattern_INC) $(light_INC) $(intersections_INC)
ray_INC						:= ray.h $(tuple_INC) $(matrix_INC)
shape_INC					:= $(matrix_INC) $(material_INC) $(intersections_INC) $(ray_INC) $(tuple_INC)
color_at_INC				:= $(shape_INC) $(pattern_INC)
intersect_INC				:= $(shape_INC)
matrix_inverse_INC			:= $(matrix_INC)
matrix_transformations_INC	:= $(matrix_INC)
normal_at_INC				:= $(shape_INC)
world_INC					:= world.h $(shape_INC) $(light_INC) $(color_INC)
world_utils					:= $(world_INC)
camera_INC					:= $(matrix_INC) $(ray_INC) $(canvas_INC) $(world_INC)
render_INC					:= $(camera_INC)

# ****************************** Make Arguments ********************************
ifdef DEBUG
CFLAGS += -g
endif

ifdef FAST
CFLAGS += -O3
endif

# ******************************* Main Targets *********************************
all: $(NAME)

$(NAME): $(OBJS) $(LIBS)
	echo "$(BLUE)Linking $(ITALIC)$(UNDERLINE)$(PURPLE)$(NAME)$(NC)"
	$(CC) $(CFLAGS) $(LFLAGS) $(MFLAGS) $^ -o $@

.SECONDEXPANSION:
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $$(addprefix $$(INC_DIR)/, $$($$*_INC)) | $(OBJ_DIR)
	echo "$(GREEN)Compiling $(ITALIC)$(UNDERLINE)$(YELLOW)$(<F)$(NC)"
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir $@

$(LIB_DIR)/MLX42/libmlx42.a:
	echo "$(PURPLE)Building $(ITALIC)$(UNDERLINE)$(CYAN)MLX42$(NC)"
	make -C $(@D)

$(LIB_DIR)/libft/libft.a:
	echo "$(PURPLE)Building $(ITALIC)$(UNDERLINE)$(CYAN)LIBFT$(NC)"
	make -C $(@D)

# ****************************** Global Targets ********************************
clean:
	if [ -d $(OBJ_DIR) ]; then \
		echo "$(RED)Removing $(ITALIC)$(UNDERLINE)$(YELLOW)Object files$(NC)"; \
		rm -rf $(OBJ_DIR); \
	fi
	make clean -C $(LIB_DIR)/MLX42;
	make clean -C $(LIB_DIR)/libft;

fclean: clean
	if [ -d *.dSYM ]; then \
		echo "$(RED)Removing$(NC) $(ITALIC)$(UNDERLINE)Debug symbols$(NC)"; \
		rm -rf *.dSYM; \
	fi
	if [ -f $(NAME) ]; then \
		echo "$(RED)Removing $(ITALIC)$(UNDERLINE)$(PURPLE)$(NAME)$(NC)"; \
		rm -f $(NAME); \
	fi
	make fclean -C $(LIB_DIR)/MLX42;
	make fclean -C $(LIB_DIR)/libft;

re: fclean all

.SILENT: $(NAME) $(OBJ_DIR) $(OBJS) clean fclean re all \
	$(LIB_DIR)/MLX42/libmlx42.a \
	$(LIB_DIR)/libft/libft.a
.PHONY: all clean fclean re
