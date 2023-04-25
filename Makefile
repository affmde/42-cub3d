
#Color scheme
COLOUR_GREEN=\033[0;32m
COLOUR_RED=\033[0;31m
COLOUR_BLUE=\033[0;34m
COLOUR_END=\033[0m

NAME = cub3D
NAME_BONUS = cub3D_bonus

#Flags
FLAGS = -Wall -Werror -Wextra -I includes
BONUS_FLAGS = -Wall -Werror -Wextra -I includes_bonus
LINFLAGS = -lmlx -lm -lXext -lX11
MOSFLAGS = -lmlx -lm -framework OpenGl -framework AppKit
LIBFT = libft/libft.a

#Dirs
OBJS_DIR = obj/
CORE_DIR = srcs/core/
FILE_PARSING_DIR = srcs/file_parsing/
INIT_DIR = srcs/init/
UTILS_DIR = srcs/utils/
FILE_VALIDATION_DIR = srcs/file_validation/
MLX_HANDLING_DIR = srcs/mlx_handling/
RAYCASTING_DIR = srcs/raycasting/
SPRITES_DIR = srcs/sprites/
BONUS_DIR = srcs/bonus/

CORE = main.c handle_errors.c clean.c draw_example.c

FILE_PARSING = file_read.c parse_elements.c parse_map.c

INIT = cub3d_init.c cam_init.c image_init.c ray_init.c

UTILS = parse_utils.c texture_creator.c walls_creator.c map_validation_utils.c return_textures.c math_utils.c bresenham_algo.c \
colors.c graphics_utils.c movement_utils.c sprites_utils.c

FILE_VALIDATION = map_validity.c file_validity.c elements_validity.c map_closed.c fc_validity.c get_map_copy.c

MLX_HANDLING = mlx_handling.c events.c mouse.c move_player.c rotate_player.c

RAYCASTING = raycast.c texture_render.c minimap.c minimap_rays.c

SPRITES = sprites.c sprites_config.c load_sprites.c gun_render.c shoot.c aim.c bullets.c load_textures.c

BONUS = time_bonus.c map_validation_utils_bonus.c move_player_bonus.c mlx_handling_bonus.c rotate_player_bonus.c main_bonus.c \
load_all_text_bonus.c raycast_bonus.c

ALL_SRCS = $(FILE_PARSING) $(INIT) $(UTILS) $(FILE_VALIDATION) $(MLX_HANDLING) $(RAYCASTING) $(CORE) $(SPRITES)
ALL_BONUS_SRCS := $(filter-out map_validation_utils.c move_player.c mlx_handling.c rotate_player.c main.c raycast.c, $(ALL_SRCS))
ALL_BONUS_SRCS += $(BONUS)
OBJ_FILES = $(ALL_SRCS:.c=.o)
OBJS = $(patsubst %, $(OBJS_DIR)%, $(ALL_SRCS:.c=.o))
BONUS_OBJS = $(patsubst %, $(OBJS_DIR)%, $(ALL_BONUS_SRCS:.c=.o))

all: $(NAME)

$(LIBFT):
	@make all -C libft
	@make bonus -C libft
	@echo "$(COLOUR_GREEN)libft compilation completed$(COLOUR_END)"

$(NAME): $(LIBFT) $(OBJS_DIR) $(OBJS)
	@cc $(FLAGS) $(OBJS) -o $@ -L. $(LIBFT) $(MOSFLAGS)
#	@cc $(FLAGS) $(OBJS) -o $@ -L. $(LIBFT) $(LINFLAGS)
	@echo "$(COLOUR_GREEN)$@ created$(COLOUR_END)"

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)
	@echo "$(COLOUR_BLUE)object directory created$(COLOUR_END)"

$(OBJS_DIR)%.o: $(CORE_DIR)%.c
	@cc $(FLAGS) -c $< -o $@
	@echo "$(COLOUR_BLUE)$@ created$(COLOUR_END)"

$(OBJS_DIR)%.o: $(FILE_PARSING_DIR)%.c
	@cc $(FLAGS) -c $< -o $@
	@echo "$(COLOUR_BLUE)$@ created$(COLOUR_END)"

$(OBJS_DIR)%.o: $(UTILS_DIR)%.c
	@cc $(FLAGS) -c $< -o $@
	@echo "$(COLOUR_BLUE)$@ created$(COLOUR_END)"

$(OBJS_DIR)%.o: $(INIT_DIR)%.c
	@cc $(FLAGS) -c $< -o $@
	@echo "$(COLOUR_BLUE)$@ created$(COLOUR_END)"

$(OBJS_DIR)%.o: $(FILE_VALIDATION_DIR)%.c
	@cc $(FLAGS) -c $< -o $@
	@echo "$(COLOUR_BLUE)$@ created$(COLOUR_END)"

$(OBJS_DIR)%.o: $(MLX_HANDLING_DIR)%.c
	@cc $(FLAGS) -c $< -o $@
	@echo "$(COLOUR_BLUE)$@ created$(COLOUR_END)"

$(OBJS_DIR)%.o: $(RAYCASTING_DIR)%.c
	@cc $(FLAGS) -c $< -o $@
	@echo "$(COLOUR_BLUE)$@ created$(COLOUR_END)"

$(OBJS_DIR)%.o: $(SPRITES_DIR)%.c
	@cc $(FLAGS) -c $< -o $@
	@echo "$(COLOUR_BLUE)$@ created$(COLOUR_END)"

$(OBJS_DIR)%.o: $(BONUS_DIR)%.c
	@cc $(FLAGS) -c $< -o $@
	@echo "$(COLOUR_BLUE)$@ created$(COLOUR_END)"

clean:
	@make clean -C libft
	@echo "$(COLOUR_BLUE)libft object files cleaned$(COLOUR_END)"
	@rm -f $(OBJS)
	@echo "$(COLOUR_BLUE)object directory cleaned$(COLOUR_END)"

fclean: clean
	@rm libft/libft.h.gch
	@rm -rf $(OBJS_DIR)
	@make fclean -C libft
	@echo "$(COLOUR_RED)libft.a removed$(COLOUR_END)"
	@rm -f $(NAME)
	@echo "$(COLOUR_RED)$(NAME) removed$(COLOUR_END)"
	@rm -f $(NAME_BONUS)
	@echo "$(COLOUR_RED)$(NAME_BONUS) removed$(COLOUR_END)"

$(NAME_BONUS): $(LIBFT) $(OBJS_DIR) $(BONUS_OBJS)
	@cc $(BONUS_FLAGS) $(BONUS_OBJS) -o $(NAME_BONUS) -L. $(LIBFT) $(MOSFLAGS)
#	@cc $(BONUS_FLAGS) $(BONUS_OBJS) -o $(NAME_BONUS) -L. $(LIBFT) $(LINFLAGS)
	@echo "$(COLOUR_GREEN)$(NAME_BONUS) created$(COLOUR_END)"

bonus: $(NAME_BONUS)

re: fclean all

