# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/04 10:04:11 by ancoulon          #+#    #+#              #
#    Updated: 2021/05/07 19:38:03 by ancoulon         ###   ########.fr        #
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

SH_SRCS		= \
				source/shared/inst/inst_get.c \
				source/shared/inst/inst_pa.c \
				source/shared/inst/inst_pb.c \
				source/shared/inst/inst_ra.c \
				source/shared/inst/inst_rb.c \
				source/shared/inst/inst_rr.c \
				source/shared/inst/inst_rra.c \
				source/shared/inst/inst_rrb.c \
				source/shared/inst/inst_rrr.c \
				source/shared/inst/inst_sa.c \
				source/shared/inst/inst_save.c \
				source/shared/inst/inst_sb.c \
				source/shared/inst/inst_ss.c \
				source/shared/stack/stack_free.c \
				source/shared/stack/stack_new.c \
				source/shared/stack/stack_parse.c \
				source/shared/utils/print_error.c

CH_SRCS		= \
				source/checker/inspector.c \
				source/checker/interpreter.c \
				source/checker/main.c \
				source/checker/reader.c

PS_SRCS		= \
				source/push_swap/bringb.c \
				source/push_swap/main.c \
				source/push_swap/median.c \
				source/push_swap/print_insts.c \
				source/push_swap/process.c \
				source/push_swap/sort.c \
				source/push_swap/splita.c

SH_OBJS		= $(SH_SRCS:.c=.o)

CH_OBJS		= $(CH_SRCS:.c=.o)

PS_OBJS		= $(PS_SRCS:.c=.o)

all:		$(CH_NAME) $(PS_NAME)

$(CH_NAME):	$(SH_OBJS) $(CH_OBJS)
			$(LIBMAKE) all
			$(CC) $(CFLAGS) -o $(CH_NAME) $(SH_OBJS) $(CH_OBJS) $(LIBDIR)/$(LIBNAME)

$(PS_NAME):	$(SH_OBJS) $(PS_OBJS)
			$(LIBMAKE) all
			$(CC) $(CFLAGS) -o $(PS_NAME) $(SH_OBJS) $(PS_OBJS) $(LIBDIR)/$(LIBNAME)

clean:
			$(LIBMAKE) clean
			$(RM) $(SH_OBJS) $(CH_OBJS) $(PS_OBJS)

fclean:		clean
			$(LIBMAKE) fclean
			$(RM) $(CH_NAME) $(PS_NAME)

re:			fclean all

.PHONY:	all clean fclean re
