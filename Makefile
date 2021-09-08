CSRC	:=	client.c
SSRC	:=	server.c

SRC_DIR :=	sources
INC_DIR :=	headers
OBJ_DIR :=	objects

INCLS   :=	$(INC_DIR)

CSRCS	:=	$(addprefix $(SRC_DIR)/,$(CSRC))
COBJS	:=	$(CSRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

SSRCS	:=	$(addprefix $(SRC_DIR)/,$(SSRC))
SOBJS	:=	$(SSRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

CC		:=	clang

CFLAGS	+=	-Wall -Wextra -Werror -pedantic
IFLAGS	+=	-I.
LFLAGS	+=	-L.
TFLAGS	+=	-fsanitize=address -g3
OFLAGS	+=	-O3
MFLAGS	+=	-lftprintf

RM		:=	rm -rf

CNAME	:=	client
SNAME	:=	server
NAME	:=	_

PFT_DIR	:=	ft_printf
LFT_DIR	:=	ft_printf/libft

all:		pft obj $(NAME)

$(OBJ_DIR)/%.o:	$(SRC_DIR)/%.c
			$(CC) $(CFLAGS) $(OFLAGS) -c $< -o $@ $(IFLAGS)/$(INCLS) $(IFLAGS)/$(PFT_DIR) $(IFLAGS)/$(LFT_DIR)

$(NAME):	$(SNAME) $(CNAME)

$(CNAME):	$(COBJS)
			$(CC) $(COBJS) $(LFLAGS)/$(PFT_DIR) $(MFLAGS) -o $(CNAME)

$(SNAME):	$(SOBJS)
			$(CC) $(SOBJS) $(LFLAGS)/$(PFT_DIR) $(MFLAGS) -o $(SNAME)

clean:
			$(MAKE) -C $(PFT_DIR) clean
			$(RM) $(OBJS) $(OBJ_DIR)

fclean: 	clean
			$(MAKE) -C $(PFT_DIR) fclean
			$(RM) $(SNAME) $(CNAME)

re: 		fclean all

pft:
			$(MAKE) -C $(PFT_DIR)

obj:
			mkdir -p $(OBJ_DIR)

.PHONY: 	all clean fclean re obj
