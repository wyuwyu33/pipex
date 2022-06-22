# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wyu <wyu@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/01 20:56:45 by wyu               #+#    #+#              #
#    Updated: 2022/01/03 13:59:17 by wyu              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC= gcc
CFLAGS= -Wall -Wextra -Werror
AR= ar rcs
RM= rm -f

LIBFT_PART1= ft_isalpha ft_isdigit ft_isalnum ft_isascii ft_isprint\
				ft_strlen ft_memset ft_bzero ft_memcpy ft_memmove\
				ft_strlcpy ft_strlcat ft_toupper ft_tolower ft_strchr\
				ft_strrchr ft_strncmp ft_memchr ft_memcmp ft_strnstr\
				ft_atoi ft_calloc ft_strdup
LIBFT_PART2= ft_substr ft_strjoin ft_strtrim ft_split ft_itoa\
				ft_strmapi ft_striteri ft_putchar_fd ft_putstr_fd ft_putendl_fd\
				ft_putnbr_fd

LIBFT_BONUS= ft_lstnew ft_lstadd_front ft_lstsize ft_lstlast ft_lstadd_back\
				ft_lstdelone ft_lstclear ft_lstiter ft_lstmap
				
NAME= libft.a
LIB_SRCS= $(patsubst %, %.c, $(LIBFT_PART1)) $(patsubst %, %.c, $(LIBFT_PART2))
LIB_SRCS_BOUNUS= $(patsubst %, %.c, $(LIBFT_BONUS))
LIB_OBJS= $(LIB_SRCS:.c=.o)
LIB_OBJS_BONUS= $(LIB_SRCS_BOUNUS:.c=.o)
all: $(NAME)
		
$(NAME): $(LIB_OBJS)
			$(AR) $@ $^

.c.o:	$(LIB_SRCS)
		$(CC) $(CFLAGS) -c -o $@ $<

clean:
		$(RM) $(LIB_OBJS) $(LIB_OBJS_BONUS)

fclean: clean
		$(RM) $(NAME)

re: clean all

bonus: $(LIB_OBJS_BONUS)
		$(AR) $(NAME) $^
		
.PHONY: all clean fclean re bonus
		