#---------------------------------------------------------#
CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror
GFLAGS		=	-g
aDFLAGS		=	-fsanitize=address -fsanitize=undefined
LINK		=	$(shell ld -v 2>&1 | grep GNU && whereis lld)
ifneq ($(LINK),)
	LFLAGS	=	-fuse-ld=lld
endif
#---------------------------------------------------------#
SRC_DIR		=	src

SRC_SUBDIRS	=	$(shell find $(SRC_DIR)/* -type d)

SRC			=	$(shell find $(SRC_DIR) -type f -name "*.c" | grep -v main)

OBJ_DIR		=	obj

OBJ_SUBDIRS	=	$(SRC_SUBDIRS:$(SRC_DIR)%=$(OBJ_DIR)%)

OBJ			=	$(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

INC_DIR		=	includes

INC_FLAGS	=	-I$(INC_DIR) -I$(LIBFT_DIR)/$(INC_DIR)
#---------------------------------------------------------#
PUSH_LIB	=	libpush.a

PUSH_FLAGS	=	-L. -lpush
#---------------------------------------------------------#
LIBFT_DIR	=	libft

CPU			=	$(shell uname -m)
ifeq ($(CPU),arm64)
	LIBFT	=	libft_arm.a
	FT		=	ft_arm
else
	LIBFT	=	libft_x86.a
	FT		=	ft_x86
endif

LIB_FLAGS	=	-L$(LIBFT_DIR) -l$(FT)
#---------------------------------------------------------#
NAME		=	push_swap

CHECKER		=	checker

all:		$(NAME)

lib:		$(LIBFT_DIR)/$(LIBFT)

$(PUSH_LIB): $(OBJ)
	ar -rcs $@ $^

$(NAME):	$(PUSH_LIB) $(LIBFT_DIR)/$(LIBFT)
	$(CC) $(CFLAGS) $(DFLAGS) $(GFLAGS) $(LFLAGS) src/main.c $(INC_FLAGS) $(LIB_FLAGS) $(PUSH_FLAGS) -o $@

$(LIBFT_DIR)/$(LIBFT):
	@echo "LIBFT being created"
	@$(MAKE) -C $(LIBFT_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_SUBDIRS) $(OBJ_DIR)
	@echo $(OBJ_SUBDIRS)
	$(CC) $(CFLAGS) $(DFLAGS) $(GFLAGS) $(INC_FLAGS) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $@

$(OBJ_SUBDIRS):
	@mkdir -p $@
#---------------------------------------------------------#
clean:
	rm -rf $(OBJ_DIR)
	rm -rf $(BONUS_OBJ_DIR)

fclean:		clean
	rm -rf $(PUSH_LIB)
	rm -rf $(NAME)
	rm -rf $(CHECKER)

libclean:
	rm -rf $(LIBFT_DIR)/$(OBJ_DIR)
	rm -rf $(LIBFT_DIR)/$(LIBFT)

libre: libclean lib

re: fclean all

ffclean: fclean libclean

.PHONY: all lib clean fclean libclean libre re ffclean bonus
#---------------------------------------------------------#
BONUS_SRC_DIR		=	src_bonus

BONUS_SRC_SUBDIRS	=	$(shell find $(BONUS_SRC_DIR)/* -type d)

BONUS_SRC			=	$(shell find $(BONUS_SRC_DIR)/* -type f)

BONUS_OBJ_DIR		=	obj_bonus

BONUS_OBJ_SUBDIRS	=	$(BONUS_SRC_SUBDIRS:$(BONUS_SRC_DIR)%=$(BONUS_OBJ_DIR)%)

BONUS_OBJ			=	$(BONUS_SRC:$(BONUS_SRC_DIR)/%.c=$(BONUS_OBJ_DIR)/%.o)

BONUS_INC_DIR		=	includes_bonus

BONUS_INC_FLAGS	=	-I$(INC_DIR) -I$(BONUS_INC_DIR) -I$(LIBFT_DIR)/$(INC_DIR)
#---------------------------------------------------------#
bonus:		$(CHECKER)

$(CHECKER):	$(PUSH_LIB) $(LIBFT_DIR)/$(LIBFT)
	$(CC) $(CFLAGS) $(DFLAGS) $(LFLAGS) $(GFLAGS) src_bonus/checker_main.c $(INC_FLAGS) $(LIB_FLAGS) $(PUSH_FLAGS) -o $@

$(BONUS_OBJ_DIR)/%.o: $(BONUS_SRC_DIR)/%.c | $(BONUS_OBJ_SUBDIRS) $(BONUS_OBJ_DIR)
	@echo $(BONUS_OBJ_SUBDIRS)
	$(CC) $(CFLAGS) $(DFLAGS) $(GFLAGS) $(BONUS_INC_FLAGS) -c $< -o $@

$(BONUS_OBJ_DIR):
	@mkdir -p $@

$(BONUS_OBJ_SUBDIRS):
	@mkdir -p $@
#---------------------------------------------------------#
