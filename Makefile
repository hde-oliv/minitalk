CSRC	:=	client.c utils.c
SSRC	:=	server.c utils.c

SRC_DIR :=	sources
INC_DIR :=	headers
OBJ_DIR :=	objects
TST_DIR	:=	tests

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

RM		:=	rm -rf

CNAME	:=	client
SNAME	:=	server
NAME	:= _

all:		obj $(NAME)

$(OBJ_DIR)/%.o:	$(SRC_DIR)/%.c
			$(CC) $(CFLAGS) $(OFLAGS) -c $< -o $@ $(IFLAGS)/$(INCLS)

$(NAME):	$(SNAME) $(CNAME)

$(CNAME):	$(COBJS)
			$(CC) $(COBJS) -o $(CNAME)

$(SNAME):	$(SOBJS)
			$(CC) $(SOBJS) -o $(SNAME)

clean:
			$(RM) $(OBJS) $(OBJ_DIR)

fclean: 	clean
			$(RM) $(SNAME) $(CNAME)

re: 		fclean all

obj:
			mkdir -p $(OBJ_DIR)

.PHONY: 	all clean fclean re obj
