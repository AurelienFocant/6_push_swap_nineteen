#-----------------------COMPILER------------------------------#
CC							=	cc
CFLAGS						=	-Wall -Wextra -Werror
GFLAGS						=	-g
LINK						=	$(shell ld -v 2>&1 | grep GNU && whereis lld)
ifneq ($(LINK),)
	LDFLAGS					=	-fuse-ld=lld
else
	LDFLAGS					=	-fuse-ld=ld
endif

COMPILER					=	$(CC) $(CFLAGS) $(GFLAGS)
LINKER						=	$(CC) $(LDFLAGS) $(CFLAGS) $(GFLAGS)
ARCHIVER					=	ar -rcs

#-----------------------HEADER FILES--------------------------#
INC_DIR						=	includes
INC_FLAGS					=	-I$(INC_DIR) -I$(LIBFT_DIR)/$(INC_DIR)

#-----------------------SOURCE FILES--------------------------#
SRC_DIR						=	src
OBJ_DIR						=	obj
SRC_SUBDIRS					=	$(shell find $(SRC_DIR)/* -type d)
OBJ_SUBDIRS					=	$(patsubst $(SRC_DIR)%, $(OBJ_DIR)%, $(SRC_SUBDIRS))

P_S_SRC						=	$(SRC_DIR)/push_swap_main.c
CH_SRC						=	$(SRC_DIR)/checker_main_bonus.c
P_S_OBJ						=	$(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o, $(P_S_SRC))
CH_OBJ						=	$(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o, $(CH_SRC))

#-----------------------PUSH_SWAP LIB-------------------------#
P_S_LIB_SRC					=	$(shell find $(SRC_DIR) -type f -name "*.c" | grep -v main)
P_S_LIB_OBJ					=	$(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(P_S_LIB_SRC))
P_S_LIB						=	libpush.a
P_S_FLAGS					=	-L$(OBJ_DIR) -lpush

#-------------------------LIBFT-------------------------------#
CPU							=	$(shell uname -m)
ifeq ($(CPU),arm64)
	LIBFT		=	libft_arm.a
	FT			=	ft_arm
else
	LIBFT		=	libft_x86.a
	FT			=	ft_x86
endif
LIBFT_DIR					=	libft
LIBFT_FLAGS					=	-L$(LIBFT_DIR) -l$(FT)

#-----------------------MAKE RULES----------------------------#
NAME						=	push_swap
CHECKER						=	checker

all:						$(NAME)
pslib:						$(OBJ_DIR)/$(P_S_LIB)
libft:						$(LIBFT_DIR)/$(LIBFT)
bonus:						$(CHECKER)

$(NAME):					$(OBJ_DIR)/$(P_S_LIB) $(P_S_OBJ) $(CH_OBJ) $(LIBFT_DIR)/$(LIBFT)
	$(LINKER) $(P_S_OBJ) $(LIBFT_FLAGS) $(P_S_FLAGS) -o $@

$(CHECKER):					$(OBJ_DIR)/$(P_S_LIB) $(P_S_OBJ) $(CH_OBJ) $(LIBFT_DIR)/$(LIBFT)
	$(LINKER) $(CH_OBJ) $(LIBFT_FLAGS) $(P_S_FLAGS) -o $@

$(OBJ_DIR)/%.o:				$(SRC_DIR)/%.c | $(OBJ_DIR)/$(OBJ_SUBDIRS) 
	$(COMPILER) $(INC_FLAGS) -c $< -o $@

$(OBJ_DIR)/$(P_S_LIB):		$(OBJ_DIR)/$(P_S_LIB_OBJ) | $(OBJ_DIR)/$(OBJ_SUBDIRS)
	$(ARCHIVER) $@ $(P_S_LIB_OBJ)

$(LIBFT_DIR)/$(LIBFT):
	@echo "LIBFT being created"
	@$(MAKE) -C $(LIBFT_DIR)

$(OBJ_DIR):
	mkdir -p $@
$(OBJ_SUBDIRS):
	mkdir -p $@
#-----------------------CLEAN RULES---------------------------#
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

ffclean: fclean libclean

.PHONY: all lib clean fclean libclean libre re ffclean bonus
#-------------------------------------------------------------#
