# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jisokang <jisokang@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/22 02:58:35 by jisokang          #+#    #+#              #
#    Updated: 2021/06/28 17:16:45 by jisokang         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	minitalk
CLIENT_NAME	=	client
SERVER_NAME	=	server

BONUS_NAME			=	minitalk_bonus
BONUS_CLIENT_NAME	=	client_bonus
BONUS_SERVER_NAME	=	server_bonus

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror
AR		=	ar rcs
RM		=	rm -f

INCS_DIR	=	./include/
SRCS_DIR	=	./src/

LIB_DIR		=	./lib/
LIB_NAME	=	lib_jisokang.a
LIBS		=	$(addprefix $(LIB_DIR), $(LIB_NAME))

UTIL_SRC	=	util.c error.c
CLIENT_SRC	=	client.c
SERVER_SRC	=	server.c

BONUS_CLIENT_SRC	=	client_bonus.c
BONUS_SERVER_SRC	=	server_bonus.c

UTIL_OBJS	=	$(UTIL_SRC:.c=.o)
CLIENT_OBJS	=	$(CLIENT_SRC:.c=.o)
SERVER_OBJS	=	$(SERVER_SRC:.c=.o)

BONUS_CLIENT_OBJS	=	$(BONUS_CLIENT_SRC:.c=.o)
BONUS_SERVER_OBJS	=	$(BONUS_SERVER_SRC:.c=.o)

UTIL_SRCS	=	$(addprefix $(SRCS_DIR), $(UTIL_OBJS))
CLIENT_SRCS	=	$(addprefix $(SRCS_DIR), $(CLIENT_OBJS))
SERVER_SRCS	=	$(addprefix $(SRCS_DIR), $(SERVER_OBJS))

BONUS_CLIENT_SRCS	=	$(addprefix $(SRCS_DIR), $(BONUS_CLIENT_OBJS))
BONUS_SERVER_SRCS	=	$(addprefix $(SRCS_DIR), $(BONUS_SERVER_OBJS))

all		:	$(NAME)

$(NAME)	: $(LIB_NAME) $(CLIENT_NAME) $(SERVER_NAME)

$(LIB_NAME) :
	make -C $(LIB_DIR)

$(CLIENT_NAME) : $(CLIENT_SRCS) $(LIBS) $(UTIL_SRCS)
	$(CC) $(CFLAGS) -I $(INCS_DIR) -o $@ $^

$(SERVER_NAME) : $(SERVER_SRCS) $(LIBS) $(UTIL_SRCS)
	$(CC) $(CFLAGS) -I $(INCS_DIR) -o $@ $^


bonus	: $(BONUS_NAME)

$(BONUS_NAME) : $(LIB_NAME) $(BONUS_CLIENT_NAME) $(BONUS_SERVER_NAME)

$(BONUS_CLIENT_NAME) : $(BONUS_CLIENT_SRCS) $(LIBS) $(UTIL_SRCS)
	$(CC) $(CFLAGS) -I $(INCS_DIR) -o $@ $^

$(BONUS_SERVER_NAME) : $(BONUS_SERVER_SRCS) $(LIBS) $(UTIL_SRCS)
	$(CC) $(CFLAGS) -I $(INCS_DIR) -o $@ $^

clean	:
	make clean -C $(LIB_DIR)
	$(RM) $(CLIENT_SRCS) $(SERVER_SRCS) $(UTIL_SRCS) $(BONUS_CLIENT_SRCS) $(BONUS_SERVER_SRCS)

fclean	: clean
	make fclean -C $(LIB_DIR)
	$(RM) $(CLIENT_NAME) $(SERVER_NAME) $(BONUS_CLIENT_NAME) $(BONUS_SERVER_NAME)

re : clean all

.PHONY : all clean fclean re bonus
