#---------------------------------------------------------#
CC		=	cc

CFLAGS	=	-Wall -Wextra -Werror

GFLAGS	=	-g

DFLAGS	=	-fsanitize=address -fsanitize=undefined
#---------------------------------------------------------#
SRC_DIR		=	src

SRC_SUBDIRS	=	$(shell find $(SRC_DIR)/* -type d)

SRC			=	$(shell find $(SRC_DIR) -type f -name "*.c")

OBJ_DIR		=	obj

OBJ_SUBDIRS	=	$(SRC_SUBDIRS:$(SRC_DIR)%=$(OBJ_DIR)%)

OBJ			=	$(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

INC_DIR		=	includes

INC_FLAGS	=	-I$(INC_DIR) -I$(LIBFT_DIR)/$(INC_DIR)
#---------------------------------------------------------#
#BONUS_SRC_DIR		=	src_bonus
#
#BONUS_OBJ_SUBDIRS	=	$(shell find $(BONUS_SRC_DIR)/* -type d)
#
#BONUS_SRC			=	$(shell find $(BONUS_SRC_DIR) -type f -name "*.c")
#
#BONUS_OBJ_DIR		=	obj_bonus
#
#BONUS_OBJ_SUBDIRS	=	$(BONUS_SRC_SUBDIRS:$(BONUS_SRC_DIR)%=$(BONUS_OBJ_DIR)%)
#
#BONUS_OBJ			=	$(BONUS_SRC:$(BONUS_SRC_DIR)/%.c=$(BONUS_OBJ_DIR)/%.o)
#
#BONUS_INC_DIR		=	includes_bonus
#
#BONUS_INC_FLAGS		=	-I$(INC_DIR) -I$(BONUS_INC_DIR) -I$(LIBFT_DIR)/$(INC_DIR)
#---------------------------------------------------------#
LIBFT_DIR	=	libft

CPU		=	$(shell uname -p)
ifeq ($(CPU),arm)
	LIBFT	=	libft_arm.a
	FT		=	ft_arm
else
	LIBFT	=	libft_x86.a
	FT		=	ft_x86
endif

LIB_FLAGS	=	-L$(LIBFT_DIR) -l$(FT)


.PHONY: all lib clean fclean libclean re
#---------------------------------------------------------#
NAME		=	push_swap

CHECKER		=	checker

all:		$(NAME)

lib:		$(LIBFT_DIR)/$(LIBFT)

$(NAME):	$(OBJ) $(LIBFT_DIR)/$(LIBFT)
	$(CC) $(CFLAGS) $(DFLAGS) $(GFLAGS) $(LIB_FLAGS) $(OBJ) -o $@

$(LIBFT_DIR)/$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_SUBDIRS) $(OBJ_DIR)
	@echo $(OBJ_SUBDIRS)
	$(CC) $(CFLAGS) $(DFLAGS) $(GFLAGS) $(INC_FLAGS) -c $< -o $@ 

$(OBJ_DIR):
	mkdir -p $@

$(OBJ_SUBDIRS):
	mkdir -p $@
#---------------------------------------------------------#
bonus:		$(CHECKER)

$(CHECKER):	$(BONUS_OBJ) $(LIBFT_DIR)/$(LIBFT)
	$(CC) $(CFLAGS) $(DFLAGS) $(GFLAGS) $(LIB_FLAGS) $(BONUS_OBJ) -o $@

$(BONUS_OBJ_DIR)/%.o: $(BONUS_SRC_DIR)/%.c | $(BONUS_OBJ_SUBDIRS) $(BONUS_OBJ_DIR)
	@echo $(BONUS_OBJ_SUBDIRS)
	$(CC) $(CFLAGS) $(DFLAGS) $(GFLAGS) $(BONUS_INC_FLAGS) -c $< -o $@ 

$(BONUS_OBJ_DIR):
	mkdir -p $@

$(BONUS_OBJ_SUBDIRS):
	mkdir -p $@
#---------------------------------------------------------#
clean:
	rm -rf $(OBJ_DIR)

fclean:		clean
	rm -rf $(NAME) 
	rm -rf $(CHECKER)

libclean:
	rm -rf $(LIBFT_DIR)/$(OBJ_DIR)
	rm -rf $(LIBFT_DIR)/$(LIBFT)

libre: libclean lib

re: fclean all

libre: libclean lib
#---------------------------------------------------------#
