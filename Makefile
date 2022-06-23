# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wyu <wyu@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/08 14:16:14 by wyu               #+#    #+#              #
#    Updated: 2022/06/23 18:44:02 by wyu              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC 		= gcc
CFLAGS 	= -Wall -Wextra -Werror
AR 		= ar rcs
RM 		= rm -f

NAME 		= pipex
LIBFT 		= libft
LIBFT_NAME 	= libft.a

FILE 		=  descriptor exec pipex

SRCS		= $(patsubst %, %.c, $(FILE))
OBJS 		= $(SRCS:.c=.o)

.PHONY : all clean fclean re bonus

all : $(NAME)

$(NAME) : $(OBJS)
		$(AR) $@ $(OBJS)

$(OBJS) : $(SRCS)
		$(CC) $(CFLAGS) -c $^

clean :
		$(RM) $(OBJS)
		make clean -C $(LIBFT)

fclean : clean
		$(RM) $(NAME)

bonus : all

re : clean all
