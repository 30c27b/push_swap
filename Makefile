# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/04 10:04:11 by ancoulon          #+#    #+#              #
#    Updated: 2021/03/06 15:26:13 by ancoulon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CH_NAME		= checker
PS_NAME		= push_swap

LIBDIR		= libcarbon
LIBNAME		= libcarbon.a
LIBMAKE		= make -C $(LIBDIR)

CC			= clang -g
\RM			= rm -f
CFLAGS		= -Wall -Wextra -Werror \
				-I./include -I./$(LIBDIR)/include \

CH_SRCS		= \
				$(wildcard source/shared/*/*.c) \
				$(wildcard source/checker/*.c)

PS_SRCS		= \
				$(wildcard source/shared/*/*.c) \
				$(wildcard source/push_swap/*.c)

CH_OBJS		= $(CH_SRCS:.c=.o)

PS_OBJS		= $(PS_SRCS:.c=.o)

all:		$(CH_NAME) $(PS_NAME)

$(CH_NAME):	$(CH_OBJS)
			$(LIBMAKE) all
			$(CC) $(CFLAGS) -o $(CH_NAME) $(CH_OBJS) $(LIBDIR)/$(LIBNAME)

$(PS_NAME):	$(PS_OBJS)
			$(LIBMAKE) all
			$(CC) $(CFLAGS) -o $(PS_NAME) $(PS_OBJS) $(LIBDIR)/$(LIBNAME)

clean:
			$(LIBMAKE) clean
			$(RM) $(CH_OBJS) $(PS_OBJS)

fclean:		clean
			$(LIBMAKE) fclean
			$(RM) $(CH_NAME) $(PS_NAME)

re:			fclean all

.PHONY:	all clean fclean re
