# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jisokang <jisokang@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/22 02:58:35 by jisokang          #+#    #+#              #
#    Updated: 2021/06/22 03:00:24 by jisokang         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLIENT_NAME	=	client
SERVER_NAME	=	server

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror
AR		=	ar rcs
RM		=	rm -f

INCS_DIR	=	./include/
SRCS_DIR	=	./src/

LIB_DIR		=	./lib/
LIB_NAME	=	lib_jisokang.a
