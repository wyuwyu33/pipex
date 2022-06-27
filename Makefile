# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wyu <wyu@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/08 14:16:14 by wyu               #+#    #+#              #
#    Updated: 2022/06/27 20:19:32 by wyu              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC 		= gcc
CFLAGS 	= -Wall -Wextra -Werror
AR 		= ar rcs
RM 		= rm -f

NAME 		= pipex

PIPE_LIBFT	= pipex.a

LIBFT_NAME 	= libft.a
LIBFT 		= libft

REMAIN 		= descriptor exec

REMAIN_SRCS	= $(patsubst %, %.c, $(REMAIN))

REMAIN_OBJS = $(REMAIN_SRCS:.c=.o)

.PHONY : all clean fclean re

all : $(NAME)

$(NAME) : $(PIPE_LIBFT)
		$(CC) $(CFLAGS) pipex.c -o $@ $<

$(PIPE_LIBFT) : $(REMAIN_OBJS) $(LIBFT)/$(LIBFT_NAME)
		$(AR) $@ $(REMAIN_OBJS)

$(LIBFT)/$(LIBFT_NAME) :
		make all -C $(LIBFT)
		cp $(LIBFT)/$(LIBFT_NAME) $(PIPE_LIBFT)

$(REMAIN_OBJS) : $(REMAIN_SRCS)
		$(CC) $(CFLAGS) -c $^

clean :
		$(RM) $(REMAIN_OBJS) $(PIPE_LIBFT)
		make clean -C $(LIBFT)

fclean : clean
		$(RM) $(NAME)
		make fclean -C $(LIBFT)

bonus : all

re : clean all
